//*************************************************************************************
/** \file ArduinoDriver_RCD_24.h
 *    This file contains a driver to operate the Recon RCD-24-1.2A LED driver module.
 *
 *  Revisions:
 *    28-09-2016 VEE Original file.
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

#ifndef ARDUINODRIVER_RCD_24_H
#define ARDUINODRIVER_RCD_24_H

#include <Arduino.h>

class ArduinoDriver_RCD_24 {
	public:
		// Constructors
		ArduinoDriver_RCD_24(uint8_t PWM); // Constructor using default PWM freq of 200Hz
		ArduinoDriver_RCD_24(uint8_t PWM, uint16_t freq); // User defined frequency
						   
		// Public Methods
		void init();	// Initialize pins, set PWM frequency, adjust PWM resolution to 10bit
		void setBrightness(uint16_t brightness); // Speed value serves as PWM dutycycle		
	
	private:
		// Pin assignments
		uint8_t _pin;
		uint16_t _freq;
		
};

#endif