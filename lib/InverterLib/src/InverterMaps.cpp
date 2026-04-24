#include "InverterMaps.h"

// ------------------------------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------- WEG ------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------------------------

static const ModbusInverterMap map_SIW400 = {
    // Identificação
    { 0x0200, ASCII, 8, 1, 1.0f, true, false },   // Serial. Scale é ignorado para ASCII; usar 1.0f apenas como valor neutro
    // Controle
    { 0x0120, U16, 1, 1, 1.0f, false, true },     // Boot. Write 0
    { 0x0121, U16, 1, 1, 1.0f, false, true },     // Shutdown. Write 0
    INVALID_FIELD,                                // Enable Power Limit (Não disponível nesse modelo)
    INVALID_FIELD,                                // Set Power Limit (W) (não disponível nesse modelo)
    { 0x0100, U16, 1, 1, 1.0f, true, true },      // Set Power Limit Percent (%)
    { 0x0123, U16, 1, 1, 1.0f, true, true },      // Enable Export Limit (0-Off, 1-On)
    INVALID_FIELD,                                // Set Export Limit (W) (não disponível nesse modelo)
    { 0x0124, U16, 1, 1, 0.1f, true, true },      // Set Export Limit Percent(%)
    INVALID_FIELD,                                // Enable Power Factor (Não disponível nesse modelo)
    { 0x0101, U16, 1, 1, 1.0f, true, true },      // Set Power Factor % [1, 20] LAGGING, [80, 100] LEADING
    INVALID_FIELD,                                // Power Factor Excitation Mode (Não disponível nesse modelo)
    // Tempo
    { 0x033B, U16, 1, 1, 1.0f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },     // Time Year MSB
    { 0x033B, U16, 1, 1, 1.0f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },     // Time Month LSB
    { 0x033C, U16, 1, 1, 1.0f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },     // Time Day MSB
    { 0x033C, U16, 1, 1, 1.0f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },     // Time Hour LSB
    { 0x033D, U16, 1, 1, 1.0f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },     // Time Minute MSB
    { 0x033D, U16, 1, 1, 1.0f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },     // Time Second LSB
    INVALID_FIELD,                                // Time Epoch (não disponível nesse modelo)
    // Status
    { 0x0312, U32, 1, 1, 0.1f, true, false },     // Total Energy (kWh) - MSB em 0x0222 e LSB em 0x0223 
    { 0x0320, U16, 1, 1, 0.1f, true, false },     // Daily Energy (kWh)  

    { 0x0352, U32, 1, 1, 1.0f, true, false },     // Active Power (W)
    INVALID_FIELD,                                // Apparent Power (kVA) (não disponível nesse modelo)
    { 0x037d, U32, 1, 1, 0.001f, true, false },   // Reactive Power (kVAr)
    { 0x0376, U16, 1, 1, 0.001f, true, false },   // Power Factor

    { 0x0304, U16, 3, 1, 0.1f, true, false },     // Grid Voltage R, S, T (V)
    { 0x0307, U16, 3, 1, 0.1f, true, false },     // Grid Current R, S, T (A)
    { 0x030A, U16, 3, 1, 0.01f, true, false },    // Frequency (Hz)

    { 0x030F, U16, 1, 1, 0.1f, true, false },     // Temperature (°C)
    { 0x037F, U16, 1, 1, 1.0f, true, false },     // Insulation Resistance (kΩ)
    { 0x030E, U16, 1, 1, 1.0f, true, false },     // Inverter Status
    { 0x0310, U16, 2, 1, 1.0f, true, false },     // Alarm

    { 0x0300, U16, 1, 2, 0.1f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },    // String Voltage (V) Reg 0x0357 e 0x0358 para MPPTs 3 e 4
    { 0x035B, U16, 20, 1, 0.1f, true, false},     // String Current (A) Reg strings 1 a 20
    INVALID_FIELD,                                // String Power (W) (não disponível nesse modelo)

    INVALID_FIELD,                                // Battery Voltage (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Current (A) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Power (W) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery SoC (%) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery SoH (%) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Voltage R, S, T (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Current R, S, T (A) (não disponível nesse modelo)
    INVALID_FIELD                                 // EPS Active Power (W) (não disponível nesse modelo)
};

