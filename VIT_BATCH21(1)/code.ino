#include <Servo.h>

Servo servoMain;  // Create a servo object
int trigpin = 4;
int echopin = 3;

void setup() {
  servoMain.attach(5);  // Attach the servo to pin 5
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
}

void loop() {
  long duration, cm;

  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);
  cm = duration / 58.82;  // Calculate distance in centimeters

  if (cm < 30) {
    servoMain.write(180);  // Open the lid (180 degrees)
    delay(3000);  // Keep the lid open for 3 seconds
  } else {
    servoMain.write(0);  // Close the lid (0 degrees)
    delay(50);  // A small delay for stability
  }
}
