#include <Servo.h>

const int numServos = 5;
const int servoPins[numServos] = {0, 1, 2, 3, 4};
Servo servos[numServos];

byte value[5] = {0, 180, 180, 180, 0};
unsigned long lasttimeservo = 0;

void setup() {
  Serial.begin(115200);
    for (int i = 0; i < numServos; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(0);
  }

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
    lasttimeservo = millis();
  }

}
