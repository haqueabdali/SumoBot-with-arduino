# SumoBot System Architecture

## Overview
The SumoBot is an autonomous robot designed for sumo wrestling competitions. It uses sensor fusion, real-time decision making, and precise motor control to detect opponents and avoid ring boundaries.

## Hardware Architecture
```mermaid
graph TD
    A[Arduino Nano] --> B[Power Management]
    A --> C[Sensor Array]
    A --> D[Motor Driver]
    B --> E[3S LiPo Battery]
    C --> F[4x IR Proximity Sensors]
    C --> G[2x Line Sensors]
    C --> H[Ultrasonic Sensor]
    D --> I[Left DC Motor]
    D --> J[Right DC Motor]