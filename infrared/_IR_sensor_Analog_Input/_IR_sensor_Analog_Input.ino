//sketch arduino kalibrasi sensor adc dan pembacaan sensor infrared denga  ADC
//                  afif husain
int adc1 = A5;  
int adc2 = A4;
int adc3 = A3;

int out =13;
//int out2 =12;
//int out3 =11;


int nilaiadc1 = 0;        // value read from the pot
int nilaiadc2 = 0;
int nilaiadc3 = 0;


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(out, OUTPUT);
//  pinMode(out2, OUTPUT);
//  pinMode(out3, OUTPUT);
}

void loop() {
  // read the analog in value:
  nilaiadc1 = analogRead(adc1);
  nilaiadc2 = analogRead(adc2);
  nilaiadc3 = analogRead(adc3);  


  Serial.print("sensor 1 = " );
  Serial.print(nilaiadc1);
  Serial.print("  sensor 2 = " );
  Serial.print(nilaiadc2);
  Serial.print(" sensor 3 = ");
  Serial.println(nilaiadc3); 

  
  if(nilaiadc1<=500)
  {
    digitalWrite(out,1);
  }
  else
  {
    digitalWrite(out,0);
  }
  delay(1);



//int sensorValue2 = analogRead(A0);
//
//
//  Serial.print("sensor 2 = " );
//  Serial.println(sensorValue2);
//
//  delay(200 );
//  
//  if(sensorValue<=500)
//  {
//    digitalWrite(out2,1);
//  }
//  else
//  {
//    digitalWrite(out2,0);
//  }
//  int sensorValue2 = analogRead(A0);
//
//
//  Serial.print("sensor 2 = " );
//  Serial.println(sensorValue2);
//
//  delay(200 );
//  
//  if(sensorValue<=500)
//  {
//    digitalWrite(out2,1);
//  }
//  else
//  {
//    digitalWrite(out2,0);
//  }
//  
}

