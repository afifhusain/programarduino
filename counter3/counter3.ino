#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display


// this constant won't change:
const int  Up_buttonPin   = 2;    // the pin that the pushbutton is attached to
const int  Down_buttonPin = 3;

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int up_buttonState = 0;         // current state of the up button
int up_lastButtonState = 0;     // previous state of the up button

int down_buttonState = 0;         // current state of the up button
int down_lastButtonState = 0;     // previous state of the up button
bool bPress = false;

int adc1 = A5;  
int adc2 = A4;
int adc3 = A3;

int out =13;
//int out2 =12;
//int out3 =11;


int nilaiadc1 = 0;        // value read from the pot
int nilaiadc2 = 0;
int nilaiadc3 = 0;

void setup()
{
  Serial.begin(9600);
  pinMode( Up_buttonPin , INPUT_PULLUP);
  pinMode( Down_buttonPin , INPUT_PULLUP);
  pinMode(out, OUTPUT);
 
  lcd.begin();                      // initialize the lcd
 
  // Print a message to the LCD.
  lcd.setCursor(1,0);
   lcd.print("Counter Test");
   lcd.setCursor(0,1);
   lcd.print("Afif Husain");
   delay(5000); 
   lcd.clear();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Please Select:");
  lcd.setCursor(2,1);
  lcd.print(buttonPushCounter);
 
}

void loop()
{
   checkUp();
   checkDown();
   nilaiadc1 = analogRead(adc1);
   nilaiadc2 = analogRead(adc2);
   nilaiadc3 = analogRead(adc3);  

   if( bPress){
       bPress = false;
      lcd.setCursor(2,1);
      lcd.print("               ");
      lcd.setCursor(2,1);
      lcd.print(buttonPushCounter);
   }
 
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
  else if(nilaiadc1<=20)
  {
    buttonPushCounter++;
    lcd.setCursor(2,1);
    lcd.print(buttonPushCounter);
  }
  else if(nilaiadc3<=20)
  {
    buttonPushCounter++;
  }
  
  delay(1);
}
//  if(nilaiadc1<=10)
//  {
//  buttonPushCounter++;
//  }
//  else if(nilaiadc2<=10)
//  {
//  buttonPushCounter++;
//  }
//  else if(nilaiadc2<=10)
//  {
//  buttonPushCounter++;
//  }

void checkUp()
{
  up_buttonState = digitalRead(Up_buttonPin);

  // compare the buttonState to its previous state
  if (up_buttonState != up_lastButtonState) {
    // if the state has changed, increment the counter
    if (up_buttonState == LOW) {
        bPress = true;
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else if(nilaiadc1<=10) {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
      buttonPushCounter++;
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  up_lastButtonState = up_buttonState;
   if(nilaiadc1<=500)
  {
    digitalWrite(out,1);
  }
  else if(nilaiadc2<=20)
  {
    buttonPushCounter++;
  }
  else if(nilaiadc3<=20)
  {
    buttonPushCounter++;
  }
}
void checkDown()
{
  down_buttonState = digitalRead(Down_buttonPin);

  // compare the buttonState to its previous state
  if (down_buttonState != down_lastButtonState) {
    // if the state has changed, increment the counter
    if (down_buttonState == LOW) {
        bPress = true;
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter--;
     
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  down_lastButtonState = down_buttonState;
}

