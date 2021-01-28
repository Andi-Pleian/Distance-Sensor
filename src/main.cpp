#include <Arduino.h>

const int trigpin = 3;
const int echopin = 2;
const int speakerpin = 8;

void setup() {
  pinMode(echopin, INPUT);
  pinMode(trigpin, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(speakerpin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);

  long time = pulseIn(echopin, HIGH);
  float speed = 0.034;
  float distance = (time * speed) / 2;

  Serial.println(distance);

    if (distance <= 11) {
        digitalWrite(LED_BUILTIN, HIGH);

        tone(speakerpin, 1000, 500);
        delay(1000);
    }
    else {
      digitalWrite(LED_BUILTIN, LOW);
      delay(1000);
    }

}
