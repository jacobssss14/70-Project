#include "Timer.h"
volatile byte state_brush_in;
int swt;
int led_red = 4 ;
int led_green = 7;
int buzz = 8;
int ledState = LOW;
unsigned long time_in;
unsigned long time_out;
unsigned long time_diff;

Timer timer(MILLIS);

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
  // put your main code here, to run repeatedly:
  //swt 0 = brush is in, swt 1 = brush is out

  switch (swt) {
   case 0:
    timer.start();
    time_in=timer.read();
      if (time_in < 8000) {
        //code repeats to line 39
      } else if (time_in >= 8000) {
        time_in = 8000;
        digitalWrite(led_green, LOW);
        digitalWrite(led_red, HIGH);
        digitalWrite(buzz, HIGH);
        delay(1000);
        digitalWrite(led_green, LOW);
        digitalWrite(buzz, LOW);
        delay(1000);
        timer.stop();
        //repeat line 40
        // case 0 repeats until interrupt on pin 2 (brush_out)
      }
    
    break;
    //brush_out condition
   case 1:
    digitalWrite(led_red, LOW);
    digitalWrite(buzz, LOW);
    digitalWrite(led_green, HIGH);
    timer.start();
    time_out=timer.read();
    if (time_out<3000) {
      //execute code to blink red led and sound buzzer
    } else if (time_out >= 3000){
      //execute code to blink green led and sound buzzer
      time_out=3000;
      timer.stop();
      //jump to line 64
      //alarm continues to sound until interrupt on pin 2
    }
    break;
  }



}
