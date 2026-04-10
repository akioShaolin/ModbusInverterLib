#include "InverterMaps.h"

static const ModbusInverterMap mapSIW400G_T075_W0 = {
    { 0x9C8F, U16, 1.0f, true, false }, // regPotenciaAtual
    { 0x9D6C, U16, 1.0f, true, true },  // regSetMaxPotencia
    { 0x9C90, U16, 1.0f, true, false }, // regTensaoRede
    { 0x9C91, U16, 1.0f, true, false }  // regCorrenteRede
};

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