
#pragma once
#include <types.h>
#include <port/port.h>

void printf(uint8_t* ltr, int flag);   
class ata
{
protected:
    bool master;
    Port16Bit dataPort;
    Port8Bit errorPort;
    Port8Bit sectorCountPort;
    Port8Bit lbaLowPort;
    Port8Bit lbaMidPort;
    Port8Bit lbaHiPort;
    Port8Bit devicePort;
    Port8Bit commandPort;
    Port8Bit controlPort;
public:
    
    ata(bool master, uint16_t portBase);
    ~ata();
    
    void Identify();
    void Read28(uint32_t sectorNum, int count = 512, uint8_t* ptr=nullptr);
    void Write28(uint32_t sectorNum, uint8_t* data, uint32_t count);
    void Flush();
    
    
};


