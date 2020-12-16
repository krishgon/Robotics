#define LED 13
#define BUTTON 2
void setup(){
  pinMode(LED,OUTPUT); 
  pinMode(BUTTON,INPUT);  
}

void loop(){
  if(digitalRead(BUTTON)==HIGH){ // if user presses the button
    if(digitalRead(LED)== LOW){ // if the led is off
        digitalWrite(LED, HIGH); // turn the led on
    }
    else{ // if the led is on
        digitalWrite(LED, LOW); // turn the led off
    }
  }
  
}
