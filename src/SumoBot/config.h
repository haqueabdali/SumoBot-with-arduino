
#pragma once

// Hardware pin mapping
#define MOTOR_L1 5
#define MOTOR_L2 6
#define MOTOR_R1 9
#define MOTOR_R2 10

#define IR_FRONT A0
#define IR_LEFT A1
#define IR_RIGHT A2
#define IR_REAR A3

#define LINE_LEFT 2
#define LINE_RIGHT 3

#define US_TRIG 7
#define US_ECHO 8

// Competition parameters
constexpr int MAX_SPEED = 255;  // PWM max
constexpr int EDGE_THRESHOLD = 500;  // Line sensor threshold
constexpr int OPPONENT_DISTANCE = 30;  // CM

// Sensor calibration offsets
int irCalibration[4] = {0, 0, 0, 0};
int lineCalibration[2] = {0, 0};

// Debug settings
constexpr bool DEBUG_MODE = true;