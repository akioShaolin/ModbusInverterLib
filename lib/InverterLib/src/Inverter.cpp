#include "Inverter.h"

Inverter::Inverter(InverterModel model) : _model(model) {
    _descriptor = getDescriptor(model);
    _map = getInverterMap(model);
}

float Inverter::getPower() {
    if (_map == nullptr) return -1.0f;
    return readField(_map->regPower);
}

bool Inverter::setMaxPower(uint16_t watts) {
    if (_map == nullptr) return false;
    return writeField(_map->regMaxPower, watts);
}

// Métodos privados para leitura e escrita de campos usando o mapa do inversor
float Inverter::readField(const ModbusField& field) {
    uint16_t raw = readHoldingRegister(field.reg);
    return raw * field.scale;
}

bool Inverter::writeField(const ModbusField& field, float value) {
    uint16_t raw = (uint16_t)(value / field.scale);
    return writeHoldingRegister(field.reg, raw);
}

// Simulações de leitura e escrita de registradores Modbus

uint16_t Inverter::readHoldingRegister(uint16_t reg) {
    // Aqui entra a implementação real do Modbus
    // Por enquanto, apenas simulação
    // Serial.print("Lendo reg 0x");
    // Serial.println(reg, HEX);
    return 0x1234; // Valor simulado
}

bool Inverter::writeHoldingRegister(uint16_t reg, uint16_t value) {
    // Aqui entra a implementação real do Modbus
    // Serial.print("Escrevendo ");
    // Serial.print(value);
    // Serial.print(" no reg 0x");
    // Serial.println(reg, HEX);
    return true;
}