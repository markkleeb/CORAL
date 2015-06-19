#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(20, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

int np;
void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  np = strip.numPixels();
}

float s1 = 0;
float s2 = 0;
float s3 = 0;
float sinSpeed = 1;

void loop() {
  
  sinSpeed = analogRead(0)/4 -127; //0-1023
  sinSpeed /= 10;
  
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    int r = abs(round(60 * sin(s1*i/np)));
    int g = abs(round(255 * sin(.1+s2*i/np)));
    int b = abs(round(201 * sin(.2+s3*i/np)));
    strip.setPixelColor(i,r,g,b);
  }
  
  s1+= .02 * sinSpeed;
  s2+= .03 * sinSpeed;
  s3+= .04 * sinSpeed;
  
  delay(0);
  strip.show();

}



