/*
   s3servo.cpp - Library for control servo motor on esp32s3.
   Created by HA.S, October 10, 2022.
   Released into the public domain.
   mit라이선스라고하고싶은데 arduino-esp32 라이선스 따라가야겠지? 아직 라이선스 잘모르니 그냥 arduino-esp32 이거 사용"했으니 이거 따름
*/
#include <s3servo.h>

s3servo::s3servo() {
};

s3servo::~s3servo() {
    detach();
};

void s3servo::detach() {
    ledcDetachPin(_pin);
};

void s3servo::_setAngleRange(int min, int max){
    _minAngle=min;
    _maxAngle=max;
    };
void s3servo::_setPulseRange(int min, int max){
    _minPulseWidth=min;
    _maxPulseWidth=max;
};

int8_t s3servo::attach(int pin, int channel , int min_angle, int max_angle, int min_pulse, int max_pulse)
{
    if(CHANNEL_MAX_NUM < channel || channel < 0){
        return -1;
    }
    _pin = pin; 
    _channel = channel;
    _setAngleRange(min_angle,max_angle);
    _setPulseRange(min_pulse,max_pulse);
    ledcSetup(channel, 50, MAX_BIT_NUM);
    ledcAttachPin(_pin, _channel);
    return 0;
};



void s3servo::write(int angle) {
    int duty = map(angle, _minAngle, _maxAngle, _minPulseWidth, _maxPulseWidth);
    constrain(duty, _minPulseWidth, _maxPulseWidth);
    ledcWrite(_channel, duty);
};

void s3servo::writeDuty(int duty) {
    ledcWrite(_channel, duty);
};
