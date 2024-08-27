#include <Servo.h>

const int numServos = 5;  // 서보 모터 개수
const int servoPins[numServos] = {0, 1, 2, 3, 4};  // 서보 모터 핀 번호 배열
Servo servos[numServos];  // 서보 객체 배열

void setup() {
  // 각 서보 모터를 핀에 연결하고 초기 각도를 0도로 설정
  for (int i = 0; i < numServos; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(0);  // 서보 모터의 각도를 0도로 설정
  }
}

void loop() {
  // loop에서 서보 모터의 각도를 0도로 계속 설정
  for (int i = 0; i < numServos; i++) {
    servos[i].write(0);  // 서보 모터의 각도를 0도로 유지
  }
  delay(20);  // 작은 딜레이를 추가하여 CPU를 너무 많이 사용하지 않도록 설정
}
