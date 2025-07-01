#include "sensor_array.h"
#include "config.h"
#include <NewPing.h>
#include <QTRSensors.h>

NewPing sonar(US_TRIG, US_ECHO, 200);
QTRSensors qtr;
const uint8_t lineSensors[] = {LINE_LEFT, LINE_RIGHT};
uint16_t lineValues[2];

// Sensor readings storage
int irValues[4] = {0};
int lineRaw[2] = {0};
int distance = 0;

void initSensors() {
  // Initialize IR sensors
  pinMode(IR_FRONT, INPUT);
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);
  pinMode(IR_REAR, INPUT);
  
  // Initialize line sensors
  qtr.setTypeRC();
  qtr.setSensorPins(lineSensors, 2);
}

void calibrateSensors() {
  if (!DEBUG_MODE) return;
  
  Serial.println("Calibrating sensors...");
  
  // Line sensor calibration
  for (int i = 0; i < 100; i++) {
    qtr.calibrate();
    delay(10);
  }
  
  // Store calibration offsets
  for (uint8_t i = 0; i < 2; i++) {
    lineCalibration[i] = (qtr.calibrationOn.minimum[i] + 
                         qtr.calibrationOn.maximum[i]) / 2;
  }
  
  // IR calibration (ambient light)
  for (int i = 0; i < 4; i++) {
    irCalibration[i] = analogRead(IR_FRONT + i);
  }
  
  Serial.println("Calibration complete!");
}

void updateSensorReadings() {
  // Read IR sensors with calibration
  irValues[0] = analogRead(IR_FRONT) - irCalibration[0];
  irValues[1] = analogRead(IR_LEFT) - irCalibration[1];
  irValues[2] = analogRead(IR_RIGHT) - irCalibration[2];
  irValues[3] = analogRead(IR_REAR) - irCalibration[3];
  
  // Read line sensors
  qtr.read(lineValues);
  lineRaw[0] = lineValues[0];
  lineRaw[1] = lineValues[1];
  
  // Read ultrasonic sensor
  distance = sonar.ping_cm();
}

bool isOnEdge() {
  return (lineRaw[0] > EDGE_THRESHOLD) || (lineRaw[1] > EDGE_THRESHOLD);
}

bool detectOpponentFront() {
  return (distance > 0 && distance < OPPONENT_DISTANCE) || 
         (irValues[0] > 200);
}

bool detectOpponentSides() {
  return (irValues[1] > 150) || (irValues[2] > 150);
}

int getOpponentAngle() {
  // Calculate approximate opponent angle based on sensor differences
  int leftDiff = irValues[1] - irValues[2];
  int rightDiff = irValues[2] - irValues[1];
  
  if (leftDiff > 100) return -45;   // Opponent on left
  if (rightDiff > 100) return 45;   // Opponent on right
  return 0;                         // Directly ahead
}