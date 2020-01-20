#include <Wire.h>
#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

//sketch arduino kalibrasi sensor adc dan pembacaan sensor infrared denga  ADC
//                  afif husain
int adc1 = A0;  
int adc2 = A1;
int adc3 = A2;

int out =13;
int counter = 0;
//int out2 =12;
//int out3 =11;


int nilaiadc1 = 0;        // value read from the pot
int nilaiadc2 = 0;
int nilaiadc3 = 0;


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(out, OUTPUT);
  lcd.begin(); 
//  pinMode(out2, OUTPUT);
//  pinMode(out3, OUTPUT);
}

void loop() {
  // read the analog in value:
  nilaiadc1 = analogRead(adc1);
  nilaiadc2 = analogRead(adc2);
  nilaiadc3 = analogRead(adc3);  

  lcd.setCursor(1,0);
  lcd.print("HITUNG :");
  
  Serial.print("sensor 1 = " );
  Serial.print(nilaiadc1);
  Serial.print("  sensor 2 = " );
  Serial.print(nilaiadc2);
  Serial.print(" sensor 3 = ");
  Serial.println(nilaiadc3); 

  
  if(nilaiadc1<=10)
  {
    digitalWrite(out,1);
    delay(0.00000000001);
    counter++;
  }
  else if(nilaiadc2<=50)
  {
    digitalWrite(out,0);
    delay(0.00000000001);
    counter++; 
  }
  else if(nilaiadc3<=15)
  {
    delay(0.0000000000001);
    counter++;
  }
  delay(0.000000001);
  lcd.setCursor(2,1);
  lcd.print(counter);


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

