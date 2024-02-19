#ifndef PCA9535_h
#define PCA9535_h

#include "Arduino.h"
#include <Wire.h>

class PCA9557
{
public:
	PCA9557(uint8_t PCAaddress, bool beginWire = false);
	uint8_t readInputGpio();
	uint8_t readOutputGpio();
	void writeGpio(uint8_t groupValue);
	uint8_t readInputPolarity();
	void setPolarityInversion(uint8_t groupValue);
	uint8_t readConfiguration();
	void setConfiguration(uint8_t configuration);
	void setAddress(uint8_t PCAaddress);

private:
	enum commandRegisters
	{
		inputP0 = 0,
		outputP0,
		polarityInversionP0,
		configurationP0,
	};

	uint8_t
		PCA9557Address,
		returnDataSize = 1;

	void writeI2c(uint8_t address, uint8_t data);
	void writeI2c(uint8_t address, uint8_t data, uint8_t data2);
	uint8_t readI2c(uint8_t address);
};

#endif
