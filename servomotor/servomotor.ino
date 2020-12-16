#include <Servo.h>

Servo motor;

int angle = 0; 

void setup(){
  motor.attach(10);
  motor.write(angle);
  delay(2000);
}

void loop(){
  motor.write(180);
//  delay(500);
//  motor.write(0);

    // now scan back from 180 to 0 degrees
    for(angle = 180; angle > 10; angle--){                                
      motor.write(angle);           
      delay(1);       
    }
    delay(3000);
//  scan from 0 to 180 degrees
    for(angle = 10; angle < 180; angle++){                                  
      motor.write(angle);               
      delay(1);                   
    }
    delay(1000);

}
