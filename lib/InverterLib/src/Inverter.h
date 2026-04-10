#ifndef INVERTER_H
#define INVERTER_H

#include <Arduino.h>
#include "ModbusConfig.h"
#include "InverterMaps.h"
#include "InverterDescriptor.h"
#include "InverterModels.h"

struct Voltage {
    float r;
    float s;
    float t;
};

struct Current {
    float r;
    float s;
    float t;
};

struct Grid {
    uint8_t phaseCount; // 1 para monofásico, 3 para trifásico
    float frequency;
    Voltage voltage;
    Current current;
    float activePower;
    float reactivePower;
    float apparentPower;
    float powerFactor;
};

struct EPS {
    uint8_t phaseCount; // 1 para monofásico, 3 para trifásico
    Voltage voltage;
    Current current;
    float activePower;
    float reactivePower;
    float apparentPower;
    float powerFactor;
};

struct String {
    uint8_t count; // Número de strings ativas
    float voltage[MAX_STRINGS];
    float current[MAX_STRINGS];
    float power[MAX_STRINGS];
};

class Inverter {
public:
    ModbusConfig modbus;

    Inverter(InverterModel model);

    bool getSerialNumber(char* buffer, size_t bufferSize);
    bool getBoot();
    bool getPowerLimitEnabled();
    float getPowerLimit();
    float getPowerLimitPercent();
    bool getExportLimitEnabled();
    float getExportLimit();
    bool getPowerFactorEnabled();
    float getPowerFactorSetpoint();

    bool setBoot(bool boot);
    bool enablePowerLimit(bool enable);
    bool setPowerLimit(uint16_t watts);
    bool setPowerLimitPercent(float percent);
    bool enableExportLimit(bool enable);
    bool setExportLimit(uint16_t watts);
    bool enablePowerFactor(bool enable);
    bool setPowerFactor(float pf);

    Datetime getTime();

    float getPower();
    float getReactivePower();
    float getApparentPower();
    float getPowerFactor();

    float getEnergyToday();
    float getTotalEnergy();
    
    Voltage getGridVoltage(Grid grid);
    Current getGridCurrent(Grid grid);

    float getGridFrequency();

    float getTemperature();
    float getInsulationResistance();
    uint16_t getOperationStatus();

    float getBatteryVoltage();
    float getBatteryCurrent();
    float getBatteryPower();
    float getBatteryCharge();
    
    float getEPSVoltageR();
    float getEPSVoltageS();
    float getEPSVoltageT();
    float getEPSCurrentR();
    float getEPSCurrentS();
    float getEPSCurrentT();
    float getEPSActivePower();

    float getStringVoltage();
    float getStringCurrent();
    float getStringPower();

        // Controle
    ModbusField boot;
    ModbusField enablePowerLimit;
    ModbusField setPowerLimit;
    ModbusField setPowerLimitPercent;
    ModbusField enableExportLimit;
    ModbusField setExportLimit;
    ModbusField enablePowerFactor;
    ModbusField setPowerFactor;

private:
    InverterModel _model;
    const InverterDescriptor _descriptor;

    Grid _grid;
    EPS _eps;
    const ModbusInverterMap* _map;

    float readField(const ModbusField& field);
    bool writeField(const ModbusField& field, float value);

    uint16_t readHoldingRegister(uint16_t reg);
    bool writeHoldingRegister(uint16_t reg, uint16_t value);
};

#endif