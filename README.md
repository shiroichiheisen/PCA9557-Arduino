 # PCA9557 Library

This Arduino library provides a simple interface for interacting with the PCA9557 I/O expander. It allows for easy reading and writing to the GPIOs with additional control over polarity and configuration.
 ## Usage Instructions

Initialize the library with the I2C address of your PCA9557 chip and begin communication. Optionally, start the Wire library if it hasn't been started yet.
 ```cpp 

#include <PCA9557.h> // Make sure to include the PCA9557 library at the top of your sketch

// Define the I2C address for the PCA9557
uint8_t pcaAdress = 0x20;
uint8_t pcaAdress2 = 0x21;

// Create a PCA9557 object
PCA9557 pca(pcaAdress);
PCA9557 pca(pcaAdress, 1); // Initialize the library and optionally start the Wire library

void setup() {
// Change the I2C address if necessary
pca.setAddress(pcaAdress2);
}

void loop() {
// Reading input state
uint8_t inputGpio = pca.readInputGpio();

// Reading output state
uint8_t outputGpio = pca.readOutputGpio();

// Reading polarity inversion registers
uint8_t polarityInversionGpio = pca.readPolarityInversion();

// Reading configuration registers
uint8_t configurationGpio = pca.readConfiguration();

// Writing to output
pca.writeOutputGpioGroup(uint8_t value);

// Writing to polarity inversion registers
pca.writePolarityInversionGroup(uint8_t value);

// Writing to configuration registers
pca.writeConfigurationGroup(uint8_t value);
}
 ``` 

This library abstracts the intricacies of handling the PCA9557, providing straightforward methods for managing inputs, outputs, and configurations.
