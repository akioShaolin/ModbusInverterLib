#include "ModbusConfig.h"

ModbusConfig::ModbusConfig() : _id(1), _baud(9600), _dataBits(8), _parity(0), _stopBits(1) {}

void ModbusConfig::setConfig(uint8_t id, uint32_t baud) {
    _id = id;
    _baud = baud;
}

void ModbusConfig::setConfig(uint8_t id, uint32_t baud, uint8_t dataBits, uint8_t parity, uint8_t stopBits) {
    _id = id;
    _baud = baud;
    _dataBits = dataBits;
    _parity = parity;
    _stopBits = stopBits;
}

void ModbusConfig::setId(uint8_t id) {
    _id = id;
}

void ModbusConfig::setBaud(uint32_t baud) {
    _baud = baud;
}

void ModbusConfig::setDataBits(uint8_t dataBits) {
    _dataBits = dataBits;
}

void ModbusConfig::setParity(uint8_t parity) {
    _parity = parity;
}

void ModbusConfig::setStopBits(uint8_t stopBits) {
    _stopBits = stopBits;
}

uint8_t ModbusConfig::getId() const {
    return _id;
}

uint32_t ModbusConfig::getBaud() const {
    return _baud;
}
uint8_t ModbusConfig::getDataBits() const {
    return _dataBits;
}

uint8_t ModbusConfig::getParity() const {
    return _parity;
}

uint8_t ModbusConfig::getStopBits() const {
    return _stopBits;
}