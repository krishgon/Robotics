void setup(){
  pinMode(11,OUTPUT);// buzzer positive pin
  pinMode(10,INPUT);// ldr sensor digital out pin 
  Serial.begin(9600);
}

void loop(){
  bool light = digitalRead(10);
  if(light == HIGH){ // if no light detected
    Serial.println("light off");
    digitalWrite(11, LOW);
  }
  else{ // if light detected
     Serial.println("light on");
     digitalWrite(11, HIGH);
     delay(100);
     digitalWrite(11, LOW);
     delay(100);
  }
}
