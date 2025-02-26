#include <Servo.h>

Servo servo1, servo2, servo3, servo4;
int val = 0;
int speed1 = 90, speed2 = 90, speed3 = 90, speed4 = 90; 
int pauseTime = 75; 
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);

  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(9);
  servo4.attach(10);

  
  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
}

void loop() {
  if (Serial.available()) {
    val = Serial.read();
    Serial.println(val);
  } else {
    val = 0; 
  }

  while (val == '1') {
    digitalWrite(13, HIGH);
    servo1.write(180); 
    delay(pauseTime);
    if (Serial.available()) val = Serial.read();
    else val = 0;
  }
  while (val == '2') {
    digitalWrite(13, HIGH);
    servo1.write(0);
    delay(pauseTime);
    if (Serial.available()) val = Serial.read();
    else val = 0;
  }


  while (val == '3') {
    digitalWrite(13, HIGH);
    servo2.write(180); 
    delay(pauseTime);
    if (Serial.available()) val = Serial.read();
    else val = 0;
  }
  while (val == '4') {
    digitalWrite(13, HIGH);
    servo2.write(0); 
    delay(pauseTime);
    if (Serial.available()) val = Serial.read();
    else val = 0;
  }

  while (val == '5') {
    digitalWrite(13, HIGH);
    servo3.write(180); 
    delay(pauseTime);
    if (Serial.available()) val = Serial.read();
    else val = 0;
  }
  while (val == '6') {
    digitalWrite(13, HIGH);
    servo3.write(0); 
    delay(pauseTime);
    if (Serial.available()) val = Serial.read();
    else val = 0;
  }

  while (val == '7') {
    digitalWrite(13, HIGH);
    servo4.write(180); 
    if (Serial.available()) val = Serial.read();
    else val = 0;
  }
  while (val == '8') {
    digitalWrite(13, HIGH);
    servo4.write(0); 
    delay(pauseTime);
    if (Serial.available()) val = Serial.read();
    else val = 0;
  }


  if (val == '0') {
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
    servo4.write(90);
    digitalWrite(13, LOW); 
  }
}
