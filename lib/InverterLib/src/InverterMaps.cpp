#include "InverterMaps.h"

static const ModbusInverterMap map_SIW400G_T075_W0 = {
    // Identificação
    { 0x9C75, ASCII, 16, 1, 1.0f, true, false }, // Serial. Scale é ignorado para ASCII; usar 1.0f apenas como valor neutro
    // Controle
    { 0xA717, U16, 1, 1, 1.0f, true, true },     // Boot. CE - Shutdown, CF - Boot
    { 0x9D6C, U16, 1, 1, 1.0f, true, true },     // Enable Power Limit (0 - Disable, 1 - Enable)
    INVALID_FIELD,                               // Set Power Limit (W) (não disponível nesse modelo)
    { 0x9D6D, U16, 1, 1, 0.1f, true, true },     // Set Power Limit Percent (%)
    { 0xA887, U16, 1, 1, 1.0f, true, true },     // Enable Export Limit (55 - Disable, AA - Enable)
    INVALID_FIELD,                               // Set Export Limit (W) (não disponível nesse modelo)
    { 0xA889, U16, 1, 1, 0.1f, true, true },     // Set Export Limit Percent(%)
    { 0x9D68, U16, 1, 1, 1.0f, true, true },     // Enable Power Factor (0 - Disable, 1 - Enable)
    { 0x9D74, U16, 1, 1, 0.001f, true, true },   // Set Power Factor
    { 0x9D75, U16, 1, 1, 1.0f, true, true },     // Power Factor Excitation Mode (0 - Inductive, 1 - Capacitive)
    // Tempo
    { 0xA710, U16, 1, 1, 1.0f, true, false },     // Time Year
    { 0xA711, U16, 1, 1, 1.0f, true, false },     // Time Month
    { 0xA712, U16, 1, 1, 1.0f, true, false },     // Time Day
    { 0xA713, U16, 1, 1, 1.0f, true, false },     // Time Hour
    { 0xA714, U16, 1, 1, 1.0f, true, false },     // Time Minute
    { 0xA715, U16, 1, 1, 1.0f, true, false },     // Time Second
    INVALID_FIELD,                                // Time Epoch (não disponível nesse modelo)
    // Status
    { 0x9C95, U64, 1, 4, 100.0f, true, false },   // Total Energy (Wh)
    INVALID_FIELD,                                // Daily Energy (Wh) (não disponível nesse modelo)    

    { 0x9C8F, I16, 1, 1, 100.0f, true, false },   // Active Power (kW)
    { 0x9C90, I16, 1, 1, 100.0f, true, false },   // Apparent Power (kVA)
    { 0x9C91, I16, 1, 1, 100.0f, true, false },   // Reactive Power (kVAr)
    { 0x9C92, I16, 1, 1, 0.001f, true, false },   // Power Factor

    { 0x9C9B, U16, 3, 3, 0.1f, true, false },     // Grid Voltage R, S, T (V)
    { 0x9C9A, I16, 3, 3, 0.1f, true, false },     // Grid Current R, S, T (A)
    { 0x9C93, U32, 1, 2, 0.01f, true, false },    // Frequency (Hz)

    { 0x9C99, I16, 1, 1, 0.1f, true, false },     // Temperature (°C)
    { 0xA00E, U16, 1, 1, 1.0f, true, false },     // Insulation Resistance (kΩ)
    { 0x9C8B, U16, 1, 1, 1.0f, true, false },     // Inverter Status
    { 0x9C8D, U32, 1, 2, 1.0f, true, false },     // Alarm

    { 0xA019, U16, 18, 2, 1.0f, true, false },    // String Voltage (V)
    { 0xA01A, U16, 18, 2, 0.01f, true, false },   // String Current (A)
    INVALID_FIELD,                                // String Power (W) (não disponível nesse modelo)

    INVALID_FIELD,                                // Battery Voltage (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Current (A) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Power (W) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Charge (%) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Voltage R, S, T (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Current R, S, T(A) (não disponível nesse modelo)
    INVALID_FIELD                                 // EPS Active Power (W) (não disponível nesse modelo)
};

