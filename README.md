The *PPMEncoder Library Routine* has been modified to be compatible with the<br>
**FlySky** Remote Control FS-i6X Transmitter and the FS-iA6B Receiver system,<br>
and renamed *PPMEncoderFS*.

The following code modifications were incorporated:<br>
	  #define PPM_DEFAULT_CHANNELS 8   
	  #define PPM_PULSE_LENGTH_uS 400  
	  #define PPM_FRAME_LENGTH_uS 20000  
	  static const uint16_t MIN = 1000;  
	  static const uint16_t MAX = 2000;

Two Example Sketches illustrate the syntax and demonstrate PPMEncoderFS:

	PPMEncoderFS_FlySky_MinMaxDemo.ino
	  Gang switches Channels 1 - 6 back and forth between  
	    minimum pulse width 1000 usec (Full CCW servo rotation) and    
	    maximum pulse width 2000 usec (Full CW servo rotation)
    
	PPMEncoderFS_FlySky_MinMidMaxDemo.ino
 	  Sequentially switches six channels,
	    from minimum pulse width (1000 usec) to
	    mid-range pulse width (1500 usec) to 
	    maximum pulse width (2000 usec) and back to mid-range and to minimum.
    
The pulse width modulation waveforms can be viewed using an oscilloscope connected to the Arduino output pin #9.

Both sketches have been tested using the FlySky RC radio system by connecting the output from Arduino pin #9 to the <br>FlySky Trainer Port PPM<sub>in</sub> [FlySky Trainer Port](FlySkyTrainerPort.jpg).

Also included are two .mp4 video clips of the outputs described above.<br>
[Six Channels Maximum and Minimum Pulse Widths](PPMEncoder_6CH_Min_Max.mp4)<br>
[Six Channels Alternating between Min, Mid, and Max Pulse Widths](PPMEncoder_6Ch_Min_Mid_Max.mp4)

The next goal is port PPMEncoderFS library utility to work with the Pico RP2040 chip and incorporate the results into Phase Four of the Adaptive RC Sailer Interface Project www.adaptivercsailer.com.

