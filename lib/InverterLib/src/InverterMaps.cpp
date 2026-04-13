#include "InverterMaps.h"

static const ModbusInverterMap mapSIW400G_T075_W0 = {
    { 0x9C75, ASCII, 16, 1, 1.0f, true, false }, // Serial. Utilizar 1.0f em scale para indicar que o valor é lido como string ASCII
    { 0xA717, U16, 1, 1, 1.0f, true, true },  // Boot. CE - Shutdown, CF - Boot
    { 0x9D6C, U16, 1, 1, 1.0f, true, true },  // Enable Power Limit (0 - Disable, 1 - Enable)
    { 0x9D6D, U16, 1, 1, 0.1f, true, true },  // Set Power Limit Percent (%)
    { 0xA887, U16, 1, 1, 1.0f, true, true },  // Enable Export Limit (55 - Disable, AA - Enable)
    { 0xA889, U16, 1, 1, 0.1f, true, true },  // Set Export Limit Percent(%)
    { 0x9D68, U16, 1, 1, 1.0f, true, true },  // Enable Power Factor (0 - Disable, 1 - Enable)
    { 0x9D74, U16, 1, 1, 0.001f, true, true }, // Set Power Factor
    { 0x9D75, U16, 1, 1, 1.0f, true, true },  // Power Factor Excitation Mode (0 - Inductive, 1 - Capacitive)

    { 0x9C8F, U16, 1, 1, 1.0f, true, false }, // Active Power (kW)
    { 0x9C90, U16, 1, 1, 1.0f, true, false }, // Grid Voltage R (V)
    { 0x9C91, U16, 1, 1, 1.0f, true, false },   // Grid Current R (A)
};

struct ModbusField {
    uint16_t address;
    uint16_t length; // Número de registradores (16 bits cada)
    uint16_t stride; // Número de registradores entre os campos (para arrays)
    ModbusDataType type;
    float scale;
    bool read;
    bool write;
};

    // Identificação
    ModbusField serial;

    // Controle
    ModbusField boot;
    ModbusField enablePowerLimit;
    ModbusField setPowerLimit;
    ModbusField setPowerLimitPercent;
    ModbusField enableExportLimit;
    ModbusField setExportLimit;
    ModbusField enablePowerFactor;
    ModbusField setPowerFactor;
    ModbusField powerFactorExcitationMode;

    // Tempo
    ModbusField time_year;
    ModbusField time_month;
    ModbusField time_day;
    ModbusField time_hour;
    ModbusField time_minute;
    ModbusField time_second;
    ModbusField time_epoch;

    // Status
    ModbusField activePower;
    ModbusField reactivePower;
    ModbusField apparentPower;
    ModbusField powerFactor;

    ModbusField totalEnergy;
    ModbusField dailyEnergy;

    ModbusField gridVoltageR;
    ModbusField gridVoltageS;
    ModbusField gridVoltageT;

    ModbusField gridCurrentR;
    ModbusField gridCurrentS;
    ModbusField gridCurrentT;

    ModbusField gridFrequency;

    ModbusField temperature;
    ModbusField insulationResistance;
    ModbusField operationStatus;

    ModbusField stringVoltage;
    ModbusField stringCurrent;
    ModbusField stringPower;


static const ModbusInverterMap mapSIW400G_T100_W0 = {
    { 0x9C8F, U16, 1.0f, true, false }, // regPotenciaAtual
    { 0x9D6C, U16, 1.0f, true, true },  // regSetMaxPotencia
    { 0x9C90, U16, 1.0f, true, false }, // regTensaoRede
    { 0x9C91, U16, 1.0f, true, false }  // regCorrenteRede
};

static const ModbusInverterMap mapGW3000_XS = {
    { 0x1100, U16, 1.0f, true, false }, // regPotenciaAtual
    { 0x1200, U16, 1.0f, true, true },  // regSetMaxPotencia
    { 0x1300, U16, 1.0f, true, false }, // regTensaoRede
    { 0x1400, U16, 1.0f, true, false }  // regCorrenteRede
};

const ModbusInverterMap* getInverterMap(InverterModel model) {
    switch (model) {
        case SIW400G_T075_W0:
            return &mapSIW400G_T075_W0;
        case SIW400G_T100_W0:
            return &mapSIW400G_T100_W0;
        case GW3000_XS:
            return &mapGW3000_XS;
        case UNKNOWN_INVERTER:
            return nullptr;
        default:
            return nullptr;
    }
}