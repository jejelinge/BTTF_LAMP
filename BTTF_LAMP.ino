
#include "Adafruit_NeoPixel.h"

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        4 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 18 // Popular NeoPixel ring size


//========================USEFUL VARIABLES=============================
int led_ring_brightness = 255; // Adjust it 0 to 255
int var=0;
int analogPin = A1;

// When setting up the NeoPixel library, we tell it how many pixels,
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {

  pinMode(4, OUTPUT);
  pinMode(analogPin, INPUT);
  Serial.begin(9600);
  
}

void loop() {

  // switch on the ring in blue
  pixels.clear(); // Set all pixel colors to 'off'
  
  if(var>3){var = 0;}

  if(analogRead(analogPin)>50)
  { 
    var = var+1 ;
    delay(45);
  }
  
Serial.print("var=");
Serial.println(var);

Serial.print("Analog=");
Serial.println(analogRead(analogPin));

delay(100);
  switch (var) {
  case 0: 
  for(int i=0; i<5;i++){
  pixels.setPixelColor(i, pixels.Color(255,0,0));
  }
  for(int i=5; i<11;i++){
  pixels.setPixelColor(i, pixels.Color(180,140,0));
  }
  for(int i=11; i<17;i++){
  pixels.setPixelColor(i, pixels.Color(255,0,0));
  }
  pixels.show();
  break;

  case 1:
    for(int i=0; i<5;i++){
  pixels.setPixelColor(i, pixels.Color(0,0,255));
  }
  for(int i=5; i<11;i++){
  pixels.setPixelColor(i, pixels.Color(200,250,255));

  }
  for(int i=11; i<17;i++){
  pixels.setPixelColor(i, pixels.Color(0,0,255));
  }
 pixels.show();
 break;

 case 2:
  pixels.clear();
  for(int i=0; i<5;i++){
  pixels.setPixelColor(i, pixels.Color(255,0,10));
  }
    for(int i=5; i<11;i++){
  pixels.setPixelColor(i, pixels.Color(0,10,255));
  }
    for(int i=11; i<17;i++){
  pixels.setPixelColor(i, pixels.Color(255,0,10));
  }
 pixels.show();
 break;

 case 3:
  pixels.clear();
  for(int i=0; i<16;i++){
  pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
 pixels.show();
 break;
  }



}

