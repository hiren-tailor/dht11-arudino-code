#include <SimpleDHT.h>
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int pinDHT11 = 8;
SimpleDHT11 dht11;

void setup() {
  
  lcd.begin(16, 2);   
}

void loop() {

  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;

  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) 
  {
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Error");
    return;
  }

  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print((int)temperature);
  lcd.print((char)223);
  lcd.print("C");
  
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");  
  lcd.print((int)humidity);
  lcd.print("%");
  delay(750);

}