static const ModbusInverterMap map_SIW400G_T100_W0 = {
    // Identificação
    { 0x9C75, ASCII, 16, 1, 1.0f, true, false }, // Serial. Scale é ignorado para ASCII; usar 1.0f apenas como valor neutro
    // Controle
    { 0xA717, U16, 1, 1, 1.0f, true, true },     // Boot. CE - Shutdown, CF - Boot
    { 0x9D6C, U16, 1, 1, 1.0f, true, true },     // Enable Power Limit (0 - Disable, 1 - Enable)
    INVALID_FIELD,                               // Set Power Limit (W) (não disponível nesse modelo)
    { 0x9D6D, U16, 1, 1, 0.1f, true, true },     // Set Power Limit Percent (%)
    { 0xA887, U16, 1, 1, 1.0f, true, true },     // Enable Export Limit (55 - Disable, AA - Enable)
    INVALID_FIELD,                               // Set Export Limit (W) (não disponível nesse modelo)
    { 0xA889, U16, 1, 1, 0.1f, true, true },     // Set Export Limit Percent(%)
    { 0x9D68, U16, 1, 1, 1.0f, true, true },     // Enable Power Factor (0 - Disable, 1 - Enable)
    { 0x9D74, U16, 1, 1, 0.001f, true, true },   // Set Power Factor
    { 0x9D75, U16, 1, 1, 1.0f, true, true },     // Power Factor Excitation Mode (0 - Inductive, 1 - Capacitive)
    // Tempo
    { 0xA710, U16, 1, 1, 1.0f, true, false },     // Time Year
    { 0xA711, U16, 1, 1, 1.0f, true, false },     // Time Month
    { 0xA712, U16, 1, 1, 1.0f, true, false },     // Time Day
    { 0xA713, U16, 1, 1, 1.0f, true, false },     // Time Hour
    { 0xA714, U16, 1, 1, 1.0f, true, false },     // Time Minute
    { 0xA715, U16, 1, 1, 1.0f, true, false },     // Time Second
    INVALID_FIELD,                                // Time Epoch (não disponível nesse modelo)
    // Status
    { 0x9C95, U64, 1, 4, 100.0f, true, false },   // Total Energy (Wh)
    INVALID_FIELD,                                // Daily Energy (Wh) (não disponível nesse modelo)    

    { 0x9C8F, I16, 1, 1, 100.0f, true, false },   // Active Power (kW)
    { 0x9C90, I16, 1, 1, 100.0f, true, false },   // Apparent Power (kVA)
    { 0x9C91, I16, 1, 1, 100.0f, true, false },   // Reactive Power (kVAr)
    { 0x9C92, I16, 1, 1, 0.001f, true, false },   // Power Factor

    { 0x9C9B, U16, 3, 3, 0.1f, true, false },     // Grid Voltage R, S, T (V)
    { 0x9C9A, I16, 3, 3, 0.1f, true, false },     // Grid Current R, S, T (A)
    { 0x9C93, U32, 1, 2, 0.01f, true, false },    // Frequency (Hz)

    { 0x9C99, I16, 1, 1, 0.1f, true, false },     // Temperature (°C)
    { 0xA00E, U16, 1, 1, 1.0f, true, false },     // Insulation Resistance (kΩ)
    { 0x9C8B, U16, 1, 1, 1.0f, true, false },     // Inverter Status
    { 0x9C8D, U32, 1, 2, 1.0f, true, false },     // Alarm

    { 0xA019, U16, 18, 2, 1.0f, true, false },    // String Voltage (V)
    { 0xA01A, U16, 18, 2, 0.01f, true, false },   // String Current (A)
    INVALID_FIELD,                                // String Power (W) (não disponível nesse modelo)

    INVALID_FIELD,                                // Battery Voltage (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Current (A) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Power (W) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Charge (%) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Voltage R, S, T (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Current R, S, T(A) (não disponível nesse modelo)
    INVALID_FIELD                                 // EPS Active Power (W) (não disponível nesse modelo)
};

