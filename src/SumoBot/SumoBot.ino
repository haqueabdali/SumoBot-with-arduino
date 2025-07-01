
#include "config.h"
#include "motor_control.h"
#include "sensor_array.h"

// Strategy states
enum StrategyState {SEARCH, ATTACK, DEFEND, EDGE_RECOVERY};

StrategyState currentStrategy = SEARCH;
unsigned long lastOpponentTime = 0;

void setup() {
  Serial.begin(115200);
  initSensors();
  initMotors();
  calibrateSensors();
  
  Serial.println("SumoBot initialized. Ready for competition!");
}

void loop() {
  updateSensorReadings();
  determineStrategy();
  executeStrategy();
  
  // Competition safety delay
  delay(20);
}

void determineStrategy() {
  // Edge recovery has highest priority
  if (isOnEdge()) {
    currentStrategy = EDGE_RECOVERY;
    return;
  }
  
  // Opponent detection logic
  if (detectOpponentFront()) {
    currentStrategy = ATTACK;
    lastOpponentTime = millis();
  } 
  else if (detectOpponentSides()) {
    currentStrategy = DEFEND;
    lastOpponentTime = millis();
  }
  // Time-based strategy decay
  else if (millis() - lastOpponentTime > 5000) {
    currentStrategy = SEARCH;
  }
}

void executeStrategy() {
  switch(currentStrategy) {
    case SEARCH:
      executeSearchPattern();
      break;
    case ATTACK:
      executeAttack();
      break;
    case DEFEND:
      executeDefense();
      break;
    case EDGE_RECOVERY:
      executeEdgeRecovery();
      break;
  }
}

void executeAttack() {
  int opponentAngle = getOpponentAngle();
  
  // Direct frontal attack
  if (abs(opponentAngle) < 30) {
    setMotorSpeed(MAX_SPEED, MAX_SPEED);
  } 
  // Adjust for off-center opponent
  else if (opponentAngle > 0) {
    setMotorSpeed(MAX_SPEED * 0.7, MAX_SPEED);
  } else {
    setMotorSpeed(MAX_SPEED, MAX_SPEED * 0.7);
  }
}

void executeDefense() {
  // Circular defensive pattern
  setMotorSpeed(MAX_SPEED * 0.8, MAX_SPEED * 0.5);
}

void executeSearchPattern() {
  // Expanding spiral search pattern
  static int searchStep = 0;
  
  switch(searchStep % 4) {
    case 0: setMotorSpeed(MAX_SPEED * 0.6, MAX_SPEED * 0.3); break;
    case 1: setMotorSpeed(MAX_SPEED * 0.3, MAX_SPEED * 0.6); break;
    case 2: setMotorSpeed(MAX_SPEED * 0.6, MAX_SPEED * 0.3); break;
    case 3: setMotorSpeed(MAX_SPEED * 0.3, MAX_SPEED * 0.6); break;
  }
  
  if(millis() % 2000 < 20) searchStep++;
}

void executeEdgeRecovery() {
  // Back away from edge and realign
  setMotorSpeed(-MAX_SPEED * 0.7, -MAX_SPEED * 0.7);
  delay(300);
  setMotorSpeed(MAX_SPEED * 0.5, -MAX_SPEED * 0.5);
  delay(400);
  stopMotors();
}