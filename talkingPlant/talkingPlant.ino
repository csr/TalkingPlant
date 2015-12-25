/* Talking plant */

const int moistureSensor = A0;
const int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(A0, INPUT);
}

void loop() {
  int moistureState = analogRead(A0);
  if (moistureState < 550) {
     Serial.println(moistureState);
     digitalWrite(led, HIGH);
  } else {
     digitalWrite(led, LOW);
  }
}
