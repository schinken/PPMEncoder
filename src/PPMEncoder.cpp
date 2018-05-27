#include "PPMEncoder.h"

PPMEncoder ppmEncoder;

void PPMEncoder::begin(uint8_t outputPin) {
  begin(outputPin, PPM_DEFAULT_CHANNELS);
}

void PPMEncoder::begin(uint8_t outputPin, uint8_t numChannels) {
  cli();

  pinMode(outputPin, OUTPUT);
  digitalWrite(outputPin, LOW);

  state = true;
  elapsedUs = 0;
  currentChannel = 0;

  numChannels = numChannels;
  outputPin = outputPin;

  for (uint8_t ch = 0; ch < numChannels; ch++) {
    setChannelPercent(ch, 0);
  }

  TCCR1A = 0;

  OCR1A = 100;
  TCCR1B = (1 << WGM12) | (1 << CS11);
  TIMSK1 = (1 << OCIE1A); // enable timer compare interrupt

  sei();
}

void PPMEncoder::setChannel(uint8_t channel, uint16_t value) {
  channels[channel] = constrain(value, PPM_MIN_VALUE, PPM_MAX_VALUE);
}

void PPMEncoder::setChannelPercent(uint8_t channel, uint8_t percent) {
  percent = constrain(percent, 0, 100);
  setChannel(channel, map(percent, 0, 100, PPM_MIN_VALUE, PPM_MAX_VALUE));
}

void PPMEncoder::interrupt() {
  TCNT1 = 0;

  if (state) {
    digitalWrite(outputPin, HIGH);
    OCR1A = PPM_PULSE_LENGTH_uS * 2;

  } else {
    digitalWrite(outputPin, LOW);

    if (currentChannel >= numChannels) {
      currentChannel = 0;
      elapsedUs = elapsedUs + PPM_PULSE_LENGTH_uS;
      OCR1A = (PPM_FRAME_LENGTH_uS - elapsedUs) * 2;
      elapsedUs = 0;
    } else {
      OCR1A = (channels[currentChannel] - PPM_PULSE_LENGTH_uS) * 2;
      elapsedUs = elapsedUs + channels[currentChannel];

      currentChannel++;
    }
  }

  state = !state;
}

ISR(TIMER1_COMPA_vect) {
  ppmEncoder.interrupt();
}
