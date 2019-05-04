#include <NewPing.h>
#include <AFMotor.h>
#include <SharpIR.h>

/******FOR SONAR*****/
// FRONT //
#define TRIGGER_FR  39
#define ECHO_FR    38
#define TRIGGER_FL  41
#define ECHO_FL    40
// RIGHT //
#define TRIGGER_RF  50
#define ECHO_RF    51
// LEFT //
#define TRIGGER_LF  44
#define ECHO_LF   45
// BACK //
#define TRIGGER_B  52
#define ECHO_B    53

#define MAX_DISTANCE 20  // In Centimeters (200cm = 78.7") It will not keep waiting for a return if past this value

NewPing sonarFR(TRIGGER_FR, ECHO_FR, MAX_DISTANCE);
NewPing sonarFL(TRIGGER_FL, ECHO_FL, MAX_DISTANCE);

NewPing sonarRF(TRIGGER_RF, ECHO_RF, MAX_DISTANCE);

NewPing sonarLF(TRIGGER_LF, ECHO_LF, MAX_DISTANCE);

NewPing sonarB(TRIGGER_B, ECHO_B, MAX_DISTANCE);


/******SHARP IR SETUP*****/
#define SHARP_FR   A14
#define SHARP_FL   A13
#define SHARP_B    A15

SharpIR SharpFR(GP2Y0A21YK0F, SHARP_FR); // In Centimeters MX 80
SharpIR SharpFL(GP2Y0A21YK0F, SHARP_FL); // In Centimeters MX 80
SharpIR SharpB(GP2YA41SK0F, SHARP_B);   // In Centimeters MX 30


/******LINE IR SETUP*****/
#define LINE_FR    36
#define LINE_FM    37
#define LINE_FL    34
#define LINE_BR    49
#define LINE_BL    48


//MOTOR SETUP
AF_DCMotor motor1(1);
AF_DCMotor motor2(3);

void setup() {
  pinMode(LINE_FR,INPUT);
  pinMode(LINE_FM,INPUT);
  pinMode(LINE_FL,INPUT);
  pinMode(LINE_BR,INPUT);
  pinMode(LINE_BL,INPUT);
  
  Serial.begin(9600);
}


//MOTOR FOUNCTION
void forward(int n){
  motor1.setSpeed(n);
  motor2.setSpeed(n);
  
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void backward(int n){
  motor1.setSpeed(n);
  motor2.setSpeed(n);
  
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

void fright(int n){
  motor1.setSpeed(n);
  motor2.setSpeed(n);
  
  motor1.run(RELEASE);
  motor2.run(FORWARD);
}

void fleft(int n){
  motor1.setSpeed(n);
  motor2.setSpeed(n);
  
  motor1.run(FORWARD);
  motor2.run(RELEASE);
}

void bright(int n){
  motor1.setSpeed(n);
  motor2.setSpeed(n);
  
  motor1.run(RELEASE);
  motor2.run(BACKWARD);
}
void bleft(int n){
  motor1.setSpeed(n);
  motor2.setSpeed(n);
  
  motor1.run(BACKWARD);
  motor2.run(RELEASE);
}
void turnright(){
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
}

void turnleft(){
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
}

void release(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  }

void loop() {

  float uFR = sonarFR.ping_cm();
  Serial.print(uFR);
  Serial.print(" -> FR cm ");
    
  float uFL = sonarFL.ping_cm();
  Serial.print(uFL); 
  Serial.print(" -> FL cm ");

  float uRF = sonarRF.ping_cm();
  Serial.print(uRF);
  Serial.print(" -> RF cm ");
 
  float uLF = sonarLF.ping_cm();
  Serial.print(uLF);
  Serial.print(" -> LF cm ");

  float uB = sonarB.ping_cm();
  Serial.print(uB);
  Serial.println(" -> B cm ");
  
  

  //GET LINE IR VALUE
  int lFR = digitalRead(LINE_FR);
  Serial.print(lFR);
  Serial.println(" -> lFR cm ");
  int lFM = digitalRead(LINE_FM);
  Serial.print(lFM);
  Serial.println(" -> lFM cm ");
  int lFL = digitalRead(LINE_FL);
  Serial.print(lFL);
  Serial.println(" -> lFL cm ");
  int lBR = digitalRead(LINE_BR);
  Serial.print(lBR);
  Serial.println(" -> lBR cm ");
  int lBL = digitalRead(LINE_BL);
  Serial.print(lBL);
  Serial.println(" -> lBL cm ");

  //GET SHARP IR VALUE
  int sFL = SharpFL.getDistance();
  Serial.print(sFL);
  Serial.print(">>sFL   ");  
  int sFR = SharpFR.getDistance();
  Serial.print(sFR);
  Serial.print(">>sFR    ");  
  int sB = SharpB.getDistance();
  Serial.print(sB);
  Serial.println(">>sB  ");  

//LINE FOLOW TEST
if((lFR==0 & lFM==0) || (lFM==0 & lFL==0))
  {
    forward(150);
    Serial.println("forward(200) "); 
    }
else if(lFR!=0 || lFM!=0 || lFL!=0){
    backward(255);
    Serial.println("backward(200) "); 
    delay(500);
    turnleft();
    Serial.println("turnleft(200) "); 
    delay(500);
  }
 else 
  release();

  delay(1000);
                                                                                                                                                                                                                                                       
}
