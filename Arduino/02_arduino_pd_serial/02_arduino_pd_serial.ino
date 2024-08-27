#include <Servo.h>

const int numServos = 10;
const int servoPins[numServos] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
Servo servos[numServos];

byte value[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned long lasttimeservo = 0;

void setup() {
  Serial.begin(115200);

}

void loop() {
  // Serial
  if (Serial.available() > 10) {
    if (Serial.read() == 255) {
      for (int i = 0; i < 10; i++) {
        value[i] = Serial.read();
      }

    } else {
      while (Serial.available())Serial.read();
    }
  }

  // Servo
  if (millis() > lasttimeservo + 20) {
    for (int i = 0; i < numServos; i++) {
      servos[i].write(value[i]);
    }
  }

}
