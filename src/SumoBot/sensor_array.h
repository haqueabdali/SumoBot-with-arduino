#pragma once

void initSensors();
void calibrateSensors();
void updateSensorReadings();
bool isOnEdge();
bool detectOpponentFront();
bool detectOpponentSides();
int getOpponentAngle();
