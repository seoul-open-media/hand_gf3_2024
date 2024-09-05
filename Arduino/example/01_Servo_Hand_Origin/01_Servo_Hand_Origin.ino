#include <Servo.h>

const int numServos = 1;
const int servoPins[numServos] = {0};
Servo servos[numServos];

void setup() {
  for (int i = 0; i < numServos; i++) {
    servos[i].attach(servoPins[i]);
      servos[i].write(0);
  }
}

void loop() {
  for (int i = 0; i < numServos; i++) {
      servos[i].write(0);
    }
  delay(20);
}
