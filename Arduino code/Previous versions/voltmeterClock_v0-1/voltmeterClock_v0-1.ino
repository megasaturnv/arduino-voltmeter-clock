#include <Time.h>
#include <TimeLib.h>
#include <DS3232RTC.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(11, 12, A0, A1, A2, A3);

//Voltmeter Clock Version 0.1

//pwm pins at 490Hz are 3, 9, 10, and 11
//pwm pins at 980Hz are 5, 6
#define SECONDS_MAX_PWM 255
#define SECONDS_PWM_PIN 5
#define MINUTES_MAX_PWM 255
#define MINUTES_PWM_PIN 6
#define HOURS_MAX_PWM 195
#define HOURS_PWM_PIN 3
#define DAY_MAX_PWM 235
#define DAY_PWM_PIN 9
#define MONTH_MAX_PWM 255
#define MONTH_PWM_PIN 10

#define BUTTON1_PIN 2
#define LCD_AND_LIGHTS_POWER_PIN 7
#define PIRPIN 8
#define POTENTIOMETER_PIN A6

byte xPosLCD = 0;
byte yPosLCD = 0;

bool needToUpdateTimeValues = true; //not yet used

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void blinkLED() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(50);
  digitalWrite(LED_BUILTIN, LOW);
}

bool digitalReadDebounce(int pin) {
  if (digitalRead(pin) == LOW) {
    delay(50);
    bool debounceRunning = true;
    while (debounceRunning) {
      if (digitalRead(pin) == HIGH) {
        debounceRunning = false;
      }
    }
    delay(50);
    return true;
  }
  return false;
}

void voltmeterAllSet(byte pwmValue) {
  analogWrite(SECONDS_PWM_PIN, pwmValue);
  analogWrite(MINUTES_PWM_PIN, pwmValue);
  analogWrite(HOURS_PWM_PIN, pwmValue);
  analogWrite(DAY_PWM_PIN, pwmValue);
  analogWrite(MONTH_PWM_PIN, pwmValue);
}

void voltmeterAllOn() {
  analogWrite(SECONDS_PWM_PIN, SECONDS_MAX_PWM);
  analogWrite(MINUTES_PWM_PIN, MINUTES_MAX_PWM);
  analogWrite(HOURS_PWM_PIN, HOURS_MAX_PWM);
  analogWrite(DAY_PWM_PIN, DAY_MAX_PWM);
  analogWrite(MONTH_PWM_PIN, MONTH_MAX_PWM);
}

void voltmeterAllOff() {
  analogWrite(SECONDS_PWM_PIN, 0);
  //digitalWrite(SECONDS_PWM_PIN,LOW);
  analogWrite(MINUTES_PWM_PIN, 0);
  analogWrite(HOURS_PWM_PIN, 0);
  analogWrite(DAY_PWM_PIN, 0);
  analogWrite(MONTH_PWM_PIN, 0);
}

int selectVoltmeterTimeValue(String valueName, int pin, int maxPWM, int value, int valueMax, int valueMin) {
  bool runningVar = true;
  Serial.println("Setting: " + valueName);

  while (runningVar) {
    byte mappedPwmVal = map((analogRead(POTENTIOMETER_PIN) / 4), 0, 255, 0, maxPWM);
    analogWrite(pin, (mappedPwmVal));

    if (digitalReadDebounce(BUTTON1_PIN)) {
      runningVar = false;
    }
  }
  value = map(analogRead(POTENTIOMETER_PIN), 0, 255, valueMin, valueMax);
  voltmeterAllOff();
  blinkLED();
  Serial.println("Value: " + value);
  return value;
}

void setDateTime(unsigned int setYear, byte setMonth, byte setDay, byte setHour, byte setMin, byte setSec) {
  //arguments are selectVoltmeterTimeValue(valueName, pin, maxPWM, value, valueMax, valueMin)
  voltmeterAllOff();
  setMonth = selectVoltmeterTimeValue("Month", MONTH_PWM_PIN,   MONTH_MAX_PWM,   setMonth, 12,   1);
  setDay = selectVoltmeterTimeValue("Day",     DAY_PWM_PIN,    DAY_MAX_PWM,    setDay,   31,   1);
  setHour = selectVoltmeterTimeValue("Hour",   HOURS_PWM_PIN,   HOURS_MAX_PWM,   setHour,  23,   0);
  setMin = selectVoltmeterTimeValue("Minute",  MINUTES_PWM_PIN, MINUTES_MAX_PWM, setMin,   59,   0);
  setSec = selectVoltmeterTimeValue("Second",  SECONDS_PWM_PIN, SECONDS_MAX_PWM, setSec,   59,   0);

  delay(500);
  Serial.println("Y" + String(setYear) +
                 " M" + String(setMonth) +
                 " D" + String(setDay) +
                 " h" + String(setHour) +
                 " m" + String(setMin) +
                 " s" + String(setSec));

  bool runningVar = true;
  unsigned long targetMillis = 0;
  while (runningVar) {
    if (millis() > targetMillis) {
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
      targetMillis = millis() + 1000;
    }
    if (digitalReadDebounce(BUTTON1_PIN)) {
      runningVar = false;
    }
  }
  digitalWrite(LED_BUILTIN, LOW);
  setTime(setHour, setMin, setSec, setDay, setMonth, setYear);
  RTC.set(now());
  setSyncProvider(RTC.get);
}

