#include <Adafruit_GFX.h>    // Core graphics library by Adafruit
#include <Arduino_ST7789_Fast.h> // Hardware-specific library for ST7789 (with or without CS pin)
#include <SPI.h>
#include <HX711.h>

#define TFT_DC    8
#define TFT_RST   9 
#define SCR_WD   240
#define SCR_HT   240
#define TFT_MOSI  11   // for hardware SPI data pin (all of available pins)
#define TFT_SCLK  13   // for hardware SPI sclk pin (all of available pins)

HX711 balanza;
uint8_t dataPin = 6;
uint8_t clockPin = 7;
float P;

Arduino_ST7789 lcd = Arduino_ST7789(TFT_DC, TFT_RST);

void Tarar(){
  balanza.tare();
}

void setup(void){
  Serial.begin(115200);

  balanza.begin(dataPin, clockPin);
  balanza.set_scale(420.52);
  balanza.set_scale(420.0983);
  balanza.tare();
  attachInterrupt(digitalPinToInterrupt(2), Tarar, HIGH);
  
  lcd.init(SCR_WD, SCR_HT);
  lcd.fillScreen(BLACK);
  lcd.setCursor(30,100);
  lcd.setTextColor(WHITE,BLUE);
  lcd.setTextSize(3);
  lcd.println("Sheridan");
  delay(2000);
  lcd.fillScreen(BLACK);  
}
void loop(void){
  P = balanza.get_units(10);
  lcd.setCursor(0,100);
  lcd.setTextColor(WHITE);
  lcd.setTextSize(2);
  lcd.print("Peso: ");
  lcd.print(P);
  lcd.print(" kg");
  lcd.fillScreen(BLACK);
}
