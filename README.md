# PPMEncoder

This library generates a Pule-Position-Signal using interrupts, so you don't have to care about timings in your software! Take a look at the examples how to use this library - I hope you find it easy to use :)

## Introduction

A simple visual on how a PPM signal works:

![PPM Signal](https://upload.wikimedia.org/wikipedia/commons/6/65/Fernsteuerungsmodulation.gif)
CC-BY-SA 3.0 Christian Wolff

Your value range is from 0,5ms to 1.5ms. This results in timer1 overflow values from 500 to 2500 - which is your range you can use.

## Setup

By default there are *8 Channels* use can use. You can set this value using the begin-function.

```c
void begin(uint8_t outputPin);
void begin(uint8_t outputPin, uint8_t numChannels);
```
For more than 8 channels, the frame length has to increase - which is not configurable yet.
