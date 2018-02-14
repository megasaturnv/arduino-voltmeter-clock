#include <DS3232RTC.h>
#include <LiquidCrystal.h>

#define LED_PIN 13

LiquidCrystal lcd(11, 12, A0, A1, A2, A3);

/*
  array eventsArray1[][2] = {
  {time_t makeTime(59, 59 , 23, 30, 12, 2017), String "Event here"},
  {time_t makeTime(59, 59 , 23, 30, 12, 2017), String "Event here"}
  };

  array eventsArray2[] = {
  {time_t a1 = makeTime(59, 59 , 23, 30, 12, 2017), String a2 = "Event here"},
  {time_t b1 = makeTime(59, 59 , 23, 30, 12, 2017), String b2 = "Event here"}
  };

  array eventsArray3[] = {
  {time_t a1[] = makeTime(59, 59 , 23, 30, 12, 2017), String a2[] = "Event here"},
  {time_t b1[] = makeTime(59, 59 , 23, 30, 12, 2017), String b2[] = "Event here"}
  };
*/

String eventsArray[] = {
  "20171230235959=Event here",
  "20171230235959=Event here"
};

String getNextEvents(byte numberOfEvents) {
  word eventYear = eventsArray[0].substring(0, 3).toInt();
  word eventMonth = (eventsArray[0].substring(4, 5)).toInt();
  //word eventDay = eventsArray[0].substring(6, 7);
  //word eventHour = eventsArray[0].substring(8, 9);
  //word eventMinute = eventsArray[0].substring(10, 11);
  //word eventSecond = eventsArray[0].substring(11, 13);
  String event1 = eventsArray[0].substring(eventsArray[0].indexOf('='));
  String event2 = eventsArray[0].substring(15);
}

//string.charAt(14)
//string.indexOf('=')
//string.substring(from, to)
//string.toInt()
//    strchr(): search for a character in a C string (i.e. char *)
//    strtok(): splits a C string into substrings, based on a separator character
//    atoi(): converts a C string to an int

void setup() {
  Serial.begin(9600); //For debugging
  pinMode(LED_PIN,           OUTPUT);

  //setSyncProvider to the RTC clock. Sync interval is 5 mins by default
  setSyncProvider(RTC.get);
  //setSyncInterval(interval); // Set the number of seconds between re-syncs
  if (timeStatus() != timeSet) {
    Serial.println("Unable to sync with the RTC");
    while (true) {
      digitalWrite(LED_PIN, !digitalRead(LED_PIN));
      delay(500);
    }
  }
  lcd.clear();
}

void loop() {
  lcd.clear();
  lcd.print(weekday()); // Day of the week (1-7), Sunday is day 1
  delay(5000);

}