static const ModbusInverterMap map_SIW400G_T050_T100 = {
    // Identificação
    { 0x9C75, ASCII, 16, 1, 1.0f, true, false }, // Serial. Scale é ignorado para ASCII; usar 1.0f apenas como valor neutro
    // Controle
    { 0xA717, U16, 1, 1, 1.0f, true, true },     // Boot. CE - Shutdown, CF - Boot
    INVALID_FIELD,                               // Shutdown (Não disponível nesse modelo)
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
    { 0xA2B7, U32, 1, 2, 0.1f, true, false },     // Total Energy (kWh)
    { 0xA2B6, U16, 1, 1, 0.1f, true, false },     // Daily Energy (kWh)    

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

    { 0xA019, U16, 24, 2, 1.0f, true, false },    // String Voltage (V)
    { 0xA01A, U16, 24, 2, 0.01f, true, false },   // String Current (A)
    INVALID_FIELD,                                // String Power (W) (não disponível nesse modelo)

    INVALID_FIELD,                                // Battery Voltage (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Current (A) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Power (W) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery SoC (%) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery SoH (%) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Voltage R, S, T (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Current R, S, T (A) (não disponível nesse modelo)
    INVALID_FIELD                                 // EPS Active Power (W) (não disponível nesse modelo)
};

static const ModbusInverterMap map_SIW400H_W10 = {
    // Identificação
    { 0x9C75, ASCII, 16, 1, 1.0f, true, false }, // Serial. Scale é ignorado para ASCII; usar 1.0f apenas como valor neutro
    // Controle
    { 0xA717, U16, 1, 1, 1.0f, true, true },     // Boot. CE - Shutdown, CF - Boot
    INVALID_FIELD,                               // Shutdown (Não disponível nesse modelo)
    { 0x9D6C, U16, 1, 1, 1.0f, true, true },     // Enable Power Limit (0 - Disable, 1 - Enable)
    INVALID_FIELD,                               // Set Power Limit (W) (não disponível nesse modelo)
    { 0x9D6D, U16, 1, 1, 0.1f, true, true },     // Set Power Limit Percent (%)
    { 0xA887, U16, 1, 1, 1.0f, true, true },     // Enable Export Limit (55 - Disable, AA - Enable)
    { 0xA889, U16, 1, 1, 1.0f, true, true },     // Set Export Limit (kW)
    INVALID_FIELD,                               // Set Export Limit Percent(%) (não disponível nesse modelo)
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
    { 0xA2BB, U32, 1, 2, 0.1f, true, false },     // Total Energy (Wh)
    { 0xA2BA, U16, 1, 1, 0.1f, true, false },     // Daily Energy (Wh) (não disponível nesse modelo)    

    { 0xAA6D, I32, 1, 2, 0.001f, true, false },   // Active Power (kW)
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

    { 0xA019, U16, 24, 2, 1.0f, true, false },    // String Voltage (V)
    { 0xA01A, U16, 24, 2, 0.01f, true, false },   // String Current (A)
    INVALID_FIELD,                                // String Power (W) (não disponível nesse modelo)

    { 0xA3AA, U16, 2, 2671, 0.01f, true, false }, // Battery Voltage (V) (não disponível nesse modelo)
    { 0xA3AB, U16, 2, 2671, 0.01f, true, false }, // Battery Current (A) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Power (W) (não disponível nesse modelo)
    { 0xA3AC, U16, 2, 2671, 0.01f, true, false }, // Battery SoC (%) (não disponível nesse modelo)
    { 0xA3CB, U16, 2, 2671, 0.01f, true, false }, // Battery SoH (%) (não disponível nesse modelo)
    { 0xB1B5, U16, 3, 1, 0.1f, true, false },     // EPS Voltage R, S, T (V) (não disponível nesse modelo)
    { 0xB1B8, U16, 3, 1, 0.1f, true, false },     // EPS Current R, S, T (A) (não disponível nesse modelo)
    { 0xB1BE, U32, 1, 2, 0.01f, true, false }     // EPS Active Power (W) (não disponível nesse modelo)
};

