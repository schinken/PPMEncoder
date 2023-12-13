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
int ServoMin=1000;
int ServoMid=1500;
int ServoMax=2000;

void setup() {
ppmEncoderFS.begin(OUTPUT_PIN,NUM_CHANNELS);
Serial.begin(9600);
Serial.println("PPMEncoderFS FlySky FS-i6 Six Channels Min Mid Max");
} 

void loop() {
// Switch from Min,Mid,Max by Channel 1-6
ppmEncoderFS.setChannel(0,ServoMid);
delay(800);
ppmEncoderFS.setChannel(0,ServoMax);
delay(800);
ppmEncoderFS.setChannel(0,ServoMid);
delay(800);
ppmEncoderFS.setChannel(0,ServoMin);
delay(800);
ppmEncoderFS.setChannel(1,ServoMid);
delay(800);
ppmEncoderFS.setChannel(1,ServoMax);
delay(800);
ppmEncoderFS.setChannel(1,ServoMid);
delay(800);
ppmEncoderFS.setChannel(1,ServoMin);
delay(800);
ppmEncoderFS.setChannel(2,ServoMid);
delay(800);
ppmEncoderFS.setChannel(2,ServoMax);
delay(800);
ppmEncoderFS.setChannel(2,ServoMid);
delay(800);
ppmEncoderFS.setChannel(2,ServoMin);
delay(800);
ppmEncoderFS.setChannel(3,ServoMid);
delay(800);
ppmEncoderFS.setChannel(3,ServoMax);
delay(800);
ppmEncoderFS.setChannel(3,ServoMid);
delay(800);
ppmEncoderFS.setChannel(3,ServoMin);
delay(800);
ppmEncoderFS.setChannel(4,ServoMid);
delay(800);
ppmEncoderFS.setChannel(4,ServoMax);
delay(800);
ppmEncoderFS.setChannel(4,ServoMid);
delay(800);
ppmEncoderFS.setChannel(4,ServoMin);
delay(800);
ppmEncoderFS.setChannel(5,ServoMid);
delay(800);
ppmEncoderFS.setChannel(5,ServoMax);
delay(800);
ppmEncoderFS.setChannel(5,ServoMid);
delay(800);
ppmEncoderFS.setChannel(5,ServoMin);
delay(800);

}
