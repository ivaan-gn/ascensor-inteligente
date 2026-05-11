#include <Servo.h>
#include <LiquidCrystal.h>
#include <DHT.h>

Servo ascensor;

// -------- LCD --------
LiquidCrystal lcd(7, 8, 9, 10, 12, 13);

// -------- DHT22 --------
#define DHTPIN A1
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// -------- LDR --------
int ldrPin = A0;

// -------- CONTROL TEMPERATURA --------
#define CALENTAR A2
#define ENFRIAR A3

// -------- CONTROL ILUMINACION --------
#define LED1 A4
#define LED2 A5

// -------- BOTONES --------
const int P1 = 2;
const int P2 = 3;
const int P3 = 4;
const int P4 = 5;
const int P5 = 6;

int plantaActual = 1;

void setup() {

  Serial.begin(9600);

  // Servo
  ascensor.attach(11);

  // Botones
  pinMode(P1, INPUT_PULLUP);
  pinMode(P2, INPUT_PULLUP);
  pinMode(P3, INPUT_PULLUP);
  pinMode(P4, INPUT_PULLUP);
  pinMode(P5, INPUT_PULLUP);

  // Control temperatura
  pinMode(CALENTAR, OUTPUT);
  pinMode(ENFRIAR, OUTPUT);

  // Control iluminacion
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  // LCD
  lcd.begin(16, 2);

  // DHT22
  dht.begin();

  lcd.print("Ascensor ACME");
  delay(2000);
  lcd.clear();
}

void loop() {

  // -------- BOTONES ASCENSOR --------

  if (digitalRead(P1) == LOW) {
    ascensor.write(0);
    plantaActual = 1;
  }

  if (digitalRead(P2) == LOW) {
    ascensor.write(45);
    plantaActual = 2;
  }

  if (digitalRead(P3) == LOW) {
    ascensor.write(90);
    plantaActual = 3;
  }

  if (digitalRead(P4) == LOW) {
    ascensor.write(135);
    plantaActual = 4;
  }

  if (digitalRead(P5) == LOW) {
    ascensor.write(180);
    plantaActual = 5;
  }

  // -------- LEER SENSORES --------

  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();

  int luz = analogRead(ldrPin);

  // -------- CONTROL TEMPERATURA --------

  if (temperatura < 23) {

    digitalWrite(CALENTAR, HIGH);
    digitalWrite(ENFRIAR, LOW);

  }

  else if (temperatura > 27) {

    digitalWrite(CALENTAR, LOW);
    digitalWrite(ENFRIAR, HIGH);

  }

  else {

    digitalWrite(CALENTAR, LOW);
    digitalWrite(ENFRIAR, LOW);

  }

  // -------- CONTROL ILUMINACION --------

  if (luz > 700) {

    // Muy oscuro
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);

  }

  else if (luz > 300) {

    // Luz media
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);

  }

  else {

    // Mucha luz
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);

  }

  // -------- LCD --------

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("P:");
  lcd.print(plantaActual);

  lcd.print(" T:");
  lcd.print(temperatura);

  lcd.setCursor(0, 1);
  lcd.print("H:");
  lcd.print(humedad);

  lcd.print("% L:");
  lcd.print(luz);

  // -------- SERIAL --------

  Serial.print("Planta: ");
  Serial.print(plantaActual);

  Serial.print(" Temp: ");
  Serial.print(temperatura);

  Serial.print(" Humedad: ");
  Serial.print(humedad);

  Serial.print(" Luz: ");
  Serial.println(luz);

  delay(500);
}