# ESP32-S3 servo
Esp32 and esp32s3 of espresif are similar and different. Although we tried to operate the servo motor using esp32s3, existing open source libraries did not support esp32s3. I want people in the same situation to solve the problem with this code.

## the difference between ESP32-S3 and ESP32(about LCPWM)
|?|ESP32|ESP32S3|
|::|::|::|
|channel|16|8|
|bit width|16|14|
ESP32 는 16개의 LEDC를 지원하고있다. 반면에 ESP32-S3는 8개의 채널을 지원한다.
이에 맞게 코드를 작성하였다.

## MCPWM에 대하여 아직 읽어보지 않았다. LEDC보다 더 효율적이고 정확하다면 수정할것이다. 게다가 BLDC모터를 서보처럼 동착하는 코드도 추가 할 계획이다.
