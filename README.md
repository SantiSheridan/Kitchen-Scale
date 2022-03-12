# Kitchen Scale

En este repositorio podras encontrar todo lo necesario para poder crear tu 
propia balanza de cocina con pantalla tft programada con el framework de arduino.

Dicho proyecto esta basado en el microcontrolador Atmega328p de un Arduino Nano, el cual controla el ADC 24bit HX711 que es ampliamente utilizado para las celdas de cargas convencionales.Ademas consta de Alimentacion propia con una bateria de Li-Ion 3000mah controlada por un tp4056(modulo cargador), el cual esta conectado a una fuente DC-DC para proporcionar unos 9V al pin de Vin del Arduino Nano.

Para la visualizacion se opto por una pantalla 128x32 SSD1306 y para el control de dos pulsadores con su respectiva resistencia pull-up o pull-down como se prefiriera.

![Scale3](https://github.com/SantiSheridan/Kitchen-Scale/blob/main/Img/Scale3.jpeg)

## Programacion
Al Microcontrolador lo programe con PlatformIO + VSCode pero tambien se puede programar desde el ArduinoIDE cambiando la extension de los archivos .cpp a .ino y eliminando la linea ```#include<arduino.h>``` necesaria en PlatformIO.
En platformio utilice la configuracion .ini:
```
[env:nanoatmega328]
platform = atmelavr
board = nanoatmega328
framework = arduino
lib_deps = 
	bogde/HX711@^0.7.5
	adafruit/Adafruit GFX Library@^1.10.13
	adafruit/Adafruit SSD1306@^2.5.1
	adafruit/Adafruit BusIO@^1.11.0
```

Proximamente se agregaran los archivos de calibracion automatica.