static const ModbusInverterMap map_R75 = {
    // Identificação
    { 0x9C75, ASCII, 16, 1, 1.0f, true, false }, // Serial. Scale é ignorado para ASCII; usar 1.0f apenas como valor neutro
    // Controle
    { 0xA717, U16, 1, 1, 1.0f, true, true },     // Boot. CE - Shutdown, CF - Boot
    { 0x9D6C, U16, 1, 1, 1.0f, true, true },     // Enable Power Limit (0 - Disable, 1 - Enable)
    INVALID_FIELD,                               // Set Power Limit (W) (não disponível nesse modelo)
    { 0x9D6D, U16, 1, 1, 0.1f, true, true },     // Set Power Limit Percent (%)
    { 0xA887, U16, 1, 1, 1.0f, true, true },     // Enable Export Limit (55 - Disable, AA - Enable)
    INVALID_FIELD,                               // Set Export Limit (W) (não disponível nesse modelo)
    { 0xA889, U16, 1, 1, 0.1f, true, true },     // Set Export Limit Percent(%)
    { 0x9D68, U16, 1, 1, 1.0f, true, true },     // Enable Power Factor (0 - Disable, 1 - Enable)
    { 0x9D74, U16, 1, 1, 0.001f, true, true },   // Set Power Factor
    { 0x9D75, U16, 1, 1, 1.0f, true, true },     // Power Factor Excitation Mode (0 - Inductive, 1 - Capacitive)
    // Tempo
    { 0xA710, U16, 1, 1, 1.0f, true, false },     // Time Year
    { 0xA711, U16, 1, 1, 1.0f, true, false },     // Time Month
    { 0xA712, U16, 1, 1, 1.0f, true, false },     // Time Day
    { 0xA713, U16, 1, 1, 1.0f, true, false },     // Time Hour
    { 0xA714, U16, 1, 1, 1.0f, true, false },     // Time Minute
    { 0xA715, U16, 1, 1, 1.0f, true, false },     // Time Second
    INVALID_FIELD,                                // Time Epoch (não disponível nesse modelo)
    // Status
    { 0x9C95, U64, 1, 4, 100.0f, true, false },   // Total Energy (Wh)
    INVALID_FIELD,                                // Daily Energy (Wh) (não disponível nesse modelo)    

    { 0x9C8F, I16, 1, 1, 100.0f, true, false },   // Active Power (kW)
    { 0x9C90, I16, 1, 1, 100.0f, true, false },   // Apparent Power (kVA)
    { 0x9C91, I16, 1, 1, 100.0f, true, false },   // Reactive Power (kVAr)
    { 0x9C92, I16, 1, 1, 0.001f, true, false },   // Power Factor

    { 0x9C9B, U16, 3, 3, 0.1f, true, false },     // Grid Voltage R, S, T (V)
    { 0x9C9A, I16, 3, 3, 0.1f, true, false },     // Grid Current R, S, T (A)
    { 0x9C93, U32, 1, 2, 0.01f, true, false },    // Frequency (Hz)

    { 0x9C99, I16, 1, 1, 0.1f, true, false },     // Temperature (°C)
    { 0xA00E, U16, 1, 1, 1.0f, true, false },     // Insulation Resistance (kΩ)
    { 0x9C8B, U16, 1, 1, 1.0f, true, false },     // Inverter Status
    { 0x9C8D, U32, 1, 2, 1.0f, true, false },     // Alarm

    { 0xA019, U16, 18, 2, 1.0f, true, false },    // String Voltage (V)
    { 0xA01A, U16, 18, 2, 0.01f, true, false },   // String Current (A)
    INVALID_FIELD,                                // String Power (W) (não disponível nesse modelo)

    INVALID_FIELD,                                // Battery Voltage (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Current (A) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Power (W) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Charge (%) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Voltage R, S, T (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Current R, S, T(A) (não disponível nesse modelo)
    INVALID_FIELD                                 // EPS Active Power (W) (não disponível nesse modelo)
};

