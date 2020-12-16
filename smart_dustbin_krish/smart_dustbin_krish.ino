#include <Servo.h>

int trig = 9;
int echo = 8;
int motorPin = 10;
int angle = 0;

Servo motor;

int GETdistance(){
  long duration, distance;
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2)/29.1;
  return distance;
}

void setup(){
  Serial.begin(9600);
  motor.attach(motorPin);
  motor.write(0);
  delay(2000);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop(){

  int distance = GETdistance();
  Serial.print(distance);
  Serial.println(" CM");
  delay(10);

  if(distance <= 20){
    for(angle = 10; angle < 180; angle++){                                  
      motor.write(angle);               
      delay(1);                   
    }
    delay(3000);
    // now scan back from 180 to 0 degrees
    for(angle = 180; angle > 10; angle--){                                
      motor.write(angle);           
      delay(1);       
    }
    delay(1000);
  }
//  else{
//    digitalWrite(led, LOW);
//  }
}
