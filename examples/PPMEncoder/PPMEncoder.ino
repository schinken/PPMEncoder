#include "PPMEncoder.h"

#define OUTPUT_PIN 10

void setup() {
  ppmEncoder.begin(OUTPUT_PIN);
}

void loop() {

  // Min value
  ppmEncoder.setChannel(0, 500);
  ppmEncoder.setChannel(0, PPMEncoder::MIN);
  ppmEncoder.setChannelPercent(0, 0);

  // Max value
  ppmEncoder.setChannel(0, 2500);
  ppmEncoder.setChannel(0, PPMEncoder::MAX);
  ppmEncoder.setChannelPercent(0, 100);
}
