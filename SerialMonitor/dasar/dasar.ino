void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   while(Serial.available()){
    char data = Serial.read();
    //kirim data ke serial
    Serial.print("Karakter :");
    Serial.print(data);
    Serial.print("ASCII : ");
    Serial.print(data, DEC);
    Serial.print("Oktal : ");
    Serial.print(data, OCT);
    Serial.print("Heksa :");
    Serial.print(data, HEX);
    Serial.print("Biner : ");
    Serial.print(data, BIN);
    delay(50);
    }

}
