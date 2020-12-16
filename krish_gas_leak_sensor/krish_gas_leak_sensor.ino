int badLED = 2; // choose the pin for the all-good LED
int goodLED = 3; // choose the pin for gas-leaked LED
int motionPIN = 4; // choose the input pin (for PIR sensor)
int gasPIN = A0;
int gasThresh = 500;
int motion = 0;
int dgas = 0;
int buzzer = 5; // Set up a speaker on a PWM pin (digital 9, 10, or 11)

void setup()
{
    pinMode(badLED, OUTPUT); // declare badLED as output
    pinMode(goodLED, OUTPUT); // declare goodLED as output
    pinMode(motionPIN, INPUT); // declare motion sensor as input
    pinMode(gasPIN, INPUT); // declare gas sensor as input
    pinMode(buzzer, OUTPUT); // declare buzzer as output
    Serial.begin(9600); // junior stark
}

void loop()
{
    dgas = analogRead(gasPIN); // read gas
    motion = digitalRead(motionPIN); // read motion
    
    Serial.println(dgas); // print the gas value for debugging
    
    if (motion != 1){ // check if no-one is bothering
      if (dgas >= gasThresh){ // check if gas is leaking
        
          digitalWrite(badLED, HIGH); // turn LED ON
          digitalWrite(buzzer, HIGH); // turn ON the buzzer
      }
    }

    else{
      digitalWrite(badLED, LOW); // turn bad LED OFF
      digitalWrite(buzzer, LOW); // turn OFF the buzzer
      digitalWrite(goodLED, HIGH); // turn the good LED ON
    }
}
