#include <Wire.h>
#include<LiquidCrystal.h>

const int rs = 13, en = 12, d4 = 10, d5 = 9, d6 = 7, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  Serial.begin(9600);
  pinMode(0, INPUT);
  pinMode(A0, INPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  lcd.begin(16, 2);
}

void loop()
{
  //Serial.println(digitalRead(2));
  //Serial.println(digitalRead(3));
  //Serial.println(analogRead(A0));
  if (digitalRead(0) == 0){
    digitalWrite(4, HIGH);
    digitalWrite(2, HIGH);
    lcd.setCursor(5, 0);
    lcd.print("Danger!");
    lcd.setCursor(2, 1);
    lcd.print("Fire Detected");
    delay(250); // Wait for 100 millisecond(s)
    digitalWrite(4, LOW);
    digitalWrite(2, LOW);
    clearLCDLine(1);
    //lcd.clear();
    delay(250); // Wait for 100 millisecond(s)
  }else if(analogRead(A0) > 550 ) {
    digitalWrite(4, HIGH);
    digitalWrite(2, HIGH);
    lcd.setCursor(5, 0);
    lcd.print("Danger!");
    lcd.setCursor(2, 1);
    lcd.print("Gas Detected");
    delay(250); // Wait for 100 millisecond(s)
    digitalWrite(4, LOW);
    digitalWrite(2, LOW);
    clearLCDLine(1);
    //lcd.clear();
    delay(250); // Wait for 100 millisecond(s)
  }
  else {
    lcd.clear();
    digitalWrite(4, LOW);
    digitalWrite(2, LOW);
    delay(125); // Wait for 100 millisecond(s)
  }
}

void clearLCDLine(int line){               
  lcd.setCursor(0,line);
  for(int n = 0; n < 20; n++){
    lcd.print(" ");
  }
}
