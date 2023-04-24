//Declaire Variables
#include <millisDelay.h>
millisDelay ledDel;
bool state_brush_in;
int swt;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Set Pinout Mode
  pinMode(2, OUTPUT);
  pinMode(4, INPUT);
  pinMode(7, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  swt = digitalRead(4);
  Serial.println(swt);
  delay(500);

  if swt = 0 {
      state_brush_in = true; 
  } else {
      state_brush_in = false;
  }; 



}
