volatile byte state_brush_in;
int swt;
int led_red = 4 ;
int led_green = 7;
int buzz = 8;
int ledState = LOW;
unsigned long time;

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
    digitalWrite(led_red, LOW);
    digitalWrite(buzz, LOW);
    digitalWrite(led_green, HIGH);
    break;
     
   case 1:
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
