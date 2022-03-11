# Kitchen Scale

En este repositorio podras encontrar todo lo necesario para poder crear tu 
propia balanza de cocina con pantalla tft programada con el framework de arduino.

Dicho proyecto esta basado en el microcontrolador Atmega328p de un Arduino Nano, el cual controla el ADC 24bit HX711 que es ampliamente utilizado para las celdas de cargas convencionales.Ademas consta de Alimentacion propia con una bateria de Li-Ion 3000mah controlada por un tp4056(modulo cargador), el cual esta conectado a una fuente DC-DC para proporcionar unos 9V al pin de Vin del Arduino Nano.

Para la visualizacion se opto por una pantalla 128x32 SSD1306 y para el control de dos pulsadores con su respectiva resistencia pull-up o pull-down como se prefiriera.

![Scale3](https://github.com/SantiSheridan/Kitchen-Scale/blob/main/Img/Scale3.jpeg)
![Scale2](https://github.com/SantiSheridan/Kitchen-Scale/blob/main/Img/Scale2.jpeg)
![Scale1](https://github.com/SantiSheridan/Kitchen-Scale/blob/main/Img/Scale1.jpeg)


Proximamente se agregaran los archivos de calibracion automatica.
