#include "pitches.h"

int trig = 5;
int echo = 4;
int buzzer = 13;
long duration, distance;


void setup(){
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2)/29.1;
  Serial.print(distance);
  Serial.println(" CM");
  delay(300);

  if(distance <= 30){
    digitalWrite(buzzer, LOW);
  }
  else{
    digitalWrite(buzzer, HIGH);
//    tone(buzzer, 10000);
    delay(500);
//    noTone(buzzer);
//    delay(500);
  }
}
