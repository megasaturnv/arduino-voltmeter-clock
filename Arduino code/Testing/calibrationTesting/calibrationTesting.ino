#include <LiquidCrystal.h>
LiquidCrystal lcd(11, 12, A0, A1, A2, A3);

#define SECONDS_MIN_PWM 9
#define SECONDS_MAX_PWM 255
#define SECONDS_PWM_PIN 5

#define MINUTES_MIN_PWM 21
#define MINUTES_MAX_PWM 250
#define MINUTES_PWM_PIN 6

#define HOURS_MIN_PWM 3
#define HOURS_MAX_PWM 183
#define HOURS_PWM_PIN 3

#define DAY_MIN_PWM 10
#define DAY_MAX_PWM 232
#define DAY_PWM_PIN 9

#define MONTH_MIN_PWM 0
#define MONTH_MAX_PWM 255
#define MONTH_PWM_PIN 10

#define LCD_AND_LIGHTS_POWER_PIN 7
#define LED_PIN 13
#define POTENTIOMETER_PIN A6

void blinkLED() {
  digitalWrite(LED_PIN, HIGH);
  delay(50);
  digitalWrite(LED_PIN, LOW);
}

void turnOnLCD() {
  digitalWrite(LCD_AND_LIGHTS_POWER_PIN, HIGH);
  delay(100);
  lcd.begin(20, 4);
  lcd.clear();
}

void turnOffLCD() {
  lcd.clear();
  delay(100);
  digitalWrite(LCD_AND_LIGHTS_POWER_PIN, LOW);
}

void analogWriteMapped(byte pin, byte minPWM, byte maxPWM, String message) {
  byte mappedPwmVal = map(analogRead(POTENTIOMETER_PIN), 0, 1023, minPWM, maxPWM);
  Serial.println(message + "mapped PWM value:    " + mappedPwmVal);
  analogWrite(pin, (mappedPwmVal));
}

void setup() {
  blinkLED();
  Serial.begin(115200); //For debugging
  pinMode(SECONDS_PWM_PIN,          OUTPUT);
  pinMode(MINUTES_PWM_PIN,          OUTPUT);
  pinMode(HOURS_PWM_PIN,            OUTPUT);
  pinMode(DAY_PWM_PIN,              OUTPUT);
  pinMode(MONTH_PWM_PIN,            OUTPUT);
  pinMode(LED_PIN,                  OUTPUT);
  pinMode(LCD_AND_LIGHTS_POWER_PIN, OUTPUT);
  pinMode(POTENTIOMETER_PIN,        INPUT);
  turnOnLCD();
  Serial.println("Ready!");
  blinkLED();
}

void loop() {
  int potentiometerAnalogValue = analogRead(POTENTIOMETER_PIN);
  
  lcd.clear();
  lcd.print("Analog in:  ");
  lcd.print(potentiometerAnalogValue);
  lcd.setCursor(0, 1);
  lcd.print("1023 > 255: ");
  lcd.print(map(potentiometerAnalogValue, 0, 1023, 0, 255));
  
  lcd.setCursor(0, 2);
  lcd.print(map(potentiometerAnalogValue, 0, 1023, HOURS_MIN_PWM,   HOURS_MAX_PWM));
  lcd.setCursor(7, 2);
  lcd.print(map(potentiometerAnalogValue, 0, 1023, MINUTES_MIN_PWM, MINUTES_MAX_PWM));
  lcd.setCursor(14, 2);
  lcd.print(map(potentiometerAnalogValue, 0, 1023, SECONDS_MIN_PWM, SECONDS_MAX_PWM));
  lcd.setCursor(7, 3);
  lcd.print(map(potentiometerAnalogValue, 0, 1023, MONTH_MIN_PWM,   MONTH_MAX_PWM));
  lcd.setCursor(14, 3);
  lcd.print(map(potentiometerAnalogValue, 0, 1023, DAY_MIN_PWM,     DAY_MAX_PWM));
  
  Serial.println("\n\n\n\n\n\nPotentiometer value: " + String(potentiometerAnalogValue));
  
  analogWriteMapped(SECONDS_PWM_PIN, SECONDS_MIN_PWM, SECONDS_MAX_PWM, "Secs  ");
  analogWriteMapped(MINUTES_PWM_PIN, MINUTES_MIN_PWM, MINUTES_MAX_PWM, "Mins  ");
  analogWriteMapped(HOURS_PWM_PIN,   HOURS_MIN_PWM,   HOURS_MAX_PWM,   "Hrs   ");
  analogWriteMapped(DAY_PWM_PIN,     DAY_MIN_PWM,     DAY_MAX_PWM,     "Day   ");
  analogWriteMapped(MONTH_PWM_PIN,   MONTH_MIN_PWM,   MONTH_MAX_PWM,   "Mnth  ");
  delay(250);
}
