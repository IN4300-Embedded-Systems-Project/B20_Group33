#include <Servo.h>

Servo servo1, servo2, servo3, servo4;
int val = 0;
int pos1 = 0, pos2 = 90, pos3 = 30, pos4 = 170; // Store current positions of each servo
int pauseTime = 75  ; // Delay time between servo movements

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);

  servo1.attach(5);  
  servo2.attach(6);  
  servo3.attach(9);  
  servo4.attach(10); 

  servo1.write(0);
  servo2.write(90);
  servo3.write(30);
  servo4.write(170);
}

void loop() {
  if (Serial.available()) {
    val = Serial.read();
    Serial.println(val);
  } else {
    val = 0; // Reset val if no input
  }

  // Move servo1 (pin 5)
  while (val == '1' && pos1 < 130) {
    digitalWrite(13, HIGH);
    pos1 += 5;
    servo1.write(pos1);
    delay(pauseTime);
    if (Serial.available()) val = Serial.read();
    else val = 0;
  }
  
  while (val == '2' && pos1 > 0) {
    digitalWrite(13, HIGH);
    pos1 -= 5;
    servo1.write(pos1);
    delay(pauseTime);
    if (Serial.available()) val = Serial.read();
    else val = 0;
  }

  // Move servo2 (pin 6)
  while (val == '3' && pos2 < 180) {
    digitalWrite(13, HIGH);
    pos2 += 5;
    servo2.write(pos2);
    delay(pauseTime);
    if (Serial.available()) val = Serial.read();
    else val = 0;
  }
  while (val == '4' && pos2 > 0) {
    digitalWrite(13, HIGH);
    pos2 -= 5;
    servo2.write(pos2);
    delay(pauseTime);
    if (Serial.available()) val = Serial.read();
    else val = 0;
  }

  // Move servo3 (pin 9)
  while (val == '5' && pos3 < 180) {
    digitalWrite(13, HIGH);
    pos3 += 5;
    servo3.write(pos3);
    delay(pauseTime);
    if (Serial.available()) val = Serial.read();
    else val = 0;
  }
  while (val == '6' && pos3 > 5) {
    digitalWrite(13, HIGH);
    pos3 -= 5;
    servo3.write(pos3);
    delay(pauseTime);
    if (Serial.available()) val = Serial.read();
    else val = 0;
  }

  // Move servo4 (pin 10)
  while (val == '8' && pos4 < 180) {
    digitalWrite(13, HIGH);
    pos4 += 5;
    servo4.write(pos4);
    delay(pauseTime);
    if (Serial.available()) val = Serial.read();
    else val = 0;
  }
  while (val == '7' && pos4 > 0) {
    digitalWrite(13, HIGH);
    pos4 -= 5;
    servo4.write(pos4);
    delay(pauseTime);
    if (Serial.available()) val = Serial.read();
    else val = 0;
  }

  digitalWrite(13, LOW); // Turn off LED when no input
}
