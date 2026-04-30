/*
 * inverterLib - Solar Inverter Library for Arduino
 * ------------------------------------------------
 * Modbus RTU (RS485)communication layer for inverter integration
 *
 * Copyright (c) 2026, Pedro Akio Sakuma
 * Licensed under BSD 3-Clause License
 */

#include "ModbusConfig.h"

ModbusConfig::ModbusConfig() : _id(1), _baud(9600), _serialConfig(SERIAL_8N1) {}

void ModbusConfig::applyTo(ModbusRTU& mb, HardwareSerial& serial) {
    // Não iniciar o modbus e o serial varias vezes. Ajustar isso aqui depois
    serial.begin(_baud, _serialConfig);

    if (_deRePin >= 0) {
        mb.begin(&serial, _deRePin);
    } else {
        mb.begin(&serial);
    }

}

void ModbusConfig::setConfig(uint8_t id, uint32_t baud) {
    _id = id;
    _baud = baud;
}

void ModbusConfig::setConfig(uint8_t id, uint32_t baud, SerialConfig config) {
    ModbusConfig::setConfig(id, baud);
    _serialConfig = config;
}

void ModbusConfig::setConfig(uint8_t id, uint32_t baud, SerialConfig config, int8_t deRePin) {
    ModbusConfig::setConfig(id, baud, config);
    _deRePin = deRePin;
}

void ModbusConfig::setId(uint8_t id) {
    _id = id;
}

void ModbusConfig::setBaud(uint32_t baud) {
    _baud = baud;
}

void ModbusConfig::setSerialConfig(SerialConfig config) {
    _serialConfig = config;
}

void ModbusConfig::setDeRePin(int8_t pin) {
    _deRePin = pin;
}

uint8_t ModbusConfig::getId() const {
    return _id;
}

uint32_t ModbusConfig::getBaud() const {
    return _baud;
}

SerialConfig ModbusConfig::getSerialConfig() const {
    return _serialConfig;
}

int8_t ModbusConfig::getDeRePin() const {
    return _deRePin;
}