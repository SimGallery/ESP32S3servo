# ESP32-S3 servo
-ESP32 and ESP32S3 of espressif are similar and different. Although I tried to operate the servo motor using ESP32S3, existing open source libraries did not support ESP32S3. I want people in the same situation like me to solve the problem with this code.<br>
-espressif사의 ESP32 ESP32S3 비슷하면서 다르다. 나는 esp32s3를 사용하여 서보 모터를 작동하려고 했지만, 기존 오픈 소스 라이브러리는 esp32s3를 지원하지 않았습니다. 나는 같은 상황에 있는 사람들이 이 코드로 문제를 해결했으면 좋겠다.

## The difference between ESP32-S3 and ESP32(about LCPWM)

| |ESP32|ESP32S3|
|:--:|:--:|:-:|
|channel|16|**8**|
|bit width|16|**14**|

-위와 같은 차이때분에 기존 라이브러리들이 동작을 안한다.<br>
-Due to the above difference, existing libraries do not work on ESP32-S3.

## Example 
```cpp
s3servo servo;

servo.attach(ioPin); //Automatically enter parameters (0,180,500,2000)
//servo.attach(ioPin,channel,min_angle,max_angle,min_pulseWidth,max_pulseWidth); // Manually enter parameters

servo.write(int Angle);
//servo.writeDuty(int Duty); // More sophisticated operation is possible by typing Dutycycle directly.
```

## In future
-MCPWM에 대하여 esp32s3의 데이터시트를 아직 읽어보지 않았다. ESP-IDF에서 말고 arduino-esp32 에서 MCPWM를 지원하며 LEDC보다 더 효율적고 정확하다면 코드를 추가할것이다. 게다가 BLDC모터를 서보처럼 동착하는 코드도 추가 할 계획이다. (그러면 리파짓토리 이름을 바꿔야할텐데..)<br>
-I have not yet read the data sheet of esp32s3 for MCPWM. It supports MCPWM on arduino-esp32 instead of ESP-IDF and will add code if it is more efficient and accurate than LEDC. In addition, it plans to add a code that makes the BLDC motor come up like a servo. (Then we should change the name of repository...)
