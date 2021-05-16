#ifndef _PPMEncoder_h_
#define _PPMEncoder_h_

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define PPM_DEFAULT_CHANNELS 8

#define PPM_PULSE_LENGTH_uS 500
#define PPM_FRAME_LENGTH_uS 22500

class PPMEncoder {

  private:
    int16_t channels[10];
    uint16_t elapsedUs;

    uint8_t numChannels;
    uint8_t currentChannel;
    byte outputPin;
    boolean state;
	
    uint8_t onState;
    uint8_t offState;


  public:
    static const uint16_t MIN = 1000;
    static const uint16_t MAX = 3000;

    void setChannel(uint8_t channel, uint16_t value);
    void setChannelPercent(uint8_t channel, uint8_t percent);

    void begin(uint8_t pin);
    void begin(uint8_t pin, uint8_t ch);
    void begin(uint8_t pin, uint8_t ch, boolean inverted);

    void interrupt();
};

extern PPMEncoder ppmEncoder;

#endif
