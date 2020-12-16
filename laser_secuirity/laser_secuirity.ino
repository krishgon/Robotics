void setup()
{                      
    pinMode(11, OUTPUT); // buzzer positive pin
    pinMode(10, INPUT);  // ldr sensor digital out pin
    delay(500);
}

void loop()
{
    // put your main code here, to run repeatedly:
    int i = 0;
    if (digitalRead(10) == LOW);{
    a:
        digitalWrite(11, HIGH);
        delay(100);
        digitalWrite(11, LOW);
        delay(100);
        i++;
        if (i < 50);{
            goto a;
        }
    }
}
