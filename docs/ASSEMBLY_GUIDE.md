## Assembly Guide:

```markdown
# SumoBot Assembly Guide

## Required Tools
- Phillips screwdriver
- Wire strippers
- Soldering iron
- 3D printer (for chassis)
- Multimeter

## Step 1: Chassis Assembly
1. Print chassis components:
   - Main body (1x)
   - Motor mounts (2x)
   - Sensor bracket (1x)
   - Battery holder (1x)
2. Attach motors to mounts using M3 screws
3. Secure wheel assemblies to motor shafts
4. Mount Arduino Nano centrally using vibration-damping standoffs

## Step 2: Electronics Installation
```mermaid
graph TD
    A[Arduino] -->|PWM| B[Motor Driver]
    A -->|Analog| C[IR Sensors]
    A -->|Digital| D[Line Sensors]
    A -->|Trig/Echo| E[Ultrasonic]
    F[Battery] -->|11.1V| B
    B -->|5V| A