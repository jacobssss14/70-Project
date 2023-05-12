
bool state_brush_in;
int swt;
int led_red = 4 ;
int led_green = 7;
int buzz = 8;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Set Pinout Mode
  pinMode(2, INPUT_PULLUP);
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(buzz, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), brush_in, CHANGE);
  
  swt=digitalRead(2);
  if (swt == 0) {
    Serial.println("Brush Detected");
    delay(1000);
  } else {
    while (swt == 1) {
      Serial.println("Please insert brush to use device");
      delay(1000);
    }
  }
   
}

void brush_in() {
  swt=digitalRead(2); 
  delay(1000);
}

void loop() {
  swt=digitalRead(2);   
  switch (swt) {

   case 0:
    for (int time=0; time <= 16; time++) {
      	digitalWrite(led_red, LOW);
      	digitalWrite(buzz, LOW);
      	digitalWrite(led_red, LOW);
      	digitalWrite(buzz, LOW);
      	digitalWrite(led_green, LOW);
        swt = digitalRead(2);
          if (swt == 1) {
            break;
          }
        delay(500);
      	Serial.println("brush is in");
        Serial.println(time);
     }
 
    while (swt == 0) {
      swt=digitalRead(2);       
      Serial.println("brush is in for too long");
      digitalWrite(led_green, LOW);
      digitalWrite(led_red, HIGH);
      digitalWrite(buzz, HIGH);
      delay(1000);
      digitalWrite(led_green, LOW);
      digitalWrite(buzz, LOW);
      delay(1000);
        if (swt == 1) {
          break;
        }
    }
 
     
   case 1:
    for (int time2=0; time2 <= 8; time2++) {
      	digitalWrite(led_red, LOW);
      	digitalWrite(buzz, LOW);
      	digitalWrite(led_red, LOW);
      	digitalWrite(buzz, LOW);
      	digitalWrite(led_green, LOW);
        swt = digitalRead(2); 
          if (swt == 0) {
            break;
          }
        delay(500);
      	Serial.println("brush is out");
        Serial.println(time2);
     }
    digitalWrite(led_green, HIGH);
    delay(3000);
    while (swt == 1) {
      swt=digitalRead(2);       
      Serial.println("brush is out for too long");
      digitalWrite(led_green, LOW);
      digitalWrite(led_red, HIGH);
      digitalWrite(buzz, HIGH);
      delay(1000);
      digitalWrite(led_green, LOW);
      digitalWrite(buzz, LOW);
      delay(1000);
        if (swt == 0) {
          break;
        }
    }
 
    break;
  
}

}


  //swt 0 = brush is in, swt 1 = brush is out



