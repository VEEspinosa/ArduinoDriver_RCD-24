//*************************************************************************************
/** \file ArduinoDriver_RCD_24.cpp
 *    This file contains a a motor driver. This driver allows for motor power to be 
 *	  specified, for the braking function to be enabled, and for the motor current to be read.
 *
 *  Revisions:
 *    27-09-2016 VEE Original file.
 *
 *  License:
 *    This file is copyright 2016 by V. Espinosa and released under the Lesser GNU 
 *    Public License, version 2. It intended for educational use only, but its use
 *    is not limited thereto. */
/*    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 *    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 *    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 *    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
 *    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUEN-
 *    TIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS 
 *    OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
 *    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
 *    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
//*************************************************************************************

#include "ArduinoDriver_RCD_24.h"

// Constructor
ArduinoDriver_RCD_24::ArduinoDriver_RCD_24(uint8_t PWM) {
	
   _pin = PWM;
   _freq = 200;
}

ArduinoDriver_RCD_24::ArduinoDriver_RCD_24(uint8_t PWM, uint16_t freq) {
	
   _pin = PWM;
   _freq = freq;
}

void ArduinoDriver_RCD_24::init() {
	// Define pin modes 
	pinMode(_pin,OUTPUT);
	
	// Set PWM frenquency to
	analogWriteFrequency(_pin, _freq);
	
	// Set PWM dutycycle resolution to 10 bits, which is compatible with 72MHz Teensy
	analogWriteResolution(10); // Max value is 1023
}

void ArduinoDriver_RCD_24::setBrightness(uint16_t brightness) {
		
	// Make sure that the value for brightness does not exceed the max dutycycle value of 1023
	if (brightness > 1023) {
		brightness = 1023;
	}
	
	brightness = 1023 - brightness; // RCD Module interprets low PWM dutycycle as high brightness
									// Must invert brightness level so that when user sends
									// low value for brightness, the LEDs are dim (normal op.)
	
	// Send PWM signal to VNH5019 using 10-bit dutycycle
	analogWrite(_pin,brightness);
}


// EOF