#pragma once
#include "../types.h"
// this is the port communication part
// in order to receive data from I/O devices it's necessary to speak to the ports that connect them to the computer
// in reality, the cpu is connected to a PIC (programmable interrupt chip) and this PIC is connected to the physical devices - 8 specifically
// we will use this port class to communicate with the PIC, which sits at port 0x20
// each object in this class represents a connnection with a single port, with the parameter being it's number
// this class has function to read and write data to the port, depending on it's size


    class Port // basic port class
    {
    protected:
        uint16_t portnumber;
        Port(uint16_t portnumber); // constructor - specify the port address as an attribute of the class
        ~Port(); // destructor - not really necessary
    };

    class Port8Bit : public Port // a child class that specifies a 8 bit port
    {
    public:
        Port8Bit(uint16_t portnumber); // constructor destructor
        ~Port8Bit();
        virtual void Write (uint8_t data); // write to the port
        // 8 bit port so the read and write are 8 bit
        virtual uint8_t Read();

    };

    class Port8BitSlow : public Port8Bit // a child class that specifies a type 8 bit port
    {
    public:
        Port8BitSlow(uint16_t portnumber);
        ~Port8BitSlow();
        virtual void Write (uint8_t data); // only the write is different

    };



    class Port16Bit : public Port // a child class that specifies a 16 bit port
    {
    public:
        Port16Bit(uint16_t portnumber);
        ~Port16Bit();
        virtual void Write (uint16_t data);
        virtual uint16_t Read();

    };

    class Port32Bit : public Port // a child class that specifies a 32 bit port
    {
    public:
        Port32Bit(uint16_t portnumber);
        ~Port32Bit();
        virtual void Write (uint32_t data);
        virtual uint32_t Read();

    };
