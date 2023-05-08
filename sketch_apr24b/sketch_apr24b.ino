#include "CountDown.h"

CountDown CD(CountDown::SECONDS);

bool state_brush_in = false;
int swt;
int led_red = 4 ;
int led_green = 12;
int buzz = 13;
int brushState = LOW;
long time_in = 0;
long time_out=0;
long time_diff=0;
int time;


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
  state_brush_in = !state_brush_in;
  // if (CD.isRunning() == true) {
   //  CD.stop();
 //  }
  Serial.println(swt);
  delay(1250);
}

void timer_1() {

 // CD.start(8);
    time=0;
     while (time < 8) {
      	digitalWrite(led_red, LOW);
      	digitalWrite(buzz, LOW);
      	digitalWrite(led_red, LOW);
      	digitalWrite(buzz, LOW);
      	digitalWrite(led_green, LOW);
      	Serial.println("brush is in");
        Serial.println(time);
        time += 1;
        delay(1000);
     }
 //   CD.stop();
}

void timer_2() {

  CD.start(3);
     while (CD.remaining() > 0) {
      	digitalWrite(led_red, LOW);
      	digitalWrite(buzz, LOW);
      	digitalWrite(led_red, LOW);
      	digitalWrite(buzz, LOW);
      	digitalWrite(led_green, LOW);
      	Serial.println("brush is out");
        Serial.println(CD.remaining());
     }
    CD.stop();
} 


void loop() {
  swt=digitalRead(2); 
  switch (swt) {

   case 0:
    state_brush_in = true;
    timer_1();
    while (state_brush_in == true) {
    Serial.println("brush is in for too long");
    digitalWrite(led_green, LOW);
    digitalWrite(led_red, HIGH);
    digitalWrite(buzz, HIGH);
    delay(1000);
    digitalWrite(led_green, LOW);
    digitalWrite(buzz, LOW);
    delay(1000);
    }
    break;
     
   case 1:
    state_brush_in = false;
    timer_2();
    digitalWrite(led_green, HIGH);
    while (state_brush_in == false) {
    delay(3000);
    digitalWrite(led_green, LOW);
    Serial.println("brush is out for too long");
    //digitalWrite(led_green, HIGH);
    digitalWrite(led_red, HIGH);
    digitalWrite(buzz, HIGH);
    delay(1000);
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(buzz, LOW);
    delay(1000);
    }
    break;
}


}


  //swt 0 = brush is in, swt 1 = brush is out



