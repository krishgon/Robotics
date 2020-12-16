int PIR = 8; // choose the input pin (for PIR sensor)
int pirState = LOW; // we start, assuming no motion detected
int motion = 0; // variable for reading the pin status
int speaker = 9; //Set up a speaker on a PWM pin (digital 9, 10, or 11)

void setup()
{
    pinMode(PIR, INPUT); // declare sensor as input
    pinMode(speaker, OUTPUT);
    Serial.begin(9600); 
}

void loop()
{
  motion = digitalRead(PIR); // read motion from sensor 
  if(motion == HIGH){// if motion is there
    digitalWrite(speaker,HIGH);
    Serial.println("Motion Detected");
  }

  else{
    digitalWrite(speaker,LOW);
    Serial.println("no motion");

  }  
}

//
//// duration in mSecs, frequency in hertz
//void playTone(long duration, int freq)
//{
//    duration *= 1000;
//    int period = (1.0 / freq) * 1000000;
//    long elapsed_time = 0;
//    while (elapsed_time < duration)
//    {
//        digitalWrite(pinSpeaker, HIGH);
//        delayMicroseconds(period / 2);
//        digitalWrite(pinSpeaker, LOW);
//        delayMicroseconds(period / 2);
//        elapsed_time += (period);
//    }
//
//}
