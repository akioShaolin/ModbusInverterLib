#ifndef MODBUS_CONFIG_H
#define MODBUS_CONFIG_H

#include <Arduino.h>

class ModbusConfig {
public:
    ModbusConfig();

    void setConfig(uint8_t id, uint32_t baud);
    void setConfig(uint8_t id, uint32_t baud, uint8_t dataBits, uint8_t parity, uint8_t stopBits);

    void setId(uint8_t id);
    void setBaud(uint32_t baud);
    void setDataBits(uint8_t dataBits);
    void setParity(uint8_t parity);
    void setStopBits(uint8_t stopBits);
    
    uint8_t getId() const;
    uint32_t getBaud() const;
    uint8_t getDataBits() const;
    uint8_t getParity() const;
    uint8_t getStopBits() const;

private:
    uint8_t _id;
    uint32_t _baud;
    uint8_t _dataBits;
    uint8_t _parity;
    uint8_t _stopBits;
};

#endif