static const ModbusInverterMap map_SIW600 = {
    // Identificação
    { 0x072E, U32, 1, 1, 1.0f, true, false },    // Serial. Este modelo tem o serial em número
    // Controle
    { 0x0074, U16, 1, 1, 1.0f, true, true },     // Boot. 0 - Shutdown, 1 - Boot
    INVALID_FIELD,                               // Shutdown (Não disponível nesse modelo)
    INVALID_FIELD,                               // Enable Power Limit (Não disponível nesse modelo)
    INVALID_FIELD,                               // Set Power Limit (W) (Não disponível nesse modelo)
    { 0x0086, FLOAT32, 1, 1, 1.0f, true, true }, // Set Power Limit Percent (%)
    INVALID_FIELD,                               // Enable Export Limit (Não disponível nesse modelo)
    INVALID_FIELD,                               // Set Export Limit (W) (não disponível nesse modelo)
    INVALID_FIELD,                               // Set Export Limit Percent(%) (Não disponível nesse modelo)
    { 0x006E, U16, 1, 1, 1.0f, true, true },     // Enable Power Factor (0 - Disable, 1 - Enable)
    { 0x0070, FLOAT32, 1, 1, 1.0f, true, true }, // Set Power Factor
    { 0x0072, U16, 1, 1, 1.0f, true, true },     // Power Factor Excitation Mode (0 - Inductive, 1 - Capacitive)
    // Tempo
    { 0x0036, U16, 1, 1, 1.0f, true, false },     // Time Year (não disponível nesse modelo)
    { 0x0034, U16, 1, 1, 1.0f, true, false },     // Time Month (não disponível nesse modelo)
    { 0x0032, U16, 1, 1, 1.0f, true, false },     // Time Day (não disponível nesse modelo)
    { 0x0038, U16, 1, 1, 1.0f, true, false },     // Time Hour (não disponível nesse modelo)
    { 0x003A, U16, 1, 1, 1.0f, true, false },     // Time Minute (não disponível nesse modelo)
    { 0x003C, U16, 1, 1, 1.0f, true, false },     // Time Second (não disponível nesse modelo)
    INVALID_FIELD,                                // Time Epoch
    // Status
    { 0x001E, U32, 1, 1, 1.0f, true, false }, // Total Energy (kWh)
    INVALID_FIELD,                                // Daily Energy (Wh) (não disponível nesse modelo)    

    { 0x0008, FLOAT32, 1, 1, 1.0f, true, false }, // Active Power (kW)
    INVALID_FIELD,                                // Apparent Power (kVA)
    { 0x000A, FLOAT32, 1, 1, 1.0f, true, false }, // Reactive Power (kVAr)
    { 0x000C, FLOAT32, 1, 1, 1.0f, true, false }, // Power Factor

    { 0x0050, FLOAT32, 3, 2, 1.0f, true, false }, // Grid Voltage R, S, T (V)
    { 0x0062, FLOAT32, 3, 2, 1.0f, true, false }, // Grid Current R, S, T (A)
    { 0x0006, FLOAT32, 1, 1, 1.0f, true, false }, // Frequency (Hz)

    { 0x0018, FLOAT32, 1, 1, 1.0f, true, false }, // Temperature (°C)
    INVALID_FIELD,                                // Insulation Resistance (kΩ)
    { 0x0022, U16, 1, 1, 1.0f, true, false },     // Inverter Status
    { 0x0026, U16, 1, 1, 1.0f, true, false },     // Alarm

    { 0x005E, FLOAT32, 2, 6, 1.0f, true, false }, // String Voltage (V)
    { 0x005A, FLOAT32, 2, 6, 1.0f, true, false }, // String Current (A)
    { 0x0056, FLOAT32, 2, 6, 1.0f, true, false }, // String Power (W) (não disponível nesse modelo)

    INVALID_FIELD,                                // Battery Voltage (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Current (A) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Power (W) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery SoC (%) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery SoH (%) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Voltage R, S, T (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Current R, S, T (A) (não disponível nesse modelo)
    INVALID_FIELD                                 // EPS Active Power (W) (não disponível nesse modelo)
};

