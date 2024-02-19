#include "Arduino.h"
#include "PCA9557.h"

PCA9557::PCA9557(uint8_t PCAaddress, bool beginWire)
{
  PCA9557Address = PCAaddress;
  if (beginWire)
    Wire.begin();
}

void PCA9557::writeI2c(uint8_t address, uint8_t data)
{
  Wire.beginTransmission(address);
  Wire.write(data);
  Wire.endTransmission();
}

void PCA9557::writeI2c(uint8_t address, uint8_t data, uint8_t data2)
{
  Wire.beginTransmission(address);
  Wire.write(data);
  Wire.write(data2);
  Wire.endTransmission();
}

uint8_t PCA9557::readI2c(uint8_t address)
{
  Wire.requestFrom(address, returnDataSize);
  return Wire.read();
}

uint8_t PCA9557::readInputGpio()
{
  writeI2c(PCA9557Address, inputP0);
  return readI2c(PCA9557Address);
}

uint8_t PCA9557::readOutputGpio()
{
  writeI2c(PCA9557Address, outputP0);
  return readI2c(PCA9557Address);
}

void PCA9557::writeGpio(uint8_t groupValue)
{
  writeI2c(PCA9557Address, outputP0, groupValue);
}

uint8_t PCA9557::readInputPolarity()
{
  writeI2c(PCA9557Address, polarityInversionP0);
  return readI2c(PCA9557Address);
}

void PCA9557::setPolarityInversion(uint8_t groupValue)
{
  writeI2c(PCA9557Address, polarityInversionP0, groupValue);
}

uint8_t PCA9557::readConfiguration()
{
  writeI2c(PCA9557Address, configurationP0);
  return readI2c(PCA9557Address);
}

void PCA9557::setConfiguration(uint8_t configuration)
{
  writeI2c(PCA9557Address, configurationP0, configuration);
}
