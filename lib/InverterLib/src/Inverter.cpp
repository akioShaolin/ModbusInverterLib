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



    // Identificação
    getSerial() // retorna uma string contendo o numero serial
    // Controle
    boot()
    boot(bool boot) // true para ligar, false para desligar
    shutdown()
    enablePowerLimit(bool enable)
    setPowerLimit(float watts)
    setPowerLimitPercent(float percent)
    enableExportLimit(bool enable)
    setExportLimit(float watts)
    setExportLimitPercent(float percent)
    enablePowerFactor(bool enable)
    setPowerFactor(float pf) // 0~1 para indutivo, 1 para unity, >1 para capacitivo

    // Tempo
    getTime()
    ModbusField time_year;
    ModbusField time_month;
    ModbusField time_day;
    ModbusField time_hour;
    ModbusField time_minute;
    ModbusField time_second;
    ModbusField time_epoch;

    // Status
    ModbusField totalEnergy;
    ModbusField dailyEnergy;

    ModbusField activePower;
    ModbusField reactivePower;
    ModbusField apparentPower;
    ModbusField powerFactor;

    ModbusField gridVoltage;
    ModbusField gridCurrent;
    ModbusField gridFrequency;

    ModbusField temperature;
    ModbusField insulationResistance;
    ModbusField inverterStatus;
    ModbusField alarm;

    ModbusField stringVoltage;
    ModbusField stringCurrent;
    ModbusField stringPower;

    ModbusField batteryVoltage;
    ModbusField batteryCurrent;
    ModbusField batteryPower;
    ModbusField batteryCharge;

    ModbusField epsVoltage;
    ModbusField epsCurrent;
    ModbusField epsActivePower;
    
};