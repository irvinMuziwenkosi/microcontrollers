// #include <stdlib.h>
#include <TM1637Display.h>


#define PIN_RED 25    // GPIO25
#define PIN_GREEN 26  // GPIO26
#define PIN_BLUE 27   //GPIO27
//Ultrasonic
#define ECHO_PIN 32            //GPIO32 connected to Ultrasonic Sensor's ECHO pin
#define TRIG_PIN 33            //GPIO33 connected to Ultrasonic Sensor's TRIG pin
#define DISTANCE_THRESHOLD 50  // centimeters
//4 Digit
#define CLK 23  // The ESP32 pin GPIO23 connected to CLK
#define DIO 22  // The ESP32 pin GPIO22 connected to DIO


// variables will change:
float duration_us, distance_cm;

bool codeRunning = true;
bool greenColorIncr = true;

TM1637Display display = TM1637Display(CLK, DIO);

void setup() {
  Serial.begin(9600);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  display.clear();
  display.setBrightness(7);  // set the brightness to 7 (0:dimmest, 7:brightest)
}

void loop() {
  if (codeRunning) {
    // generate 10-microsecond pulse to TRIG pin
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // measure duration of pulse from ECHO pin
    duration_us = pulseIn(ECHO_PIN, HIGH);
    // calculate the distance
    distance_cm = 0.017 * duration_us;

    //Show distance to the 7 segment display
    display.showNumberDec(distance_cm, false);


    if (distance_cm < 10) {
      setColor(250, 10, 10);
    } else if (distance_cm < 20) {
      setColor(250, 255, 0);
    } else if (distance_cm < 30) {
      setColor(20, 240, 20);
    } else setColor(0, 0, 0);
    Serial.print("Distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");
    delay(500);   
  }
}
void setColor(int r, int g, int b) {
  analogWrite(PIN_RED, r);
  analogWrite(PIN_GREEN, g);
  analogWrite(PIN_BLUE, b);
}
