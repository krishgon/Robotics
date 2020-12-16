int badLED = 13; // choose the pin for the all-good LED
int goodLED = 3; // choose the pin for gas-leaked LED
int motionPIN = 2; // choose the input pin (for PIR sensor)
int gasPIN = A0;
int gasThresh = 250;
int pirState = LOW; // we start, assuming no motion detected
bool gasLeak = false; // variable for gas leak. we are assuming that no gas has leaked at the starting
int pinSpeaker = 10; // Set up a speaker on a PWM pin (digital 9, 10, or 11)

void setup()
{
    pinMode(badLED, OUTPUT); // declare badLED as output
    pinMode(goodLED, OUTPUT); // declare goodLED as output
    pinMode(motionPIN, INPUT); // declare motion sensor as input
    pinMode(gasPIN, INPUT); // declare gas sensor as input
    pinMode(pinSpeaker, OUTPUT); // declare buzzer as output
    Serial.begin(9600); // junior stark
}

void loop()
{
    val = digitalRead(inputPin); // read input value
    if (val == HIGH)
    { // check if the input is HIGH
        digitalWrite(ledPin, HIGH); // turn LED ON
        playTone(300, 160);
        delay(150);

        if (pirState == LOW)
        {
            // we have just turned on
            Serial.println("Motion detected!");
            // We only want to print on the output change, not state
            pirState = HIGH;
        }
    }
    else
    {
        digitalWrite(ledPin, LOW); // turn LED OFF
        playTone(0, 0);
        delay(300);
        if (pirState == HIGH)
        {
            // we have just turned off
            Serial.println("Motion ended!");
            // We only want to print on the output change, not state
            pirState = LOW;
        }
    }
}


// duration in mSecs, frequency in hertz
void playTone(long duration, int freq)
{
    duration *= 1000;
    int period = (1.0 / freq) * 1000000;
    long elapsed_time = 0;
    while (elapsed_time < duration)
    {
        digitalWrite(pinSpeaker, HIGH);
        delayMicroseconds(period / 2);
        digitalWrite(pinSpeaker, LOW);
        delayMicroseconds(period / 2);
        elapsed_time += (period);
    }

} 
