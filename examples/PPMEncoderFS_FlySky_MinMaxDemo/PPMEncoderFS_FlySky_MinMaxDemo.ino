/* 12-11-2023
 Christopher Schirner
 https://github.com/schinken/PPMEncoder  
 PPMEncoderFS.h modified to match FlySky FS-i6X
   #define PPM_PULSE_LENGTH_uS 400
   #define PPM_FRAME_LENGTH_uS 20000
   static const uint16_t MIN = 1000;
   static const uint16_t MAX = 2000;
*/

#include "PPMEncoderFS.h"
#define OUTPUT_PIN 9
#define NUM_CHANNELS 6

void setup() {
ppmEncoderFS.begin(OUTPUT_PIN,NUM_CHANNELS);
Serial.begin(9600);
Serial.println("PPMEncoderFS FlySky FS-i6 Six Channels Min / Six Channels Max Demo");
} 

void loop() {
ppmEncoderFS.setChannel(0,PPMEncoderFS::MIN);
ppmEncoderFS.setChannel(1,PPMEncoderFS::MIN);
ppmEncoderFS.setChannel(2,PPMEncoderFS::MIN);
ppmEncoderFS.setChannel(3,PPMEncoderFS::MIN);
ppmEncoderFS.setChannel(4,PPMEncoderFS::MIN);
ppmEncoderFS.setChannel(5,PPMEncoderFS::MIN);
delay(2000);

ppmEncoderFS.setChannel(0,PPMEncoderFS::MAX);
ppmEncoderFS.setChannel(1,PPMEncoderFS::MAX);
ppmEncoderFS.setChannel(2,PPMEncoderFS::MAX);
ppmEncoderFS.setChannel(3,PPMEncoderFS::MAX);
ppmEncoderFS.setChannel(4,PPMEncoderFS::MAX);
ppmEncoderFS.setChannel(5,PPMEncoderFS::MAX);
delay(2000);
}
