#include <LiquidCrystal.h>  
int Contrast=100;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
}

void lcdMessage(String input, String input2){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(input);
  if(input2){
   delay(1000);
   lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print(input2);
  }
}


void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  
  Serial.println(sensorValue);
  delay(1000);
  if(sensorValue < 600){
    lcdMessage("Thanks assface", "gtfo now");
  }else{
    lcdMessage("Feed me you scum", "I am hungry");
  }
}   
 
