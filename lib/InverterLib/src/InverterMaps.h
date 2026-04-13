#ifndef INVERTER_MAPS_H
#define INVERTER_MAPS_H

#include <Arduino.h>
#include "InverterModels.h"

#define MAX_STRINGS 20



enum NaNValue {
    NAN_U16 = 0xFFFF,
    NAN_I16 = 0x8000,
    NAN_U32 = 0xFFFFFFFF,
    NAN_I32 = 0x80000000,
    NAN_FLOAT32 = 0x7FC00000, // Representação de NaN em float de 32 bits
    NAN_ASCII = 0xFF // Valor arbitrário para indicar NaN em ASCII
};

struct Datetime {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
};

enum ModbusDataType {
    U16,        // Unsigned 16-bit integer
    I16,        // Signed 16-bit integer
    U32,        // Unsigned 32-bit integer
    I32,        // Signed 32-bit integer
    FLOAT32,    // 32-bit floating point
    ASCII       // String ASCII (cada registrador de 16 bits representa 2 caracteres ASCII)
};

// address - endereço do primeiro registrador do primeiro elemento

// type - tipo de dado (U16, I16, U32, I32, FLOAT32, ASCII)

// length - quantidade de elementos (valores) do campo
// Ex.: 3 FLOAT32 = 3 elementos (cada um com 2 registradores)

// stride - distância, em regs, entre o inicio de um elemento e o próximo
// Ex: 
//   - Dados contínuos: stride = registradores por elemento
//   - Dados intercalados: stride > registradores por elemento

// scale - fator de escala para converter o valor lido do Modbus para a unidade correta (exceto ASCII)

struct ModbusField {
    uint16_t address;
    ModbusDataType type;
    uint16_t length; // Número de registradores (16 bits cada)
    uint16_t stride; // Número de registradores entre os campos (para arrays)
    float scale;
    bool read;
    bool write;
};

struct ModbusInverterMap {
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

    //ModbusField batteryVoltage;
    //ModbusField batteryCurrent;
    //ModbusField batteryPower;
    //ModbusField batteryCharge;

    //ModbusField epsVoltageR;
    //ModbusField epsVoltageS;
    //ModbusField epsVoltageT;

    //ModbusField epsCurrentR;
    //ModbusField epsCurrentS;
    //ModbusField epsCurrentT;
    //ModbusField epsActivePower;
    
};

const ModbusInverterMap* getInverterMap(InverterModel model);

#endif

/*

    Parametros de Identificação
    - Fabricante
    - Modelo
    - Numero de Strings
    - Numero de MPPTs
    - Monofasico/Trifasico
    - Tipo de inversor: Ongrid/Hibrido/Offgrid

    Parametros do Modbus
    - Endereço Modbus
    - Baudrate
    - Paridade
    - Stopbits

    Status
    - Numero de Serie
    - Tensão R    
    - Corrente R
    - Frequencia R
    - Potencia R
    - Tensão S    
    - Corrente S
    - Potencia S
    - Tensão T    
    - Corrente T
    - Potencia T
    - Fator de Potencia
    - Potencia Ativa
    - Potencia Reativa
    - Energia Total Gerada
    - Energia Gerada Hoje
    - Temperatura
    - Resistencia de Isolamento
    - Status de Operação []

    - Tensão de Bateria []
    - Corrente de Bateria []
    - Potencia de Bateria []
    - Carga da Bateria []

    - EPS Tensão R
    - EPS Tensão S
    - EPS Tensão T
    - EPS Corrente R
    - EPS Corrente S
    - EPS Corrente T
    - EPS Potencia Ativa
    
    - Tensão String   []
    - Corrente String []
    - Potencia String []

    Configurações
    - Boot/Shutdown
    - Tempo de Antilhamento
    - Enable/Disable Limite de potência    
    - Limite de Potencia
    - Limite de Potencia %
    - Enable/Disable Exportação de potência
    - Limite de Exportação de Potencia
    - Limite de Importacao de Potencia
    - Enable/Disable Fator de Potencia
    - Setpoint de Fator de Potencia
    - Enable/Disable Potencia Reativa
    - Limite de Potencia Reativa
    - Escrita de Registrador
    - Leitura de Registrador

*/