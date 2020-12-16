//junior sratk
// gas sensor
int redLed = 12; //led red
int greenLed = 11; //led green
int buzzer = 10; //buzzer
int smokeA0 = A0; //mq2 sensor
int sensorThres = 300; //change the threshold value asper your need

void setup() { 
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);

  if (analogSensor > sensorThres) //checks if it has reached threshold value
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
  delay(100);
}                                 // junior stark
