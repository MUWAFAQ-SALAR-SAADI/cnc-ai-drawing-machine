/*
  GENERIC REFERENCE SKETCH — NOT THE ORIGINAL COMPETITION FIRMWARE
  ------------------------------------------------------------------
  This is an illustrative, generic example of open-loop step/direction
  control for a 2-stepper-motor X-Y pen plotter, added for documentation
  purposes only. It does not represent the actual firmware used in the
  CNC AI-Assisted Drawing Machine project, which was written by other
  team members and was not preserved.

  Demonstrates the general control concept only: moving two stepper
  motors along X and Y axes, and lifting/dropping a pen via servo.
*/

#include <Servo.h>

const int X_STEP_PIN = 2;
const int X_DIR_PIN  = 3;
const int Y_STEP_PIN = 4;
const int Y_DIR_PIN  = 5;
const int PEN_SERVO_PIN = 6;

const int PEN_UP_ANGLE   = 90;
const int PEN_DOWN_ANGLE = 30;
const int STEP_DELAY_US  = 800; // controls plotting speed

Servo penServo;

void setup() {
  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);

  penServo.attach(PEN_SERVO_PIN);
  penUp();
}

void loop() {
  // Example only: trace a small square, pen down, then lift and idle.
  penDown();
  moveAxis(X_STEP_PIN, X_DIR_PIN, 200, true);
  moveAxis(Y_STEP_PIN, Y_DIR_PIN, 200, true);
  moveAxis(X_STEP_PIN, X_DIR_PIN, 200, false);
  moveAxis(Y_STEP_PIN, Y_DIR_PIN, 200, false);
  penUp();

  while (true) {
    // Idle after the demo shape. Replace with real image-to-gcode
    // coordinate parsing in an actual implementation.
  }
}

void moveAxis(int stepPin, int dirPin, int steps, bool forward) {
  digitalWrite(dirPin, forward ? HIGH : LOW);
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(STEP_DELAY_US);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(STEP_DELAY_US);
  }
}

void penDown() {
  penServo.write(PEN_DOWN_ANGLE);
  delay(200);
}

void penUp() {
  penServo.write(PEN_UP_ANGLE);
  delay(200);
}
