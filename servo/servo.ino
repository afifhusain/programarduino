#include <Servo.h>
Servo kendali; 

 void setup() {
  // put your setup code here, to run once:
  kendali.attach(3);
}

void loop() {
  // put your main code here, to run repeatedly:
  kendali.write(0);
  delay(5000);
  kendali.write(90);
  delay(1000);
}