static const ModbusInverterMap map_SIW610 = {
    // Identificação
    { 0x0808, U32, 1, 1, 1.0f, true, false },    // Serial. Este modelo tem o serial em número
    // Controle
    { 0x013D, U16, 1, 1, 1.0f, true, true },     // Boot. 0 - Shutdown, 1 - Boot
    INVALID_FIELD,                               // Shutdown (Não disponível nesse modelo)
    INVALID_FIELD,                               // Enable Power Limit (Não disponível nesse modelo)
    INVALID_FIELD,                               // Set Power Limit (W) (Não disponível nesse modelo)
    { 0x0132, U16, 1, 1, 0.1f, true, true },     // Set Power Limit Percent (%)
    INVALID_FIELD,                               // Enable Export Limit (Não disponível nesse modelo)
    INVALID_FIELD,                               // Set Export Limit (W) (não disponível nesse modelo)
    INVALID_FIELD,                               // Set Export Limit Percent(%) (Não disponível nesse modelo)
    { 0x0134, U16, 1, 1, 1.0f, true, true },     // Enable Power Factor (0 - Disable, 1 - Enable)
    { 0x0136, U16, 1, 1, 0.001f, true, true },   // Set Power Factor
    { 0x0138, U16, 1, 1, 1.0f, true, true },     // Power Factor Excitation Mode (0 - Inductive, 1 - Capacitive)
    // Tempo
    INVALID_FIELD,                                // Time Year (não disponível nesse modelo)
    INVALID_FIELD,                                // Time Month (não disponível nesse modelo)
    INVALID_FIELD,                                // Time Day (não disponível nesse modelo)
    INVALID_FIELD,                                // Time Hour (não disponível nesse modelo)
    INVALID_FIELD,                                // Time Minute (não disponível nesse modelo)
    INVALID_FIELD,                                // Time Second (não disponível nesse modelo)
    { 0x03F0, U32, 1, 1, 1.0f, true, false },     // Time Epoch
    // Status
    { 0x0BE6, U32, 1, 1, 0.00001f, true, false }, // Total Energy (kWh)
    INVALID_FIELD,                                // Daily Energy (Wh) (não disponível nesse modelo)    

    { 0x0026, I32, 1, 1, 0.1f, true, false },     // Active Power (kW)
    INVALID_FIELD,                                // Apparent Power (kVA)
    { 0x0028, I16, 1, 1, 0.1f, true, false },     // Reactive Power (kVAr)
    { 0x002A, I16, 1, 1, 0.001f, true, false },   // Power Factor

    { 0x000C, U32, 3, 4, 0.1f, true, false },     // Grid Voltage R, S, T (V)
    { 0x0018, I32, 3, 4, 0.1f, true, false },     // Grid Current R, S, T (A)
    { 0x0014, U32, 1, 1, 0.01f, true, false },    // Frequency (Hz)

    { 0x07EE, I16, 1, 1, 1.0f, true, false },     // Temperature (°C)
    INVALID_FIELD,                                // Insulation Resistance (kΩ)
    { 0x0016, U16, 1, 1, 1.0f, true, false },     // Inverter Status
    { 0x0898, U16, 2, 1, 1.0f, true, false },     // Alarm

    { 0x0C1E, U16, 6, 100, 1.0f, true, false },   // String Voltage (V)
    { 0x0C20, U16, 6, 100, 1.0f, true, false },   // String Current (A)
    { 0x0C1C, U16, 6, 100, 1.0f, true, false },   // String Power (W) (não disponível nesse modelo)

    INVALID_FIELD,                                // Battery Voltage (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Current (A) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Power (W) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery SoC (%) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery SoH (%) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Voltage R, S, T (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Current R, S, T (A) (não disponível nesse modelo)
    INVALID_FIELD                                 // EPS Active Power (W) (não disponível nesse modelo)
};