unsigned int monthdays[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
unsigned long secondsSince2000(unsigned int yearVar, byte monthVar, byte dayVar, byte hourVar, byte minuteVar, byte secondVar)
{
  // This code stolen from someone else's DS1337 library. It was called
  // "date_to_epoch_seconds()" there, but it didn't do epoch seconds,
  // just seconds since 2000. That's fine in this case, since seconds
  // since 2000 is sufficient for this purpose.
  unsigned long sse = (((unsigned long)yearVar) * 365 * 24 * 60 * 60)   +   ((((unsigned long)yearVar + 3) >> 2) + ((unsigned long)yearVar % 4 == 0 && (unsigned long)monthVar > 2)) * 24 * 60 * 60   +   \
                      ((unsigned long)monthdays[monthVar - 1] + (unsigned long)dayVar - 1) * 24 * 60 * 60   +   ((unsigned long)hourVar * 60 * 60)   +   ((unsigned long)minuteVar * 60)   + (unsigned long)secondVar;
  return sse;
}

void turnOnLCD() {
  digitalWrite(LCD_AND_LIGHTS_POWER_PIN, LOW);
  delay(500);
  lcd.begin(20, 4);
  lcd.clear();
}

void turnOffLCD() {
  digitalWrite(LCD_AND_LIGHTS_POWER_PIN, HIGH);
}

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
  //Serial.begin(9600); //For debugging
  pinMode(SECONDS_PWM_PIN,          OUTPUT);
  pinMode(MINUTES_PWM_PIN,          OUTPUT);
  pinMode(HOURS_PWM_PIN,            OUTPUT);
  pinMode(DAY_PWM_PIN,              OUTPUT);
  pinMode(MONTH_PWM_PIN,            OUTPUT);
  pinMode(LED_BUILTIN,                  OUTPUT);
  pinMode(LCD_AND_LIGHTS_POWER_PIN, OUTPUT);
  pinMode(PIRPIN, INPUT);
  pinMode(BUTTON1_PIN,              INPUT_PULLUP);
  pinMode(POTENTIOMETER_PIN,        INPUT);

  //setSyncProvider to the RTC clock. Sync interval is 5 mins by default
  setSyncProvider(RTC.get);
  //setSyncInterval(interval); // Set the number of seconds between re-syncs

  if (timeStatus() != timeSet) {
    Serial.println("Unable to sync with the RTC");
    while (true) {
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
      delay(500);
    }
  }

  //Year is temporarily wrote to LCD only on startup
  turnOnLCD();
  lcdNumber(year());

  //testing assigning a veriable as a time_t type
  /*
    Serial.println(now());
    Serial.println(second());
    time_t test = now();
    Serial.println();
    Serial.println(test);
    Serial.println(second(test));
  */
}

void loop() {
  //time_t t = now();

  if (digitalRead(BUTTON1_PIN) == LOW) {
    //modify date and time
    if (digitalReadDebounce(BUTTON1_PIN)) {
      setDateTime(year(), month(), day(), hour(), minute(), second());
      delay(100);
      //t = now();
    }
  }

  //Now = secondsSince2000(year(t), month(t), day(t), hour(t), minute(t), second(t));

  //now(); // Returns the current time as seconds since Jan 1 1970 (Test if since 1970 etc)

  //year(t)   vs year()   vs
  //month(t)  vs month()  vs
  //day(t)    vs day()    vs
  //hour(t)   vs hour()   vs DateTime.Hour
  //minute(t) vs minute() vs DateTime.Minute
  //second(t) vs second() vs DateTime.Second

  float exactYear = year() + (month() / 12);

  byte daysInMonth;
  if (month() == 4 or month() == 6 or month() == 9 or month() == 11) {
    //30 days in month
    daysInMonth = 30;
  } else if (month() == 2) {
    //Every year that is exactly divisible by four is a leap year, except for years that are exactly divisible by 100, but these centurial years are leap years if they are exactly divisible by 400
    if ((year() % 4) == 0) {
      if ((year() % 100) == 0) {
        if ((year() % 400) == 0) {
          //leap year
          daysInMonth = 29;
        } else {
          //not leap year
          daysInMonth = 28;
        }
      } else {
        //leap year
        daysInMonth = 29;
      }
    } else {
      //not leap year
      daysInMonth = 28;
    }
  } else {
    //month is no. 1,3,5,7,8,10 or 12 therefore 31 days in these month
    daysInMonth = 31;
  }
  float exactMonth  = month() + (day() / daysInMonth);

  float exactDay    = day() + (float(hour()) / 24);
  float exactHour   = hour() + (float(minute()) / 60);
  float exactMinute = minute() + (float(second()) / 60);
  float exactSecond = second(); // TODO: Make seconds smoother

  //Serial.println(exactMinute);
  //Serial.println(map(     exactMinute, 0, 59, 0, MINUTES_MAX_PWM));
  //Serial.println(mapfloat(exactMinute, 0, 59, 0, MINUTES_MAX_PWM));
  //Serial.println();
  analogWrite(SECONDS_PWM_PIN , map(exactSecond, 0,    59,          0, SECONDS_MAX_PWM));
  analogWrite(MINUTES_PWM_PIN , map(exactMinute, 0,    59,          0, MINUTES_MAX_PWM));
  analogWrite(HOURS_PWM_PIN   , map(exactHour,   0,    23,          0, HOURS_MAX_PWM));
  analogWrite(DAY_PWM_PIN     , map(exactDay,    0,    daysInMonth, 0, DAY_MAX_PWM));
  analogWrite(MONTH_PWM_PIN   , map(exactMonth,  1,    12,          0, MONTH_MAX_PWM));

  delay(100);
}
