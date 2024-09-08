#include <stdlib.h>

#define PIN_RED 25    // GPIO25
#define PIN_GREEN 26  // GPIO26
#define PIN_BLUE 27   //GPIO27
#define ECHO_PIN 32
#define TRIG_PIN 33

void setup() {
  Serial.begin(9600);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
}

bool codeRunning = false;
bool greenColorIncr = true;

void loop() {
  if (codeRunning) {
    for (int r = 0, g = 127, b = 255; r < 255; r++) {
      setColor(r, g, b);
      Serial.print("r: ");
      Serial.print(r);
      Serial.print(", g: ");
      Serial.print(g);
      Serial.print(", b: ");
      Serial.println(b);
      b--;
      if (g == 255) {
        greenColorIncr = false;
      } 
      if (g == 0) {
        greenColorIncr = true;
      }
      if (greenColorIncr) g++;
      else if(!greenColorIncr) g--;
      delay(100);
    }
    for (int r = 255, g = 127, b = 0; r > 0; r--) {
      setColor(r, g, b);
      Serial.print("r: ");
      Serial.print(r);
      Serial.print(", g: ");
      Serial.print(g);
      Serial.print(", b: ");
      Serial.println(b);
      b++;
      if (g == 255) {
        greenColorIncr = false;
      }
      if (g == 0) {
        greenColorIncr = true;
      }
      if (greenColorIncr) g++;
      else if(!greenColorIncr) g--;
      delay(100);
    }
  }
}
void setColor(int r, int g, int b) {
  analogWrite(PIN_RED, r);
  analogWrite(PIN_GREEN, g);
  analogWrite(PIN_BLUE, b);
}
