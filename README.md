# ESP32-S3 servo
Esp32 and esp32s3 of espressif are similar and different. Although I tried to operate the servo motor using esp32s3, existing open source libraries did not support esp32s3. I want people in the same situation like me to solve the problem with this code.
espressif사의 Esp32와 esp32s3는 비슷하면서 다르다. 나는 esp32s3를 사용하여 서보 모터를 작동하려고 했지만, 기존 오픈 소스 라이브러리는 esp32s3를 지원하지 않았습니다. 나는 같은 상황에 있는 사람들이 이 코드로 문제를 해결했으면 좋겠다.

## The difference between ESP32-S3 and ESP32(about LCPWM)
|?|ESP32|ESP32S3|
|:---:|:---:|:---:|
|channel|16|8|
|bit width|16|14|
위와 같은 차이때분에 기존 라이브러리들이 동작을 안한다.
Due to the above difference, existing libraries do not work on ESP32-S3.

## Example 
```cpp
TEST()
```

## In future
-MCPWM에 대하여 아직 읽어보지 않았다. LEDC보다 더 효율적이고 정확하다면 수정할것이다. 게다가 BLDC모터를 서보처럼 동착하는 코드도 추가 할 계획이다.
-I haven't read about MCPWM yet. If it is more efficient and accurate than LEDC, it will be modified. In addition, it plans to add a code that makes the BLDC motor come up like a servo.
