## Calibration 

```markdown
# SumoBot Calibration Procedures

## 1. Line Sensor Calibration
```arduino
void calibrateLineSensors() {
  Serial.println("Line Sensor Calibration");
  Serial.println("Place robot over boundary line");
  delay(3000);
  
  // White surface calibration
  Serial.println("Measuring white surface...");
  int whiteLeft = qtr.readLineWhite(lineValues[0]);
  int whiteRight = qtr.readLineWhite(lineValues[1]);
  
  // Black surface calibration
  Serial.println("Measuring black surface...");
  int blackLeft = qtr.readLineBlack(lineValues[0]);
  int blackRight = qtr.readLineBlack(lineValues[1]);
  
  // Calculate thresholds
  edgeThresholdLeft = (whiteLeft + blackLeft) / 2;
  edgeThresholdRight = (whiteRight + blackRight) / 2;
  
  Serial.print("Left Threshold: "); Serial.println(edgeThresholdLeft);
  Serial.print("Right Threshold: "); Serial.println(edgeThresholdRight);
}