#include <Adafruit_GFX.h>       // include Adafruit graphics library
#include <Adafruit_ILI9341.h>   // include Adafruit ILI9341 TFT library
#include <SPI.h>
#include <SD.h> 
#define TFT_CS    8      // TFT CS  pin is connected to arduino pin 8
#define TFT_RST   9      // TFT RST pin is connected to arduino pin 9
#define TFT_DC    10     // TFT DC  pin is connected to arduino pin 10
// initialize ILI9341 TFT library
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
 
void setup() {
  Serial.begin(9600);
  Serial.println("ILI9341 Test!"); 
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);
  int x1,y1,x2,y2;
  int w = tft.width();
  int h = tft.height();
  Serial.println(w,h);
  x1=0;
  x2=w-20;
  y1=y2=160;
  tft.drawLine(x1,y1,x2,y2,tft.color565(200,200,200));
  y1=y2=240;
  tft.drawLine(x1,y1,x2,y2,tft.color565(200,200,200));
  //y1=y2=10;
  //tft.drawLine(x1,y1,x2,y2,tft.color565(200,200,200));
}

void loop(void) {
  //SPEED
  tft.setCursor(5,65);
  tft.setTextSize(3);
  tft.println("Speed");
  tft.setTextColor(ILI9341_BLUE);
  tft.setCursor(100,50);
  tft.setTextSize(7);
  tft.println(100);
  tft.setTextColor(ILI9341_BLUE);
  tft.setCursor(150,120);
  tft.setTextSize(3);
  tft.println("Kmph");
  tft.setTextColor(ILI9341_BLUE);

  //MAXSPEED
  tft.setCursor(5,190);
  tft.setTextSize(3);
  tft.println("Max kmph");
  tft.setTextColor(ILI9341_BLUE);
  tft.setCursor(160,190);
  tft.setTextSize(3);
  tft.println(100);
  tft.setTextColor(ILI9341_BLUE);

  //BRAKE TEMP
  tft.setCursor(5,280);
  tft.setTextSize(3);
  tft.println("Eng Temp");
  tft.setTextColor(ILI9341_BLUE);
  tft.setCursor(160,280);
  tft.setTextSize(3);
  tft.println(100);
  tft.setTextColor(ILI9341_BLUE);
  
  //CIRCLE
  int x=230;
  for(int a=15;a<320;a+=15){
    if(a<105)
      tft.fillCircle(x,a,5,tft.color565(255,0,0));
    else if(a<225)
      tft.fillCircle(x,a,5,tft.color565(0,255,0));
    else
      tft.fillCircle(x,a,5,tft.color565(191, 64, 191));
  }
  delay(1000);
}
