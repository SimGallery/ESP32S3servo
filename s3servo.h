/*
   s3servo.h - Library for control servo motor on esp32s3.
   Created by HA.S, October 10, 2022.
   Released into the public domain.
   mit라이선스라고하고싶은데 arduino-esp32 라이선스 따라가야겠지? 아직 라이선스 잘모르니 그냥 arduino-esp32 이거 사용했으니 이거 따름
*/

#ifndef S3SERVO_H
#define S3SERVO_H

#include "Arduino.h"


#if defined (CONFIG_IDF_TARGET_ESP32S3)
#define CHANNEL_MAX_NUM  7
#define MAX_BIT_NUM  14
#else 
#define CHANNEL_MAX_NUM  15
#define MAX_BIT_NUM  16
#endif

class s3servo {

public:
    
    s3servo();
    ~s3servo();

    int8_t attach(int pin, int channel = 0, int min_angle=0, int max_angle=180, int min_pulse=500, int max_pulse=2000);// emax es9251II
    void detach();

    void write(int angle);
    void writeDuty(int duty);

private:
    int _pin;
    int _channel;
    int _minAngle;
    int _maxAngle;
    int _minPulseWidth;
    int _maxPulseWidth;
    void _setAngleRange(int min, int max);
    void _setPulseRange(int min, int max);
};

#endif

