#include <s3servo.h>

static const int servoPin = 4;

s3servo servo;

String input_str = "";
void setup() {
    Serial.begin(115200);
    servo.attach(servoPin);
    //servo.attach(servoPin,0,0,180,500,2000); //핀,채널 0~7,최저각도,최고각도,최저 각도의 듀티, 최고 각도의 듀티)
}

void loop() {

    while (Serial.available()) {
      char c = Serial.read(); 
      input_str += c; 
      delay(3); 
    }

    if (input_str.length()) {
      int duty = input_str.toInt();
      servo.writeDuty(duty);
      input_str = "";
    }
}