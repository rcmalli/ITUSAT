//
//  ITUSAT_EEPROM.cpp
//  ITUSAT_ENERGIA
//
//  Created by Refikcan Malli on 03/05/15.
//  Copyright (c) 2015 Refikcan Malli. All rights reserved.
//

#include "ITUSAT_EEPROM.h"
#include "Wire.h"



uint8_t ITUSAT_EEPROM::readFswState()
{
    return readData(MEM_FSW_STATE);
}

uint8_t ITUSAT_EEPROM::readActiveState()
{
    return readData(MEM_ACTIVE_STATE);
}

uint8_t ITUSAT_EEPROM::readHours()
{
    return readData(MEM_TIME_HOURS);
}

uint8_t ITUSAT_EEPROM::readMinutes()
{
    return readData(MEM_TIME_MINUTES);
}


uint8_t ITUSAT_EEPROM::readSeconds()
{
    return readData(MEM_TIME_SECONDS);
}

uint8_t ITUSAT_EEPROM::readLock()
{
    return readData(MEM_EEPROM_LOCK);
}



void  ITUSAT_EEPROM::writeFswState(uint8_t data)
{
    writeData(MEM_FSW_STATE, data);
}

void  ITUSAT_EEPROM::writeActiveState(uint8_t data)
{
    writeData(MEM_ACTIVE_STATE, data);
}

void  ITUSAT_EEPROM::writeHours(uint8_t data)
{
    writeData(MEM_TIME_HOURS, data);
}

void  ITUSAT_EEPROM::writeMinutes(uint8_t data)
{
    writeData(MEM_TIME_MINUTES, data);
}

void  ITUSAT_EEPROM::writeSeconds(uint8_t data)
{
    writeData(MEM_TIME_SECONDS, data);
}

void  ITUSAT_EEPROM::writeLock(uint8_t data)
{
    writeData(MEM_EEPROM_LOCK, data);
}








uint8_t ITUSAT_EEPROM::testEEPROM()
{
    writeData(MEM_TEST_EEPROM, 5);
    uint8_t check =  readData(MEM_TEST_EEPROM);
    if (check = 5 ) {
        return 1;
    }
    else
        return 0;
}



uint8_t ITUSAT_EEPROM::readData(int address)
{
    byte rdata = 0xFF;
    Wire.beginTransmission(EEPROM_ADDRESS);
    Wire.write((int)(address >> 8));   // MSB
    Wire.write((int)(address & 0xFF)); // LSB
    Wire.endTransmission();
    
    Wire.requestFrom(EEPROM_ADDRESS,1);
    
    if (Wire.available()) rdata = Wire.read();
    
    return rdata;
}

void ITUSAT_EEPROM::writeData(int address, uint8_t value)
{
    Wire.beginTransmission(EEPROM_ADDRESS);
    Wire.write((int)(address >> 8));   // MSB
    Wire.write((int)(address & 0xFF)); // LSB
    Wire.write(value);
    Wire.endTransmission();
    delay(5);
}

ITUSAT_EEPROM EEPROM;