// ------------------------------------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------- FOXESS -----------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------------------------

static const ModbusInverterMap map_R_series = {
    // Identificação
    { 0x9C75, ASCII, 16, 1, 1.0f, true, false }, // Serial. Scale é ignorado para ASCII; usar 1.0f apenas como valor neutro
    // Controle
    { 0xA717, U16, 1, 1, 1.0f, true, true },     // Boot. CE - Shutdown, CF - Boot
    INVALID_FIELD,                               // Shutdown (Não disponível nesse modelo)
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
    INVALID_FIELD,                                // Battery SoC (%) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery SoH (%) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Voltage R, S, T (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Current R, S, T (A) (não disponível nesse modelo)
    INVALID_FIELD                                 // EPS Active Power (W) (não disponível nesse modelo)
};

static const ModbusInverterMap map_V_series = {
    // Identificação
    { 0x9C75, ASCII, 16, 1, 1.0f, true, false }, // Serial. Scale é ignorado para ASCII; usar 1.0f apenas como valor neutro
    // Controle
    { 0xA717, U16, 1, 1, 1.0f, true, true },     // Boot. CE - Shutdown, CF - Boot
    INVALID_FIELD,                               // Shutdown (Não disponível nesse modelo)
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
    INVALID_FIELD,                                // Battery SoC (%) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery SoH (%) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Voltage R, S, T (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Current R, S, T (A) (não disponível nesse modelo)
    INVALID_FIELD                                 // EPS Active Power (W) (não disponível nesse modelo)
};

static const ModbusInverterMap map_H3P_series = {
    // Identificação
    { 0x9C75, ASCII, 16, 1, 1.0f, true, false }, // Serial. Scale é ignorado para ASCII; usar 1.0f apenas como valor neutro
    // Controle
    { 0xA717, U16, 1, 1, 1.0f, true, true },     // Boot. CE - Shutdown, CF - Boot
    INVALID_FIELD,                               // Shutdown (Não disponível nesse modelo)
    { 0x9D6C, U16, 1, 1, 1.0f, true, true },     // Enable Power Limit (0 - Disable, 1 - Enable)
    INVALID_FIELD,                               // Set Power Limit (W) (não disponível nesse modelo)
    { 0x9D6D, U16, 1, 1, 0.1f, true, true },     // Set Power Limit Percent (%)
    { 0xA887, U16, 1, 1, 1.0f, true, true },     // Enable Export Limit (55 - Disable, AA - Enable)
    { 0xA889, U16, 1, 1, 1.0f, true, true },     // Set Export Limit (kW)
    INVALID_FIELD,                               // Set Export Limit Percent(%) (não disponível nesse modelo)
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
    { 0xA2BB, U32, 1, 2, 0.1f, true, false },     // Total Energy (Wh)
    { 0xA2BA, U16, 1, 1, 0.1f, true, false },     // Daily Energy (Wh) (não disponível nesse modelo)    

    { 0xAA6D, I32, 1, 2, 0.001f, true, false },   // Active Power (kW)
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

    { 0xA019, U16, 24, 2, 1.0f, true, false },    // String Voltage (V)
    { 0xA01A, U16, 24, 2, 0.01f, true, false },   // String Current (A)
    INVALID_FIELD,                                // String Power (W) (não disponível nesse modelo)

    { 0xA3AA, U16, 2, 2671, 0.01f, true, false }, // Battery Voltage (V) (não disponível nesse modelo)
    { 0xA3AB, U16, 2, 2671, 0.01f, true, false }, // Battery Current (A) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Power (W) (não disponível nesse modelo)
    { 0xA3AC, U16, 2, 2671, 0.01f, true, false }, // Battery SoC (%) (não disponível nesse modelo)
    { 0xA3CB, U16, 2, 2671, 0.01f, true, false }, // Battery SoH (%) (não disponível nesse modelo)
    { 0xB1B5, U16, 3, 1, 0.1f, true, false },     // EPS Voltage R, S, T (V) (não disponível nesse modelo)
    { 0xB1B8, U16, 3, 1, 0.1f, true, false },     // EPS Current R, S, T (A) (não disponível nesse modelo)
    { 0xB1BE, U32, 1, 2, 0.01f, true, false }     // EPS Active Power (W) (não disponível nesse modelo)
};

