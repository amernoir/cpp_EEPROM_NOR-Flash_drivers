/**
    * @file spi_eeprom_driver.h
    * @brief driver for SPI EEPROM and NOR flash memory
    * @details provides bit-banging SPI interface for memory devices 
*/

#pragma once 

#include <cstdint>
#include <vector>
#include <memory>

namespace MemoryDriver {
/**
    * @enum SPIMode
    * @brief SPI communication modes 
    */
enum class SPIMode {
    MODE_0 = 0, ///<CPOL=0, CPHA=0
    MODE_1 = 1, ///< CPOL=0, CPHA=1
    MODE_2 = 2, ///< CPOL=1, CPHA=0
    MODE_3 = 3, ///< CPOL=1, CPHA=1
};

/**
    * @enum MemoryType
    * @brief type of memory device 
*/

enum class MemoryType {
    EEPROM, ///< EEPROM memory (e.g 25LC040A)
    NOR_FLASH ///< NOR FLASH memory (e.g W25Q128)
};

/**
    * @enum MemoryStatus 
    * @brief Memory operation status 
*/

enum class MemoryStatus {
    SUCCESS,
    FAILURE,
    BUSY,
    PROTECTED,
    ADDRESS_INVALID,
    SIZE_INVALID,
    TIMEOUT
};

/**
    * @class ISPInterface
    * @brief abstract SPI bit-banging interface 
*/

class ISPInterface {
public:
    virtual ~ISPInterface() = default;

    /**
        * @brief initialize SPI interface 
        * @return true if successful, false otherwise
    */

    virtual bool initialize() = 0;

    /**
        * @brief set chip select line state
        * @param state true for active (low), false for inactive(high)

    */

    virtual void chipSelect(bool state) = 0;

    /**
        * @brief set clock line state 
        * @param state true for high, false for low 
    */
    
    virtual void dataOut (bool state) = 0;

     /**
        * @brief read data input line (MISO)
        * @return current state of MISO line
    */
    
     virtual bool dataIn() = 0;
    
    /**
        * @brief delay for specified microseconds
        * @param us microseconds to delay
    */
    
    virtual void delayUs(uint32_t us) = 0;
};


