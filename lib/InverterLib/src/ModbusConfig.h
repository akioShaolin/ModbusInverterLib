#ifndef MODBUS_CONFIG_H
#define MODBUS_CONFIG_H

#include <Arduino.h>
#include <ModbusRTU.h>

class ModbusConfig {
public:
    ModbusConfig();

    void applyTo(ModbusRTU& mb, HardwareSerial& serial);

    void setConfig(uint8_t id, uint32_t baud);
    void setConfig(uint8_t id, uint32_t baud, SerialConfig config);
    void setConfig(uint8_t id, uint32_t baud, SerialConfig config, int8_t deRePin);

    void setId(uint8_t id);
    void setBaud(uint32_t baud);
    void setSerialConfig(SerialConfig config);
    void setDeRePin(int8_t pin);

    uint8_t getId() const;
    uint32_t getBaud() const;
    SerialConfig getSerialConfig() const;
    int8_t getDeRePin() const;

private:
    uint8_t _id;
    uint32_t _baud;
    SerialConfig _serialConfig;
    int8_t _deRePin;

    uint32_t _timeout = 1000;
};

#endif