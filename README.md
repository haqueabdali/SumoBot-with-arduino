# SumoBot with Arduino 🤖🥋

[![Arduino CI](https://github.com/haqueabdali/SumoBot-with-arduino/actions/workflows/arduino-ci.yml/badge.svg)](https://github.com/haqueabdali/SumoBot-with-arduino/actions/workflows/arduino-ci.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Documentation Status](https://img.shields.io/badge/docs-passing-brightgreen)](https://github.com/haqueabdali/SumoBot-with-arduino/tree/main/docs)

<img src="docs/images/sumobot_demo.gif" alt="SumoBot in Action" width="600">

An autonomous sumo wrestling robot built with Arduino that detects opponents and ring boundaries using sensor fusion. Designed for robotic sumo competitions with strategic algorithms for offensive and defensive maneuvers.

## Table of Contents
- [Features](#features)
- [Hardware Specifications](#hardware-specifications)
- [Getting Started](#getting-started)
- [System Architecture](#system-architecture)
- [Installation](#installation)
- [Calibration](#calibration)
- [Competition Strategies](#competition-strategies)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Features ✨
- **Multi-sensor Fusion**: IR proximity sensors + ultrasonic distance detection
- **Edge Detection**: Line sensors for ring boundary awareness
- **Tactical Algorithms**: 
  - Aggressive attack mode
  - Defensive circling strategy
  - Corner escape routines
- **Real-time Motor Control**: PID-controlled precise movements
- **Modular Design**: Easily replaceable sensor arrays
- **Energy Efficient**: Low-power sleep modes between matches

## Hardware Specifications 🛠️
| Component              | Specification                          |
|------------------------|----------------------------------------|
| Microcontroller        | Arduino Nano (ATmega328P)              |
| Motor Driver           | L298N Dual H-Bridge                    |
| Motors                 | 2x 12V DC Gear Motors (300 RPM)        |
| Sensors                | 4x IR Proximity (10-80cm range), 2x QTR-8A Reflectance |
| Power                  | 3S LiPo Battery (11.1V, 2200mAh)       |
| Chassis                | 3D-printed PETG (10x10cm competition spec) |
| Weight                 | < 500g (Class 1 SumoBot)               |

## Getting Started 🚀
1. **Hardware Assembly**: Follow the [Assembly Guide](docs/ASSEMBLY_GUIDE.md)
2. **Software Setup**:
   ```bash
   git clone https://github.com/haqueabdali/SumoBot-with-arduino.git
   cd SumoBot-with-arduino/src/SumoBot
   # Open SumoBot.ino in Arduino IDE
