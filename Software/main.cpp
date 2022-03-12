#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>
#include <HX711.h>

#define TARE_PIN 3  //Pin de interrupcion para tarar
#define UNIT_PIN 2  //Pin de interrupcion para cambio de unidad
#define WIDTH 128   //Ancho del display
#define HEIGHT 32   //Alto del display
#define OLED_RESET 4  //Pin de Reset(no usado), pero necesario para el objeto HX711

#define LOADCELL_DOUT_PIN 5 //Pin de Datos del ADC HX711
#define LOADCELL_SCK_PIN 6  //Pin de Reloj del ADC HX711

#define SCALE 402   //Valor de calibracion
#define PAUSE 3000  //Tiempo de Pause antes de iniciar a medir

float weight = 0;
float weight_display = 0;
bool weight_unit = true;

Adafruit_SSD1306 oled(WIDTH, HEIGHT, &Wire, OLED_RESET);
HX711 scale;


void tare_interrup(){ //Funcion para Tarar Balanza
    scale.tare();
}

void unit_interrupt(){ //Funcion para cambiar de unidad
    if (weight_unit = true){
        weight_unit = false;
    }
    else{
        weight_unit = true;
    }
}

void setup() {
    Wire.begin(); //Inicializamos conexion I2C para display
    oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); //Ininicializamos display con direccion 0x3C

    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN); //Inicializamos Hx711
    scale.set_scale(SCALE);
    scale.tare();

    attachInterrupt(TARE_PIN, tare_interrup, RISING); //Configuracion de interrupcion de Tara
    attachInterrupt(UNIT_PIN, unit_interrupt, RISING);//Configuracion de interrupcion de Cambio de Unidad

    oled.clearDisplay();
    oled.setFont(&FreeSans9pt7b);
    oled.setTextColor(WHITE);
    oled.setCursor(9, 22);
    oled.print("Flia. ");
    oled.print("Sheridan");
    oled.drawLine(0,0,127,0,1);
    oled.drawLine(0,0,0,31,1);
    oled.drawLine(0,31,127,31,1);
    oled.drawLine(127,0,127,31,1);
    oled.display();

    delay(PAUSE);
}

void loop() {
    oled.clearDisplay();
    weight = scale.get_units(); //Obtenemos Peso

    if (weight_unit){   //Presentamos peso en Gramos
        oled.setCursor(8, 22);
        weight_display = round(weight);
        oled.print(weight_display);
        oled.print('Gramos');
    }
    else{               //Presentamos peso en Onzas
        oled.setCursor(8, 22);
        weight_display = weight*0.035274;
        oled.print(weight_display,2);
        oled.print('Onzas');
    }

    oled.drawLine(0,0,127,0,1);
    oled.drawLine(0,0,0,31,1);
    oled.drawLine(0,31,127,31,1);
    oled.drawLine(127,0,127,31,1);

    oled.display();
}
