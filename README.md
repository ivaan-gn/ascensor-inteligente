# Ascensor Inteligente ACME - Actividad 2

Proyecto desarrollado para la asignatura Equipos e Instrumentación Electrónica del Máster en Ingeniería de Telecomunicación.

## Descripción

El proyecto consiste en el desarrollo de un sistema de control y actuación para un ascensor inteligente de cinco plantas utilizando Arduino UNO y la plataforma de simulación Wokwi.

El sistema implementa:

- Control de desplazamiento entre plantas mediante servomotor
- Botones de llamada para cada planta
- Medición de temperatura y humedad mediante sensor DHT22
- Medición de iluminación ambiental mediante sensor LDR
- Algoritmo de control ON-OFF con zona muerta para temperatura
- Control automático de iluminación
- Interfaz HMI mediante display LCD 16x2
- Monitorización mediante comunicación serie

## Componentes utilizados

- Arduino UNO
- Servomotor SG90
- Sensor DHT22
- Sensor LDR
- Display LCD 16x2
- Pulsadores
- LEDs de actuación

## Funcionalidades

### Control del ascensor
El usuario puede seleccionar cualquiera de las cinco plantas mediante pulsadores. El servomotor simula el desplazamiento de la cabina entre plantas.

### Control de temperatura
Se implementa un algoritmo ON-OFF con zona muerta:
- Temperatura < 23 ºC → calefacción activada
- Temperatura > 27 ºC → refrigeración activada
- Entre 23 ºC y 27 ºC → sistema estable

### Control de iluminación
El sistema activa automáticamente iluminación auxiliar mediante LEDs cuando disminuye la iluminación ambiental detectada por el sensor LDR.

## Simulación Wokwi

https://wokwi.com/projects/463750126437303297

## Autor

@ivaan-gn
