#include <LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
String received_data;

void setup() {
 // put your setup code here, to run once:
lcd.begin(16,2);
Serial.begin(9600);
}
void loop() {
 // put your main code here, to run repeatedly:
lcd.setCursor(0,0);
lcd.print("on");
lcd.setCursor(0,1);
if(Serial.available())
 {
 lcd.print("data:");
 received_data = Serial.readString();
 lcd.print(received_data);
 delay(1000);
 lcd.clear();
 }
}