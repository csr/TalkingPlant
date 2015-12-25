/* Talking plant */
#include <LiquidCrystal.h>

const int moistureSensor = A0;
const int led = 6;
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
int backLight = 13;    // pin 13 will control the backlight

void setup() {
  pinMode(backLight, OUTPUT);
  analogWrite(backLight, 150);
  lcd.begin(16,2);                    // columns, rows. size of display
  lcd.clear();                        // clear the screen
  
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  int moistureState = analogRead(A0);
  if (moistureState < 550) {
     Serial.println(moistureState);
     digitalWrite(led, HIGH);
     int random = rand() + 4;
     lcd.print("Ho sete!");
     delay(300);
     lcd.clear();
     delay(300);
     lcd.print("Acqua!");
     delay(300);
     lcd.clear();
     delay(300);
     lcd.print("Ti prego!");
     delay(300);
     lcd.clear();
     delay(300);
  } else {
     digitalWrite(led, LOW);
     lcd.clear();
     delay(300);
     lcd.print("Grazie salvatore!");
  }
}
