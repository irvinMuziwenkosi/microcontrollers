#include <stdlib.h>

int ledPin = 2;
#define PIN_RED 23    // GPIO23
#define PIN_GREEN 22  // GPIO22
#define PIN_BLUE 21   // GPIO21

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
}

// int r = rand() % 256;
// int g = rand() % 256;
// int b = rand() % 256;

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(ledPin, HIGH);
  // for (int i = 0; i < 2; i++) {
  //   digitalWrite(ledPin, HIGH);
  //   delay(140);
  //   digitalWrite(ledPin, LOW);
  //   delay(140);
  //   // digitalWrite(ledPin, HIGH);
  //   // delay(100);
  //   // digitalWrite(ledPin, LOW);
  // }
  // delay(1100);
  // setColor((rand() % 256), (rand() % 256), (rand() % 256));
  // setColor(40, 40, 40);
  // delay(4000);
}
void setColor(int r, int g, int b) {
  analogWrite(PIN_RED, r);
  analogWrite(PIN_GREEN, g);
  analogWrite(PIN_BLUE, b);
}