// ------------------------------------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------- GOODWE -----------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------------------------

static const ModbusInverterMap map_GOODWE_NON_MT = {
    // Identificação
    { 0x0200, ASCII, 8, 1, 1.0f, true, false }, // Serial. Scale é ignorado para ASCII; usar 1.0f apenas como valor neutro
    // Controle
    { 0x0120, U16, 1, 1, 1.0f, false, true },     // Boot. Write 0
    { 0x0121, U16, 1, 1, 1.0f, false, true },     // Shutdown. Write 0
    INVALID_FIELD,                                // Enable Power Limit (Não disponível nesse modelo)
    INVALID_FIELD,                                // Set Power Limit (W) (não disponível nesse modelo)
    { 0x0100, U16, 1, 1, 1.0f, true, true },      // Set Power Limit Percent (%)
    { 0x0123, U16, 1, 1, 1.0f, true, true },      // Enable Export Limit (0-Off, 1-On)
    INVALID_FIELD,                                // Set Export Limit (W) (não disponível nesse modelo)
    { 0x0124, U16, 1, 1, 0.1f, true, true },      // Set Export Limit Percent(%)
    INVALID_FIELD,                                // Enable Power Factor (Não disponível nesse modelo)
    { 0x0101, U16, 1, 1, 1.0f, true, true },      // Set Power Factor % [1, 20] LAGGING, [80, 100] LEADING
    INVALID_FIELD,                                // Power Factor Excitation Mode (Não disponível nesse modelo)
    // Tempo
    { 0x0010, U16, 1, 1, 1.0f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },     // Time Year MSB
    { 0x0010, U16, 1, 1, 1.0f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },     // Time Month LSB
    { 0x0011, U16, 1, 1, 1.0f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },     // Time Day MSB
    { 0x0011, U16, 1, 1, 1.0f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },     // Time Hour LSB
    { 0x0012, U16, 1, 1, 1.0f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },     // Time Minute MSB
    { 0x0012, U16, 1, 1, 1.0f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },     // Time Second LSB
    INVALID_FIELD,                                // Time Epoch (não disponível nesse modelo)
    // Status
    { 0x0222, U16, 2, 1, 0.1f, true, false },     // Total Energy (kWh) - MSB em 0x0222 e LSB em 0x0223 
    { 0x0236, U16, 1, 1, 0.1f, true, false },     // Daily Energy (kWh)  

    { 0x0233, U16, 1, 1, 1.0f, true, false },     // Active Power (W)
    INVALID_FIELD,                                // Apparent Power (kVA) (não disponível nesse modelo)
    INVALID_FIELD,                                // Reactive Power (kVAr) (não disponível nesse modelo)
    INVALID_FIELD,                                // Power Factor (não disponível nesse modelo)

    { 0x022A, U16, 3, 1, 0.1f, true, false },     // Grid Voltage R, S, T (V)
    { 0x022D, U16, 3, 1, 0.1f, true, false },     // Grid Current R, S, T (A)
    { 0x022F, U16, 3, 1, 0.01f, true, false },    // Frequency (Hz)

    { 0x0235, U16, 1, 1, 0.1f, true, false },     // Temperature (°C)
    INVALID_FIELD,                                // Insulation Resistance (kΩ)
    { 0x0234, U16, 1, 1, 1.0f, true, false },     // Inverter Status
    { 0x0220, U32, 1, 2, 1.0f, true, false },     // Alarm

    { 0x0226, U16, 2, 1, 0.1f, true, false },    // String Voltage (V)
    { 0x0228, U16, 2, 1, 0.1f, true, false },    // String Current (A)
    INVALID_FIELD,                               // String Power (W) (não disponível nesse modelo)

    INVALID_FIELD,                               // Battery Voltage (V) (não disponível nesse modelo)
    INVALID_FIELD,                               // Battery Current (A) (não disponível nesse modelo)
    INVALID_FIELD,                               // Battery Power (W) (não disponível nesse modelo)
    INVALID_FIELD,                               // Battery SoC (%) (não disponível nesse modelo)
    INVALID_FIELD,                               // Battery SoH (%) (não disponível nesse modelo)
    INVALID_FIELD,                               // EPS Voltage R, S, T (V) (não disponível nesse modelo)
    INVALID_FIELD,                               // EPS Current R, S, T (A) (não disponível nesse modelo)
    INVALID_FIELD                                // EPS Active Power (W) (não disponível nesse modelo)
};

