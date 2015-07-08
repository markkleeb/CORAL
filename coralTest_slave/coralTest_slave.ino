
//SLAVE
//LED connected to pin11
//pin 13 LED lights up if error

#include <SoftwareSerial.h>
#include "RS485_protocol.h"
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN 6

int np;
float s1 = 0;
float s2 = 0;
float s3 = 0;
float reading = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(14, PIN, NEO_GRB + NEO_KHZ800);

SoftwareSerial rs485 (2, 3);  // receive pin, transmit pin
const byte ENABLE_PIN = 4;

void fWrite (const byte what)
  {
  rs485.write (what);  
  }
  
int fAvailable ()
  {
  return rs485.available ();  
  }

int fRead ()
  {
  return rs485.read ();  
  }
  
void setup()
{
  rs485.begin (28800);
  //Serial.begin(9600);
  pinMode (ENABLE_PIN, OUTPUT);  // driver output enable
  
   np = strip.numPixels();
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop()
{
  byte buf [10];
  
  byte received = recvMsg (fAvailable, fRead, buf, sizeof (buf), 10);
  //Serial.println(buf[2]);
  
  if (received)
    {
    if (buf [0] != 1)
      return;  // not my device
      
    if (buf [1] != 2)
      return;  // unknown command
    
    byte msg [] = {
       0,  // device 0 (master)
       3,  // turn light on command received
    };
    
    reading = buf[2];
    
   delay (1);  // give the master a moment to prepare to receive
   digitalWrite (ENABLE_PIN, HIGH);  // enable sending
   sendMsg (fWrite, msg, sizeof msg);
   digitalWrite (ENABLE_PIN, LOW);  // disable sending
 
 //   delay(10);
   // analogWrite (11, buf [2]);  // set light level
   }  // end if something received
   
   
   breath(reading);

   
   
}  // end of loop

void breath(float sinSpeed){
  
  // sinSpeed = analogRead(0)/4 -127; //0-1023
  sinSpeed /= 10;
  
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    int r = abs(round(sinSpeed*5 * sin(s1*i/np)));
    int g = abs(round(sinSpeed*10 * sin(.1+s2*i/np)));
    int b = abs(round(201 * sin(.2+s3*i/np)));
    strip.setPixelColor(i,r,g,b);
  }
  
  s1+= .02 * sinSpeed;
  s2+= .03 * sinSpeed;
  s3+= .04 * sinSpeed;
  
  delay(0);
  strip.show();


}



