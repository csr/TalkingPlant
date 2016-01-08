/* Talking plant
Connect LCD to Arduino:
  LCD    -> Arduino
  --------------------------
  1|VSS| -> Arduino GND
  2|VDD| -> Arduino +5v
  3|VO | -> Arduino GND pin + Resistor or Potentiometer
  4|RS | -> Arduino pin 12
  5|RW | -> Arduino GND - pin can be conected to 11. But Ground was used here.
  6|E  | -> Arduino pin 10
  7|D0 | -> Arduino - Not Connected
  8|D1 | -> Arduino - Not Connected
  9|D2 | -> Arduino - Not Connected
 10|D3 | -> Arduino - Not Connected
 11|D4 | -> Arduino pin 5 
 12|D5 | -> Arduino pin 4
 13|D6 | -> Arduino pin 3
 14|D7 | -> Arduino pin 2
 15|A  | -> Arduino Pin 13 + Resistor (Backlight power)
 16|K  | -> Arduino GND (Backlight ground)
*/

#include <LiquidCrystal.h>
const int moistureSensor = A0;
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
int backLight = 13;

char thingsToSay[][80] =  {"Ti prego!",
                           "Acqua!",
                           "Dissetami!",
                           "Sto male!",
                           "Moriro'!",
                           "Un po' d'acqua?",
                           "Sali minerali!",
                           "Calo di zuccheri!",
                           "Mi salverai?",
                           "Innaffiami"};
int previousRandomNumber;

void setup() {
  pinMode(backLight, OUTPUT);
  pinMode(A0, INPUT);
  
  analogWrite(backLight, 150);
  lcd.begin(16,2);                    // columns, rows. size of display
  lcd.clear();                        // clear the screen
  
  Serial.begin(9600);
}

int generateRandomNumber(int min, int max) {
    return rand() % (max-min) + min;
}

void checkMoistureSensor() {
   int moistureState = analogRead(A0);
   Serial.println(moistureState);
   if (moistureState < 100) {
    lcd.print("Collega pianta");
   } else if (moistureState >= 100 && moistureState <= 500) {
    int randomNumber = generateRandomNumber(0, 10);
    lcd.print(thingsToSay[randomNumber]);
   } else {
    lcd.print("Sto bene ora!");
   }
   lcd.setCursor(0, 1);
   for (int i = 0; i < moistureState; i += 75) {
    lcd.print("~");
   }
   delay(700);
   lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  checkMoistureSensor();
}
