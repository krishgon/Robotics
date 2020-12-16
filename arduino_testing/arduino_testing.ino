int goodLED = 3; // choose the pin for gas-leaked LED
int badLED = 2; // choose the pin for the all-good LED
int motionPIN = 4; // choose the input pin (for PIR sensor)
int motion = LOW;
int buzzer = 5; // Set up a speaker on a PWM pin (digital 9, 10, or 11)
int gasPIN = A0;
int gasThresh = 350;


void setup() {
  pinMode(goodLED, OUTPUT); // declare goodLED as output
  pinMode(badLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(gasPIN, INPUT);
  pinMode(motionPIN, INPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(goodLED, HIGH);
  digitalWrite(badLED, HIGH);
  // digitalWrite(buzzer, HIGH);
  
  int temp = analogRead(gasPIN);
  int temp2 = digitalRead(motionPIN);
  
  Serial.println(temp2);
  
}
