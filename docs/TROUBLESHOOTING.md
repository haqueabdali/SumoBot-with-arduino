# SumoBot Troubleshooting Guide

## Common Issues and Solutions

### 1. Robot Doesn't Move
| Check | Solution |
|-------|----------|
| Power LED on Arduino? | Check battery connection and switch |
| Motors vibrate but don't turn? | Increase PWM value in `config.h` |
| Serial monitor shows motor commands? | Verify motor driver connections |
| Wheels stuck? | Check for mechanical obstructions |

### 2. Sensor Malfunctions
**IR Sensors not detecting:**
- Clean sensor lenses
- Verify wiring: Red=5V, Black=GND, Yellow=Signal
- Test with multimeter: Output should vary 0.1-4.5V

**Line Sensors always triggered:**
- Recalibrate in actual competition lighting
- Adjust sensor height (optimal: 3-5mm from surface)
- Check for reflected light interference

**Ultrasonic gives inconsistent readings:**
- Ensure no objects in 50cm range during startup
- Add 10μF capacitor across VCC/GND
- Replace with new sensor if error persists

### 3. Unintended Behaviors
**Robot drives off ring:**
- Recalibrate line sensors
- Increase EDGE_THRESHOLD in `config.h`
- Check sensor alignment (must face downward)

**Spins in circles:**
- Verify motor wiring consistency
- Check for equal tire pressure
- Recalibrate IR sensors (side detection imbalance)

**Ignores opponents:**
- Clean IR sensor lenses
- Decrease OPPONENT_DISTANCE in `config.h`
- Verify ultrasonic sensor orientation

### 4. Power Issues
**Sudden shutdown during attack:**
- Battery voltage drop: Replace/upgrade battery
- Add capacitors across motor driver power inputs
- Reduce MAX_SPEED in `config.h`

**Arduino resets randomly:**
- Add 100μF capacitor across Arduino VIN/GND
- Separate power lines for motors and logic
- Check for loose connections

### 5. Advanced Debugging
**Serial Debug Codes:**
| Code | Meaning |
|------|---------|
| E01  | Left motor fault |
| E02  | Right motor fault |
| E11  | Front IR sensor error |
| E12  | Left line sensor error |
| E21  | Ultrasonic timeout |

**Debugging Procedure:**
1. Enable DEBUG_MODE in `config.h`
2. Open Serial Monitor (115200 baud)
3. Check real-time sensor readings
4. Use test sketches in `/tests` directory

### 6. Competition Checklist
- [ ] Battery fully charged (≥12.4V)
- [ ] Firmware uploaded within last 24 hours
- [ ] Edge recovery tested from all ring positions
- [ ] No loose wires or screws
- [ ] Weight < 500g (including battery)
- [ ] Dimensions within 10x10cm specification