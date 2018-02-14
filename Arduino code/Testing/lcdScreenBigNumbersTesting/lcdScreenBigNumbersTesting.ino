#include <LiquidCrystal.h>
LiquidCrystal lcd(11, 12, A0, A1, A2, A3);

// If the LCD is externally powered, set this to False.
// If the Arduino and LCD are connected to the circuit board, the LCD needs power from
// the NPN transistor by pulling pin 7 low. To do this, set the variable below to true
bool LCDNeedsPower = true;

byte xPosLCD = 0;
byte yPosLCD = 0;

void lcdClear() {
  xPosLCD = 0;
  yPosLCD = 0;
  lcd.clear();
}

void lcdSetCursor(byte x, byte y) {
  xPosLCD = x;
  yPosLCD = y;
  lcd.setCursor(x, y);
}

void lcdDigit(byte digit) {
  digit = constrain(digit, 0, 9);
  switch (digit) {
    case 0:
      lcd.setCursor(xPosLCD, 0);
      lcd.print("###");
      lcd.setCursor(xPosLCD, 1);
      lcd.print("# #");
      lcd.setCursor(xPosLCD, 2);
      lcd.print("# #");
      lcd.setCursor(xPosLCD, 3);
      lcd.print("###");
      break;
    case 1:
      lcd.setCursor(xPosLCD, 0);
      lcd.print("  #");
      lcd.setCursor(xPosLCD, 1);
      lcd.print("  #");
      lcd.setCursor(xPosLCD, 2);
      lcd.print("  #");
      lcd.setCursor(xPosLCD, 3);
      lcd.print("  #");
      break;
    case 2:
      lcd.setCursor(xPosLCD, 0);
      lcd.print("###");
      lcd.setCursor(xPosLCD, 1);
      lcd.print(" _#");
      lcd.setCursor(xPosLCD, 2);
      lcd.print("#");
      lcd.setCursor(xPosLCD, 3);
      lcd.print("###");
      break;
    case 3:
      lcd.setCursor(xPosLCD, 0);
      lcd.print("###");
      lcd.setCursor(xPosLCD, 1);
      lcd.print("__#");
      lcd.setCursor(xPosLCD, 2);
      lcd.print("  #");
      lcd.setCursor(xPosLCD, 3);
      lcd.print("###");
      break;
    case 4:
      lcd.setCursor(xPosLCD, 0);
      lcd.print("# #");
      lcd.setCursor(xPosLCD, 1);
      lcd.print("#_#");
      lcd.setCursor(xPosLCD, 2);
      lcd.print("  #");
      lcd.setCursor(xPosLCD, 3);
      lcd.print("  #");
      break;
    case 5:
      lcd.setCursor(xPosLCD, 0);
      lcd.print("###");
      lcd.setCursor(xPosLCD, 1);
      lcd.print("#_");
      lcd.setCursor(xPosLCD, 2);
      lcd.print("  #");
      lcd.setCursor(xPosLCD, 3);
      lcd.print("###");
      break;
    case 6:
      lcd.setCursor(xPosLCD, 0);
      lcd.print("###");
      lcd.setCursor(xPosLCD, 1);
      lcd.print("#_");
      lcd.setCursor(xPosLCD, 2);
      lcd.print("# #");
      lcd.setCursor(xPosLCD, 3);
      lcd.print("###");
      break;
    case 7:
      lcd.setCursor(xPosLCD, 0);
      lcd.print("###");
      lcd.setCursor(xPosLCD, 1);
      lcd.print("  #");
      lcd.setCursor(xPosLCD, 2);
      lcd.print(" #");
      lcd.setCursor(xPosLCD, 3);
      lcd.print(" #");
      break;
    case 8:
      lcd.setCursor(xPosLCD, 0);
      lcd.print("###");
      lcd.setCursor(xPosLCD, 1);
      lcd.print("#_#");
      lcd.setCursor(xPosLCD, 2);
      lcd.print("# #");
      lcd.setCursor(xPosLCD, 3);
      lcd.print("###");
      break;
    case 9:
      lcd.setCursor(xPosLCD, 0);
      lcd.print("###");
      lcd.setCursor(xPosLCD, 1);
      lcd.print("#_#");
      lcd.setCursor(xPosLCD, 2);
      lcd.print("  #");
      lcd.setCursor(xPosLCD, 3);
      lcd.print("###");
      break;
  }
  lcdSetCursor(xPosLCD + 5, 0);
}

void lcdNumber(word num) {
  num = constrain(num, 0, 9999);
  lcdClear();
  lcdDigit((num / 1000) % 10);
  lcdDigit((num / 100) % 10);
  lcdDigit((num / 10) % 10);
  lcdDigit(num % 10);
}

void setup() {
  if (LCDNeedsPower) {
    pinMode(7, OUTPUT);
    digitalWrite(7, LOW);
    delay(500);
  }


  lcd.begin(20, 4);

  lcd.clear();
  /*lcd.print(" _ ");
    lcd.setCursor(0, 1);
    lcd.print("|_|");
    lcd.setCursor(0, 2);
    lcd.print("|_|");

    lcd.setCursor(5, 0);
    lcd.print("###");
    lcd.setCursor(5, 1);
    lcd.print("#_#");
    lcd.setCursor(5, 2);
    lcd.print("# #");
    lcd.setCursor(5, 3);
    lcd.print("###");

    lcd.setCursor(10, 0);
    lcd.write(255); lcd.write(255); lcd.write(255);
    lcd.setCursor(10, 1);
    lcd.write(255); lcd.print("_"); lcd.write(255);
    lcd.setCursor(10, 2);
    lcd.write(255); lcd.print(" "); lcd.write(255);
    lcd.setCursor(10, 3);
    lcd.write(255); lcd.write(255); lcd.write(255);
  */
  lcdClear();
  lcdDigit(0);
  delay(500);
  lcdDigit(1);
  delay(500);
  lcdDigit(2);
  delay(500);
  lcdDigit(3);
  delay(1000);
  lcdClear();

  lcdNumber(1234);
  delay(1000);
  lcdClear();
  lcdNumber(0);
  delay(1000);
  lcdClear();
  lcdNumber(1);
  delay(1000);
  lcdClear();
  lcdNumber(-1);
  delay(1000);
  lcdClear();
  lcdNumber(2017);
  delay(1000);

  for (word i = 0; i <= 9999; i++) {
    lcdClear();
    lcdNumber(i);
    delay(500);
  }
}

void loop() {

}