static const ModbusInverterMap map_GOODWE_MT_ONLY = {
    // Identificação
    { 0x0200, ASCII, 8, 1, 1.0f, true, false },   // Serial. Scale é ignorado para ASCII; usar 1.0f apenas como valor neutro
    // Controle
    { 0x0120, U16, 1, 1, 1.0f, false, true },     // Boot. Write 0
    { 0x0121, U16, 1, 1, 1.0f, false, true },     // Shutdown. Write 0
    INVALID_FIELD,                                // Enable Power Limit (Não disponível nesse modelo)
    INVALID_FIELD,                                // Set Power Limit (W) (não disponível nesse modelo)
    { 0x0100, U16, 1, 1, 1.0f, true, true },      // Set Power Limit Percent (%)
    { 0x0123, U16, 1, 1, 1.0f, true, true },      // Enable Export Limit (0-Off, 1-On)
    INVALID_FIELD,                                // Set Export Limit (W) (não disponível nesse modelo)
    { 0x0124, U16, 1, 1, 0.1f, true, true },      // Set Export Limit Percent(%)
    INVALID_FIELD,                                // Enable Power Factor (Não disponível nesse modelo)
    { 0x0101, U16, 1, 1, 1.0f, true, true },      // Set Power Factor % [1, 20] LAGGING, [80, 100] LEADING
    INVALID_FIELD,                                // Power Factor Excitation Mode (Não disponível nesse modelo)
    // Tempo
    { 0x033B, U16, 1, 1, 1.0f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },     // Time Year MSB
    { 0x033B, U16, 1, 1, 1.0f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },     // Time Month LSB
    { 0x033C, U16, 1, 1, 1.0f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },     // Time Day MSB
    { 0x033C, U16, 1, 1, 1.0f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },     // Time Hour LSB
    { 0x033D, U16, 1, 1, 1.0f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },     // Time Minute MSB
    { 0x033D, U16, 1, 1, 1.0f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },     // Time Second LSB
    INVALID_FIELD,                                // Time Epoch (não disponível nesse modelo)
    // Status
    { 0x0312, U32, 1, 1, 0.1f, true, false },     // Total Energy (kWh) - MSB em 0x0222 e LSB em 0x0223 
    { 0x0320, U16, 1, 1, 0.1f, true, false },     // Daily Energy (kWh)  

    { 0x0352, U32, 1, 1, 1.0f, true, false },     // Active Power (W)
    INVALID_FIELD,                                // Apparent Power (kVA) (não disponível nesse modelo)
    { 0x037d, U32, 1, 1, 0.001f, true, false },   // Reactive Power (kVAr)
    { 0x0376, U16, 1, 1, 0.001f, true, false },   // Power Factor

    { 0x0304, U16, 3, 1, 0.1f, true, false },     // Grid Voltage R, S, T (V)
    { 0x0307, U16, 3, 1, 0.1f, true, false },     // Grid Current R, S, T (A)
    { 0x030A, U16, 3, 1, 0.01f, true, false },    // Frequency (Hz)

    { 0x030F, U16, 1, 1, 0.1f, true, false },     // Temperature (°C)
    { 0x037F, U16, 1, 1, 1.0f, true, false },     // Insulation Resistance (kΩ)
    { 0x030E, U16, 1, 1, 1.0f, true, false },     // Inverter Status
    { 0x0310, U16, 2, 1, 1.0f, true, false },     // Alarm

    { 0x0300, U16, 1, 2, 0.1f, true, false, FIELD_SPECIAL, GOODWE_HANDLER },    // String Voltage (V) Reg 0x0357 e 0x0358 para MPPTs 3 e 4
    { 0x035B, U16, 20, 1, 0.1f, true, false},     // String Current (A) Reg strings 1 a 20
    INVALID_FIELD,                                // String Power (W) (não disponível nesse modelo)

    INVALID_FIELD,                                // Battery Voltage (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Current (A) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery Power (W) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery SoC (%) (não disponível nesse modelo)
    INVALID_FIELD,                                // Battery SoH (%) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Voltage R, S, T (V) (não disponível nesse modelo)
    INVALID_FIELD,                                // EPS Current R, S, T (A) (não disponível nesse modelo)
    INVALID_FIELD                                 // EPS Active Power (W) (não disponível nesse modelo)
};

