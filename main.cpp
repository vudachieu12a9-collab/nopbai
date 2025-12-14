#include <Servo.h>
#include <Arduino.h>

Servo servo1;
Servo servo2;

void setup() {
  servo1.attach(9);   // Servo 1 nối chân số 9
  
}

void loop() {
  // 1. Cùng quay xuôi 3 giây
  servo1.write(0);    // Góc 0 độ (xuôi)
  servo2.write(0);
  delay(3000);

  // 2. Cùng quay ngược 2 giây
  servo1.write(180);  // Góc 180 độ (ngược)
  servo2.write(180);
  delay(2000);

  // 3. Quay ngược chiều nhau trong 10 giây
  unsigned long startTime = millis();
  while (millis() - startTime < 10000) {
    servo1.write(0);      // Servo 1 xuôi
    servo2.write(180);    // Servo 2 ngược
    delay(500);

    servo1.write(180);    // Đảo chiều
    servo2.write(0);
    delay(500);
  }
}