static const ModbusInverterMap map_R100 = {
    // Identificação
    { 0x9C75, ASCII, 16, 1, 1.0f, true, false }, // Serial. Scale é ignorado para ASCII; usar 1.0f apenas como valor neutro
    // Controle
    { 0xA717, U16, 1, 1, 1.0f, true, true },     // Boot. CE - Shutdown, CF - Boot
    { 0x9D6C, U16, 1, 1, 1.0f, true, true },     // Enable Power Limit (0 - Disable, 1 - Enable)
    INVALID_FIELD,                               // Set Power Limit (W) (não disponível nesse modelo)
    { 0x9D6D, U16, 1, 1, 0.1f, true, true },     // Set Power Limit Percent (%)
    { 0xA887, U16, 1, 1, 1.0f, true, true },     // Enable Export Limit (55 - Disable, AA - Enable)
    INVALID_FIELD,                               // Set Export Limit (W) (não disponível nesse modelo)
    { 0xA889, U16, 1, 1, 0.1f, true, true },     // Set Export Limit Percent(%)
    { 0x9D68, U16, 1, 1, 1.0f, true, true },     // Enable Power Factor (0 - Disable, 1 - Enable)
    { 0x9D74, U16, 1, 1, 0.001f, true, true },   // Set Power Factor
    { 0x9D75, U16, 1, 1, 1.0f, true, true },     // Power Factor Excitation Mode (0 - Inductive, 1 - Capacitive)
    // Tempo
    { 0xA710, U16, 1, 1, 1.0f, true, false },     // Time Year
    { 0xA711, U16, 1, 1, 1.0f, true, false },     // Time Month
    { 0xA712, U16, 1, 1, 1.0f, true, false },     // Time Day
    { 0xA713, U16, 1, 1, 1.0f, true, false },     // Time Hour
    { 0xA714, U16, 1, 1, 1.0f, true, false },     // Time Minute
    { 0xA715, U16, 1, 1, 1.0f, true, false },     // Time Second
    INVALID_FIELD,                                // Time Epoch (não disponível nesse modelo)
    // Status
    { 0x9C95, U64, 1, 4, 100.0f, true, false },   // Total Energy (Wh)
    INVALID_FIELD,                                // Daily Energy (Wh) (não disponível nesse modelo)    

    { 0x9C8F, I16, 1, 1, 100.0f, true, false },   // Active Power (kW)
    { 0x9C90, I16, 1, 1, 100.0f, true, false },   // Apparent Power (kVA)
    { 0x9C91, I16, 1, 1, 100.0f, true, false },   // Reactive Power (kVAr)
    { 0x9C92, I16, 1, 1, 0.001f, true, false },   // Power Factor

    { 0x9C9B, U16, 3, 3, 0.1f, true, false },     // Grid Voltage R, S, T (V)
    { 0x9C9A, I16, 3, 3, 0.1f, true, false },     // Grid Current R, S, T (A)
    { 0x9C93, U32, 1, 2, 0.01f, true, false },    // Frequency (Hz)

    { 0x9C99, I16, 1, 1, 0.1f, true, false },     // Temperature (°C)
    { 0xA00E, U16, 1, 1, 1.0f, true, false },     // Insulation Resistance (kΩ)
    { 0x9C8B, U16, 1, 1, 1.0f, true, false },     // Inverter Status
    { 0x9C8D, U32, 1, 2, 1.0f, true, false },     // Alarm

    { 0xA019, U16, 18, 2, 1.0f, true, false },    // String Voltage (V)
    { 0xA01A, U16, 18, 2, 0.01f, true, false },   // String Current (A)
    INVALID_FIELD,                                // String Power (W) (não disponível nesse modelo)

    INVALID_FIELD,                                // Battery Voltage (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Current (A) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Power (W) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Charge (%) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Voltage R, S, T (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Current R, S, T(A) (não disponível nesse modelo)
    INVALID_FIELD                                 // EPS Active Power (W) (não disponível nesse modelo)
};

struct ModbusField {
    uint16_t address;
    ModbusDataType type;
    uint16_t length; // Número de registradores (16 bits cada)
    uint16_t stride; // Número de registradores entre os campos (para arrays)
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
    ModbusField operationStatus;

    ModbusField stringVoltage;
    ModbusField stringCurrent;
    ModbusField stringPower;

    //ModbusField batteryVoltage;
    //ModbusField batteryCurrent;
    //ModbusField batteryPower;
    //ModbusField batteryCharge;

    //ModbusField epsVoltage;

    //ModbusField epsCurrent;
    //ModbusField epsActivePower;

static const ModbusInverterMap mapGW3000_XS = {
    { 0x1100, U16, 1.0f, true, false }, // regPotenciaAtual
    { 0x1200, U16, 1.0f, true, true },  // regSetMaxPotencia
    { 0x1300, U16, 1.0f, true, false }, // regTensaoRede
    { 0x1400, U16, 1.0f, true, false }  // regCorrenteRede
};

const ModbusInverterMap* getInverterMap(InverterModel model) {
    switch (model) {
        case SIW400G_T075_W0:
            return &map_SIW400G_T075_W0;
        case SIW400G_T100_W0:
            return &map_SIW400G_T100_W0;
        case R75:
            return &map_R75;
        case R100:
            return &map_R100;
            
        case UNKNOWN_INVERTER:
            return nullptr;
        default:
            return nullptr;
    }
}