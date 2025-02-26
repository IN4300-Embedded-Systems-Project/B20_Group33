#include <Servo.h>

Servo Servo;
void setup() {
  Servo.attach(5);

}

void loop() {
  Servo.write(45);
  delay(1000);
//  Servo.write(90);
//  delay(1000);
//  Servo.write(180);
//  delay(1000);
}
