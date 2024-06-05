#include <fat16/disk.h>


ata::ata(bool master, uint16_t portBase)
:   dataPort(portBase),
    errorPort(portBase + 0x1),
    sectorCountPort(portBase + 0x2),
    lbaLowPort(portBase + 0x3),
    lbaMidPort(portBase + 0x4),
    lbaHiPort(portBase + 0x5),
    devicePort(portBase + 0x6),
    commandPort(portBase + 0x7),
    controlPort(portBase + 0x206)
{
    this->master = master;
}

ata::~ata()
{
}
            
void ata::Identify()
{
    devicePort.Write(master ? 0xA0 : 0xB0);
    controlPort.Write(0);
    
    devicePort.Write(0xA0);
    uint8_t status = commandPort.Read();
    if(status == 0xFF)
        return;
    
    
    devicePort.Write(master ? 0xA0 : 0xB0);
    sectorCountPort.Write(0);
    lbaLowPort.Write(0);
    lbaMidPort.Write(0);
    lbaHiPort.Write(0);
    commandPort.Write(0xEC); // identify command
    
    
    status = commandPort.Read();
    if(status == 0x00)
        return;
    
    while(((status & 0x80) == 0x80)
       && ((status & 0x01) != 0x01))
        status = commandPort.Read();
        
    if(status & 0x01)
    {
        return;
    }

    for (uint16_t i = 0; i < 256; i++)
    {
        uint16_t data = dataPort.Read();
        char* foo = "  \0";
        foo[1] = (data >> 8) & 0x00FF;
        foo[0] = data & 0x00FF;
    }
}

void ata::Read28(uint32_t sectorNum, int count, uint8_t* ptr)
{
    if(sectorNum > 0x0FFFFFFF)
        return;
    
    devicePort.Write((master ? 0xE0 : 0xF0) | ((sectorNum >> 24) & 0x0F));
    errorPort.Write(0);
    sectorCountPort.Write(1);
    lbaLowPort.Write(sectorNum & 0x000000FF);
    lbaMidPort.Write((sectorNum & 0x0000FF00) >> 8);
    lbaHiPort.Write((sectorNum & 0x00FF0000) >> 16);
    commandPort.Write(0x20);
    
    uint8_t status = commandPort.Read();
    while (((status & 0x80) == 0x80) && ((status & 0x01) != 0x01))
        status = commandPort.Read();
        
    if (status & 0x01)
        return;
    
    for (int i = 0; i < count; i += 2)
    {
        uint16_t wdata = dataPort.Read();
        
        ptr[i] = wdata & 0xFF;
        if (i + 1 < count)
            ptr[i + 1] = (wdata >> 8) & 0xFF;
    }
    
    for (int i = count + (count % 2); i < 512; i += 2)
        dataPort.Read();
}

void ata::Write28(uint32_t sectorNum, uint8_t* data, uint32_t count)
{
    if(sectorNum > 0x0FFFFFFF)
        return;
    if(count > 512)
        return;

    // Set the drive and LBA high 4 bits
    devicePort.Write((master ? 0xE0 : 0xF0) | ((sectorNum >> 24) & 0x0F));
    
    errorPort.Write(0);
    sectorCountPort.Write(1);
    lbaLowPort.Write(sectorNum & 0xFF); // LBA low byte
    lbaMidPort.Write((sectorNum >> 8) & 0xFF); // LBA mid byte
    lbaHiPort.Write((sectorNum >> 16) & 0xFF); // LBA high byte
    commandPort.Write(0x30); // Write sectors command
    
    // Wait until the drive is ready
    uint8_t status = commandPort.Read();
    while ((status & 0x80) && !(status & 0x08)) {
        status = commandPort.Read();
    }
    
    // Write the data
    for (uint32_t i = 0; i < count; i += 2)
    {
        uint16_t wdata = data[i];
        if (i + 1 < count)
            wdata |= ((uint16_t)data[i + 1]) << 8;
        dataPort.Write(wdata);
    }
    
    // Pad remaining data with zeros if count is less than 512
    for (int i = count + (count % 2); i < 512; i += 2)
        dataPort.Write(0x0000);
}

void ata::Flush()
{
    devicePort.Write( master ? 0xE0 : 0xF0 );
    commandPort.Write(0xE7);

    uint8_t status = commandPort.Read();
    if(status == 0x00)
        return;
    
    while(((status & 0x80) == 0x80)
       && ((status & 0x01) != 0x01))
        status = commandPort.Read();
        
    if(status & 0x01)
    {
        return;
    }
}
            