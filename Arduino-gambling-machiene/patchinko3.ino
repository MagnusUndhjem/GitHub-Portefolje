#include <LiquidCrystal.h>
#include <Wire.h>

#define SLAVE_ADDR 8

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int buttonPin = 7;  // Oppdatert pin for knappen
int x = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

bool isAnimationPlayed = false;  // Flagg for å sjekke om animasjonen er spilt

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Bruker intern pull-up motstand
  lcd.begin(16, 2);                 // Initialiser LCD
  lcd.clear();                      // Sørger for at LCD er klar ved oppstart

  Wire.begin(SLAVE_ADDR);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  if(x == 1) {
    for (int position = 0; position < 16; position++) {
      lcd.clear();                  // Rydd skjermen for å forhindre spøkelsestegn
      lcd.setCursor(position, 0);   // Sett posisjon på første rad
      lcd.print("0");               // Vis ballen
      delay(300);                   // Vent litt før du flytter ballen
    }
    x = 0;
    lcd.clear();  
  }
}
void receiveEvent() {
  x = 1;   
}