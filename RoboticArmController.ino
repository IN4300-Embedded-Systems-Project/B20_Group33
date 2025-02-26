#include <Servo.h>
#include <SoftwareSerial.h>

// Create servo objects
Servo base;      // Base rotation
Servo shoulder;  // Shoulder joint
Servo elbow;     // Elbow joint
Servo gripper;   // Gripper

// Bluetooth module pins
#define BT_RX 2
#define BT_TX 3

// Create bluetooth serial object
SoftwareSerial btSerial(BT_RX, BT_TX);

// Servo pins
#define BASE_PIN 5
#define SHOULDER_PIN 6  
#define ELBOW_PIN 9
#define GRIPPER_PIN 10

// Current angles for each servo
int baseAngle = 90;
int shoulderAngle = 90;
int elbowAngle = 90;
int gripperAngle = 90;

// Step size for servo movement
const int STEP = 5;

void setup() {
  // Initialize serial communications
  Serial.begin(9600);
  btSerial.begin(9600);
  
  // Attach servos to pins
  base.attach(BASE_PIN);
  shoulder.attach(SHOULDER_PIN);
  elbow.attach(ELBOW_PIN);
  gripper.attach(GRIPPER_PIN);
  
  // Set initial positions
  base.write(baseAngle);
  shoulder.write(shoulderAngle);
  elbow.write(elbowAngle);
  gripper.write(gripperAngle);
  
  delay(1000);
}

void loop() {
  // Check if data is available from bluetooth
  if (btSerial.available()) {
    char cmd = btSerial.read();
    
    // Control logic for each servo
    switch(cmd) {
      case '1': // Base left
        if(baseAngle < 180) baseAngle += STEP;
        base.write(baseAngle);
        break;
        
      case '2': // Base right
        if(baseAngle > 0) baseAngle -= STEP;
        base.write(baseAngle);
        break;
        
      case '3': // Shoulder up
        if(shoulderAngle < 180) shoulderAngle += STEP;
        shoulder.write(shoulderAngle);
        break;
        
      case '4': // Shoulder down
        if(shoulderAngle > 0) shoulderAngle -= STEP;
        shoulder.write(shoulderAngle);
        break;
        
      case '5': // Elbow up
        if(elbowAngle < 180) elbowAngle += STEP;
        elbow.write(elbowAngle);
        break;
        
      case '6': // Elbow down
        if(elbowAngle > 0) elbowAngle -= STEP;
        elbow.write(elbowAngle);
        break;
        
      case '7': // Gripper open
        if(gripperAngle < 180) gripperAngle += STEP;
        gripper.write(gripperAngle);
        break;
        
      case '8': // Gripper close
        if(gripperAngle > 0) gripperAngle -= STEP;
        gripper.write(gripperAngle);
        break;
    }
    
    // Print current angles for debugging
    Serial.print("Base: "); Serial.print(baseAngle);
    Serial.print(" Shoulder: "); Serial.print(shoulderAngle);
    Serial.print(" Elbow: "); Serial.print(elbowAngle);
    Serial.print(" Gripper: "); Serial.println(gripperAngle);
  }
  
  delay(20); // Small delay to prevent servo jitter
}