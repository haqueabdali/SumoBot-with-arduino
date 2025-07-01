#include "motor_control.h"
#include "config.h"
#include <Arduino.h>

void initMotors() {
  pinMode(MOTOR_L1, OUTPUT);
  pinMode(MOTOR_L2, OUTPUT);
  pinMode(MOTOR_R1, OUTPUT);
  pinMode(MOTOR_R2, OUTPUT);
  stopMotors();
}

void setMotorSpeed(int leftSpeed, int rightSpeed) {
  // Constrain speeds to safe range
  leftSpeed = constrain(leftSpeed, -MAX_SPEED, MAX_SPEED);
  rightSpeed = constrain(rightSpeed, -MAX_SPEED, MAX_SPEED);

  // Left motor control
  if (leftSpeed > 0) {
    analogWrite(MOTOR_L1, leftSpeed);
    analogWrite(MOTOR_L2, 0);
  } else {
    analogWrite(MOTOR_L1, 0);
    analogWrite(MOTOR_L2, -leftSpeed);
  }

  // Right motor control
  if (rightSpeed > 0) {
    analogWrite(MOTOR_R1, rightSpeed);
    analogWrite(MOTOR_R2, 0);
  } else {
    analogWrite(MOTOR_R1, 0);
    analogWrite(MOTOR_R2, -rightSpeed);
  }
}

void stopMotors() {
  analogWrite(MOTOR_L1, 0);
  analogWrite(MOTOR_L2, 0);
  analogWrite(MOTOR_R1, 0);
  analogWrite(MOTOR_R2, 0);
}

void testMotors() {
  if (!DEBUG_MODE) return;
  
  Serial.println("Testing motors...");
  setMotorSpeed(150, 150);
  delay(500);
  setMotorSpeed(-150, -150);
  delay(500);
  setMotorSpeed(200, -200);
  delay(500);
  stopMotors();
}