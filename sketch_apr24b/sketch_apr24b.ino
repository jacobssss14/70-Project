#include "CountDown.h"

CountDown CD(CountDown::SECONDS);

volatile byte state_brush_in;
int swt;
int led_red = 4 ;
int led_green = 7;
int buzz = 8;
int ledState = LOW;
long time_in = 0;
long time_out=0;
long time_diff=0;
bool brushState = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Set Pinout Mode
  pinMode(2, INPUT_PULLUP);
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(buzz, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), brush_in, CHANGE);
}

void brush_in() {
  swt=digitalRead(2); 
  Serial.println(swt);
}


void loop() {
  swt=digitalRead(2); 
  
  //swt 0 = brush is in, swt 1 = brush is out
switch (swt) {
   case 0:
      CD.start(3);
     while (CD.remaining() > 0) {
      	digitalWrite(led_red, LOW);
      	digitalWrite(buzz, LOW);
      	digitalWrite(led_red, LOW);
      	digitalWrite(buzz, LOW);
      	digitalWrite(led_green, HIGH);
      	Serial.println("brush is in");
      	Serial.println(CD.remaining());
     }
    CD.stop();
    Serial.println("brush is in for too long");
    digitalWrite(led_green, LOW);
    digitalWrite(led_red, HIGH);
    digitalWrite(buzz, HIGH);
    delay(1000);
    digitalWrite(led_green, LOW);
    digitalWrite(buzz, LOW);
    delay(1000);
    break;
     
   case 1:
   CD.start(3);
     while (CD.remaining() > 0) {
      	digitalWrite(led_red, LOW);
      	digitalWrite(buzz, LOW);
      	digitalWrite(led_red, LOW);
      	digitalWrite(buzz, LOW);
      	digitalWrite(led_green, HIGH);
        delay(1000);
        digitalWrite(led_green, LOW);
      	Serial.println("brushing teeth");
      	Serial.println(CD.remaining());
     }
    CD.stop();
   	Serial.println("brush is out for too long");
    digitalWrite(led_green, LOW);
    digitalWrite(led_red, HIGH);
    digitalWrite(buzz, HIGH);
    delay(1000);
    digitalWrite(led_green, LOW);
    digitalWrite(buzz, LOW);
    delay(1000);
    break;
}



}