const ModbusInverterMap* getInverterMap(InverterModel model) {
    switch (model) {
        // Weg
        case SIW400_ST075:
            return &map_SIW400;
        case SIW400G_K015_W00:
            return &map_SIW400G_T050_T100;            
        case SIW400G_K020_W00:
            return &map_SIW400G_T050_T100;  
        case SIW400G_K025_W00:
            return &map_SIW400G_T050_T100;  
        case SIW400G_K030_W00:
            return &map_SIW400G_T050_T100;          
        case SIW400G_K037_W00:
            return &map_SIW400G_T050_T100;  
        case SIW400G_T050_W00:
            return &map_SIW400G_T050_T100;
        case SIW400G_T060_W00:
            return &map_SIW400G_T050_T100;
        case SIW400G_T075_W0:
            return &map_SIW400G_T050_T100;
        case SIW400G_T075_W01:
            return &map_SIW400G_T050_T100;
        case SIW400G_T100_W0:
            return &map_SIW400G_T050_T100;
        case SIW400H_T015_W10:
            return &map_SIW400H_W10;
        case SIW400H_T030_W10:
            return &map_SIW400H_W10;

        // Goodwe
        case GW3000_XS:
            return &map_GOODWE_NON_MT;
        case GW3300_XS_30:
            return &map_GOODWE_NON_MT;
        case GW5000_DNS:
            return &map_GOODWE_NON_MT;
        case GW5K_DNS_G40:
            return &map_GOODWE_NON_MT;

        // Foxess
        case V30:
            return &map_V_series;
        case V33:
            return &map_V_series;
        case V36:
            return &map_V_series;
        case V40:
            return &map_V_series;
        case V50:
            return &map_V_series;
        case V60:
            return &map_V_series;
        case V75:
            return &map_V_series;
        case VL15:
            return &map_V_series;
        case VL20:
            return &map_V_series;
        case VL25:
            return &map_V_series;
        case VL30:
            return &map_V_series;
        case VL37_5:
            return &map_V_series;
        case R75:
            return &map_R_series;
        case R100:
            return &map_R_series;
        case R110:
            return &map_R_series;
            
        case UNKNOWN_INVERTER:
            return nullptr;
        default:
            return nullptr;
    }
}