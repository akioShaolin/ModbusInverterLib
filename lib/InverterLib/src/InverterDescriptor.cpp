#include "InverterDescriptor.h"
#include "InverterModels.h"
/*
enum PhaseType {
    PHASE_NONE = 0x00,
    SINGLE_PHASE = 0x01,
    THREE_PHASE = 0x03
};

enum InverterTopology {
    STRING,
    CENTRAL,
    MICRO
};

enum InverterGridConnection {
    ON_GRID,
    OFF_GRID,
    HYBRID
};

struct PVInfo {
    uint8_t stringCount;    // Número de strings, relevante para inversores do tipo STRING, MICRO, pode ser 0 para outros tipos
    uint8_t mpptCount;      // Número de mppts, relevante para inversores do tipo STRING, MICRO, pode ser 0 para outros tipos
    uint8_t stringToMppt[MAX_STRINGS];  // Distribuição das Strings pelos MPPTs
};

struct BatteryInfo {
    uint8_t batteryCount;    // Número de baterias, relevante para inversores do tipo Hibrido e Offgrid, pode ser 0 para outros tipos
    uint8_t portCount;      // Número de entradas, relevante para inversores do tipo Hibrido e Offgrid, pode ser 0 para outros tipos
    uint8_t batteryToPort[MAX_BATTERIES];  // Distribuição das Baterias pelas Entradas
};
    
struct BootInfo {
    uint16_t bootValue = 0x01;        // Valores padrão para boot e shutdown
    uint16_t shutdownValue = 0x00;
};

enum AlarmFormat {
    ENUM_CODE,
    BITFIELD16,
    BITFIELD32
};

enum StatusFormat {
    ENUM_CODE,
    BITFIELD16,
    BITFIELD32
};

struct InverterDescriptor {
    PhaseType inverterPhaseType;
    InverterTopology topology;
    InverterGridConnection gridConnection;

    uint32_t nominalPowerW; // Potência máxima em watts, pode ser 0 se não for aplicável ou desconhecida

    BootInfo bootInfo;    
    PVInfo pvInfo;
    BatteryInfo batteryInfo;
    PhaseType EpsPhaseType;

    AlarmFormat alarmFormat;
    StatusFormat statusFormat;
};*/

// Revisar os alarmes e status depois. Linha SIW200 ok. SIW300H ok
constexpr InverterDescriptor desc_SIW200_M030 =            {SINGLE_PHASE, STRING, ON_GRID, 3000U, {0x00, 0x00}, {1, 1, {0}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD32, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW200_M050 =            {SINGLE_PHASE, STRING, ON_GRID, 5000U, {0x00, 0x00}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD32, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW200_M085 =            {SINGLE_PHASE, STRING, ON_GRID, 8500U, {0x00, 0x00}, {3, 3, {0, 1, 2}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD32, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW200_M100 =            {SINGLE_PHASE, STRING, ON_GRID, 10000U, {0x00, 0x00}, {3, 3, {0, 1, 2}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD32, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW200H_M050_W00 =       {SINGLE_PHASE, STRING, HYBRID,  5000U, {0x01, 0x01}, {2, 2, {0, 1}}, {4, 1, {0, 0, 0, 0}}, SINGLE_PHASE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW200H_M075_W10 =       {SINGLE_PHASE, STRING, HYBRID,  7500U, {0x01, 0x01}, {3, 3, {0, 1, 2}}, {4, 1, {0, 0, 0, 0}}, SINGLE_PHASE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW200H_M105_W10 =       {SINGLE_PHASE, STRING, HYBRID,  10500U, {0x01, 0x01}, {4, 4, {0, 1, 2, 3}}, {4, 1, {0, 0, 0, 0}}, SINGLE_PHASE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW200G_M030_W0 =        {SINGLE_PHASE, STRING, ON_GRID, 3000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW200G_M030_W1 =        {SINGLE_PHASE, STRING, ON_GRID, 3000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW200G_M050_W0 =        {SINGLE_PHASE, STRING, ON_GRID, 5000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW200G_M050_W1 =        {SINGLE_PHASE, STRING, ON_GRID, 5000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW200G_M060_W0 =        {SINGLE_PHASE, STRING, ON_GRID, 6000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW200G_M060_W1 =        {SINGLE_PHASE, STRING, ON_GRID, 6000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW200G_M070_W1 =        {SINGLE_PHASE, STRING, ON_GRID, 7000U, {0x01, 0x01}, {3, 3, {0, 1, 2}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW200G_M075_W1 =        {SINGLE_PHASE, STRING, ON_GRID, 7500U, {0x01, 0x01}, {3, 3, {0, 1, 2}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW200G_M080_W1 =        {SINGLE_PHASE, STRING, ON_GRID, 8000U, {0x01, 0x01}, {3, 3, {0, 1, 2}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW200G_M090_W1 =        {SINGLE_PHASE, STRING, ON_GRID, 9000U, {0x01, 0x01}, {3, 3, {0, 1, 2}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW200G_M105_W1 =        {SINGLE_PHASE, STRING, ON_GRID, 10500U, {0x01, 0x01}, {3, 3, {0, 1, 2}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW300H_M030_W00 =       {SINGLE_PHASE, STRING, HYBRID,  3000U, {0x01, 0x01}, {2, 2, {0, 1}}, {2, 1, {0, 0}}, SINGLE_PHASE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW300H_M050_W00 =       {SINGLE_PHASE, STRING, HYBRID,  5000U, {0x01, 0x01}, {2, 2, {0, 1}}, {2, 1, {0, 0}}, SINGLE_PHASE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW300H_M060_W00 =       {SINGLE_PHASE, STRING, HYBRID,  6000U, {0x01, 0x01}, {2, 2, {0, 1}}, {2, 1, {0, 0}}, SINGLE_PHASE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW300H_M075_W00 =       {SINGLE_PHASE, STRING, HYBRID,  7500U, {0x01, 0x01}, {3, 3, {0, 1, 2}}, {2, 1, {0, 0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW300H_M080_W00 =       {SINGLE_PHASE, STRING, HYBRID,  8000U, {0x01, 0x01}, {3, 3, {0, 1, 2}}, {2, 1, {0, 0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW300H_M100_W00 =       {SINGLE_PHASE, STRING, HYBRID,  10000U, {0x01, 0x01}, {3, 3, {0, 1, 2}}, {2, 1, {0, 0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW400_ST075 =           {THREE_PHASE , STRING, ON_GRID, 75000U, {0x00, 0x00}, {16, 4, {0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400G_T012_W0 =        {THREE_PHASE , STRING, ON_GRID, 12000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400G_T012_W1 =        {THREE_PHASE , STRING, ON_GRID, 12000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400G_T015_W0 =        {THREE_PHASE , STRING, ON_GRID, 15000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400G_T015_W1 =        {THREE_PHASE , STRING, ON_GRID, 15000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400G_T020_W0 =        {THREE_PHASE , STRING, ON_GRID, 20000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400G_T020_W1 =        {THREE_PHASE , STRING, ON_GRID, 20000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400G_T025_W0 =        {THREE_PHASE , STRING, ON_GRID, 25000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400G_T025_W1 =        {THREE_PHASE , STRING, ON_GRID, 25000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400G_T075_W0 =        {THREE_PHASE , STRING, ON_GRID, 75000U, {0xCE, 0xCF}, {18, 9, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400G_T100_W0 =        {THREE_PHASE , STRING, ON_GRID, 100000U, {0xCE, 0xCF}, {18, 9, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400G_T050_W00 =       {THREE_PHASE , STRING, ON_GRID, 50000U, {0xCE, 0xCF}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400G_T060_W00 =       {THREE_PHASE , STRING, ON_GRID, 60000U, {0xCE, 0xCF}, {12, 6, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400G_T075_W01 =       {THREE_PHASE , STRING, ON_GRID, 75000U, {0xCE, 0xCF}, {12, 6, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400G_K015_W00 =       {THREE_PHASE , STRING, ON_GRID, 15000U, {0xCE, 0xCF}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400G_K020_W00 =       {THREE_PHASE , STRING, ON_GRID, 20000U, {0xCE, 0xCF}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400G_K025_W00 =       {THREE_PHASE , STRING, ON_GRID, 25000U, {0xCE, 0xCF}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400G_K030_W00 =       {THREE_PHASE , STRING, ON_GRID, 30000U, {0xCE, 0xCF}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400G_K037_W00 =       {THREE_PHASE , STRING, ON_GRID, 37500U, {0xCE, 0xCF}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400H_T015_W10 =       {THREE_PHASE , STRING, HYBRID,  15000U, {0xCE, 0xCF}, {6, 3, {0, 0, 1, 1, 2, 2}}, {8, 2, {0, 0, 0, 0, 1, 1, 1, 1}}, THREE_PHASE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW400H_T030_W10 =       {THREE_PHASE , STRING, HYBRID,  30000U, {0xCE, 0xCF}, {6, 3, {0, 0, 1, 1, 2, 2}}, {8, 2, {0, 0, 0, 0, 1, 1, 1, 1}}, THREE_PHASE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SIW420G_K025_W00 =       {THREE_PHASE , STRING, ON_GRID, 25000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::UNKNOWN, StatusFormat::UNKNOWN };
constexpr InverterDescriptor desc_SIW420G_K075_W00 =       {THREE_PHASE , STRING, ON_GRID, 75000U, {0x01, 0x01}, {18, 9, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::UNKNOWN, StatusFormat::UNKNOWN };
constexpr InverterDescriptor desc_SIW500G_T075_W0 =        {THREE_PHASE , STRING, ON_GRID, 75000U, {0x01, 0x01}, {20, 10, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500G_T100_W0 =        {THREE_PHASE , STRING, ON_GRID, 100000U, {0x01, 0x01}, {20, 10, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500G_K050_W00 =       {THREE_PHASE , STRING, ON_GRID,  50000U, {0x01, 0x01}, {21, 7, {0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500G_K075_W00 =       {THREE_PHASE , STRING, ON_GRID,  75000U, {0x01, 0x01}, {21, 7, {0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500G_H250_W0 =        {THREE_PHASE , STRING, ON_GRID, 250000U, {0x01, 0x01}, {28, 6, {0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_ST012_M2 =       {THREE_PHASE , STRING, ON_GRID,  12000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_ST015_M2 =       {THREE_PHASE , STRING, ON_GRID,  15000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_ST020_M2 =       {THREE_PHASE , STRING, ON_GRID,  20000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_ST030_M3 =       {THREE_PHASE , STRING, ON_GRID,  30000U, {0x01, 0x01}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_ST036_M3 =       {THREE_PHASE , STRING, ON_GRID,  36000U, {0x01, 0x01}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_ST040_M3 =       {THREE_PHASE , STRING, ON_GRID,  40000U, {0x01, 0x01}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_SK020 =          {THREE_PHASE , STRING, ON_GRID,  20000U, {0x01, 0x01}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_ST030 =          {THREE_PHASE , STRING, ON_GRID,  30000U, {0x01, 0x01}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_ST036 =          {THREE_PHASE , STRING, ON_GRID,  36000U, {0x01, 0x01}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_ST040 =          {THREE_PHASE , STRING, ON_GRID,  40000U, {0x01, 0x01}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_ST060 =          {THREE_PHASE , STRING, ON_GRID, 60000U, {0x01, 0x01}, {12, 6, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_ST100 =          {THREE_PHASE , STRING, ON_GRID, 100000U, {0x01, 0x01}, {20, 10, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_ST200_H3 =       {THREE_PHASE , STRING, ON_GRID, 200000U, {0x01, 0x01}, {18, 9, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_ST200_H0 =       {THREE_PHASE , STRING, ON_GRID, 200000U, {0x01, 0x01}, {14, 3, {0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_ST060_HV =       {THREE_PHASE , STRING, ON_GRID, 600000U, {0x01, 0x01}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_ST100_HV =       {THREE_PHASE , STRING, ON_GRID, 1000000U, {0x01, 0x01}, {12, 6, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_T012_W00 =       {THREE_PHASE , STRING, HYBRID,  12000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_T015_W00 =       {THREE_PHASE , STRING, HYBRID,  15000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_T017_W00 =       {THREE_PHASE , STRING, HYBRID,  17000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_T020_W00 =       {THREE_PHASE , STRING, HYBRID,  20000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW500H_T025_W00 =       {THREE_PHASE , STRING, HYBRID,  25000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SIW600_T020_44 =         {THREE_PHASE , STRING, ON_GRID, 20000U };
constexpr InverterDescriptor desc_SIW610_T018_W0 =         {THREE_PHASE , STRING, ON_GRID,  18000U };
constexpr InverterDescriptor desc_SIW610_T075_W0 =         {THREE_PHASE , STRING, ON_GRID,  75000U };
constexpr InverterDescriptor desc_S700_G2 =                {SINGLE_PHASE , STRING, ON_GRID,  700U };
constexpr InverterDescriptor desc_S1000_G2 =               {SINGLE_PHASE , STRING, ON_GRID,  1000U };
constexpr InverterDescriptor desc_S1500_G2 =               {SINGLE_PHASE , STRING, ON_GRID,  1500U };
constexpr InverterDescriptor desc_S2000_G2 =               {SINGLE_PHASE , STRING, ON_GRID,  2000U };
constexpr InverterDescriptor desc_S2500_G2 =               {SINGLE_PHASE , STRING, ON_GRID,  2500U };
constexpr InverterDescriptor desc_S3000_G2 =               {SINGLE_PHASE , STRING, ON_GRID,  3000U };
constexpr InverterDescriptor desc_S3300_G2 =               {SINGLE_PHASE, STRING, ON_GRID,  3300U };
constexpr InverterDescriptor desc_F3000_G2 =               {SINGLE_PHASE, STRING, ON_GRID,  3000U };
constexpr InverterDescriptor desc_F3600_G2 =               {SINGLE_PHASE, STRING, ON_GRID,  3600U };
constexpr InverterDescriptor desc_F4600_G2 =               {SINGLE_PHASE, STRING, ON_GRID,  4600U };
constexpr InverterDescriptor desc_F5000_G2 =               {SINGLE_PHASE, STRING, ON_GRID,  5000U };
constexpr InverterDescriptor desc_F5300_G2 =               {SINGLE_PHASE, STRING, ON_GRID,  5300U };
constexpr InverterDescriptor desc_F6000_G2 =               {SINGLE_PHASE, STRING, ON_GRID,  6000U };
constexpr InverterDescriptor desc_G7 =                     {SINGLE_PHASE, STRING, ON_GRID,  7000U };
constexpr InverterDescriptor desc_G7_5 =                   {SINGLE_PHASE, STRING, ON_GRID,  7500U };
constexpr InverterDescriptor desc_G8_ =                    {SINGLE_PHASE, STRING, ON_GRID,  8000U };
constexpr InverterDescriptor desc_G9 =                     {SINGLE_PHASE, STRING, ON_GRID,  9000U };
constexpr InverterDescriptor desc_G10 =                    {SINGLE_PHASE, STRING, ON_GRID,  10000U };
constexpr InverterDescriptor desc_G10_5 =                  {SINGLE_PHASE, STRING, ON_GRID,  10500U };
constexpr InverterDescriptor desc_T3_G3 =                  {THREE_PHASE , STRING, ON_GRID,  3000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_T4_G3 =                  {THREE_PHASE , STRING, ON_GRID,  4000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_T5_G3 =                  {THREE_PHASE , STRING, ON_GRID,  5000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_T6_G3 =                  {THREE_PHASE , STRING, ON_GRID,  6000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_T8_G3 =                  {THREE_PHASE , STRING, ON_GRID,  8000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_T10_G3 =                 {THREE_PHASE , STRING, ON_GRID,  10000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_T12_G3 =                 {THREE_PHASE , STRING, ON_GRID,  12000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_T15_G3 =                 {THREE_PHASE , STRING, ON_GRID,  15000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_T17_G3 =                 {THREE_PHASE , STRING, ON_GRID,  17000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_T20_G3 =                 {THREE_PHASE , STRING, ON_GRID,  20000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_T23_G3 =                 {THREE_PHASE , STRING, ON_GRID,  23000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_T25_G3 =                 {THREE_PHASE , STRING, ON_GRID,  25000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_V30 =                    {THREE_PHASE , STRING, ON_GRID,  30000U, {0xCE, 0xCF}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_V33 =                    {THREE_PHASE , STRING, ON_GRID,  33000U, {0xCE, 0xCF}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_V36 =                    {THREE_PHASE , STRING, ON_GRID,  36000U, {0xCE, 0xCF}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_V40 =                    {THREE_PHASE , STRING, ON_GRID,  40000U, {0xCE, 0xCF}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_V50 =                    {THREE_PHASE , STRING, ON_GRID,  50000U, {0xCE, 0xCF}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_V60 =                    {THREE_PHASE , STRING, ON_GRID,  60000U, {0xCE, 0xCF}, {12, 6, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_V75 =                    {THREE_PHASE , STRING, ON_GRID,  75000U, {0xCE, 0xCF}, {12, 6, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_VL15 =                   {THREE_PHASE , STRING, ON_GRID,  15000U, {0xCE, 0xCF}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_VL20 =                   {THREE_PHASE , STRING, ON_GRID,  20000U, {0xCE, 0xCF}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_VL25 =                   {THREE_PHASE , STRING, ON_GRID,  25000U, {0xCE, 0xCF}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_VL30 =                   {THREE_PHASE , STRING, ON_GRID,  30000U, {0xCE, 0xCF}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_VL37_5 =                 {THREE_PHASE , STRING, ON_GRID,  37500U, {0xCE, 0xCF}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_R75 =                    {THREE_PHASE , STRING, ON_GRID,  75000U, {0xCE, 0xCF}, {18, 9, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_R100 =                   {THREE_PHASE , STRING, ON_GRID,  100000U, {0xCE, 0xCF}, {18, 9, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_R110 =                   {THREE_PHASE , STRING, ON_GRID,  110000U, {0xCE, 0xCF}, {18, 9, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_GW3000_XS =              {SINGLE_PHASE, STRING, ON_GRID,  3000U, {0x00, 0x00}, {1, 1, {0}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD32, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_GW3300_XS_30 =           {SINGLE_PHASE, STRING, ON_GRID,  3300U, {0x00, 0x00}, {1, 1, {0}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD32, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_GW5000_DNS =             {SINGLE_PHASE, STRING, ON_GRID,  5000U, {0x00, 0x00}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD32, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_GW5K_DNS_G40 =           {SINGLE_PHASE, STRING, ON_GRID,  5000U, {0x00, 0x00}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD32, StatusFormat::ENUM_CODE };
//GW8500-MS, GW10K-MS
constexpr InverterDescriptor desc_SUN2000_2KTL =           {SINGLE_PHASE, STRING, ON_GRID,  2000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SUN2000_3KTL =           {SINGLE_PHASE, STRING, ON_GRID,  3000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SUN2000_4KTL =           {SINGLE_PHASE, STRING, ON_GRID,  4000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SUN2000_5KTL =           {SINGLE_PHASE, STRING, ON_GRID,  5000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SUN2000_6KTL =           {SINGLE_PHASE, STRING, ON_GRID,  6000U, {0x01, 0x01}, {2, 2, {0, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::ENUM_CODE };
constexpr InverterDescriptor desc_SUN2000_12KTL_M0 =       {THREE_PHASE , STRING, ON_GRID,  12000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SUN2000_12KTL_M2 =       {THREE_PHASE , STRING, ON_GRID,  12000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SUN2000_15KTL_M0 =       {THREE_PHASE , STRING, ON_GRID,  15000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SUN2000_15KTL_M2 =       {THREE_PHASE , STRING, ON_GRID,  15000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SUN2000_20KTL_M0 =       {THREE_PHASE , STRING, ON_GRID,  20000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SUN2000_20KTL_M2 =       {THREE_PHASE , STRING, ON_GRID,  20000U, {0x01, 0x01}, {4, 2, {0, 0, 1, 1}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SUN2000_33KTL_A =        {THREE_PHASE , STRING, ON_GRID,  33000U, {0x01, 0x01}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SUN2000_36KTL_A =        {THREE_PHASE , STRING, ON_GRID,  36000U, {0x01, 0x01}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SUN2000_30KTL_M3 =       {THREE_PHASE , STRING, ON_GRID,  30000U, {0x01, 0x01}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SUN2000_36KTL_M3 =       {THREE_PHASE , STRING, ON_GRID,  36000U, {0x01, 0x01}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SUN2000_40KTL_M3 =       {THREE_PHASE , STRING, ON_GRID,  40000U, {0x01, 0x01}, {8, 4, {0, 0, 1, 1, 2, 2, 3, 3}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SUN2000_60KTL_M0 =       {THREE_PHASE , STRING, ON_GRID,  60000U, {0x01, 0x01}, {12, 6, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SUN2000_75KTL_M1 =       {THREE_PHASE , STRING, ON_GRID,  75000U, {0x01, 0x01}, {20, 10, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SUN2000_100KTL_M2 =      {THREE_PHASE , STRING, ON_GRID, 100000U, {0x01, 0x01}, {20, 10, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SUN2000_100KTL_H1 =      {THREE_PHASE , STRING, ON_GRID,  100000U, {0x01, 0x01}, {12, 6, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SUN2000_215KTL_H0 =      {THREE_PHASE , STRING, ON_GRID,  215000U, {0x01, 0x01}, {18, 9, {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SUN2000_215KTL_H3 =      {THREE_PHASE , STRING, ON_GRID,  215000U, {0x01, 0x01}, {14, 3, {0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };
constexpr InverterDescriptor desc_SUN2000_250KTL_H1 =      {THREE_PHASE , STRING, ON_GRID,  250000U, {0x01, 0x01}, {28, 6, {0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5}}, {0, 0, {0}}, PHASE_NONE, AlarmFormat::BITFIELD16, StatusFormat::BITFIELD16 };

const InverterDescriptor* getDescriptor(InverterModel model) {
    switch (model) {
        case SIW200_M030:
            return &desc_SIW200_M030;
        case SIW200_M050:
            return &desc_SIW200_M050;
        case SIW200_M085:
            return &desc_SIW200_M085;
        case SIW200_M100:
            return &desc_SIW200_M100;
        case SIW200H_M050_W00:
            return &desc_SIW200H_M050_W00;
        case SIW200H_M075_W10:
            return &desc_SIW200H_M075_W10;
        case SIW200H_M105_W10:
            return &desc_SIW200H_M105_W10;
        case SIW200G_M030_W0:
            return &desc_SIW200G_M030_W0;
        case SIW200G_M030_W1:
            return &desc_SIW200G_M030_W1;
        case SIW200G_M050_W0:
            return &desc_SIW200G_M050_W0;
        case SIW200G_M050_W1:
            return &desc_SIW200G_M050_W1;
        case SIW200G_M060_W0:
            return &desc_SIW200G_M060_W0;
        case SIW200G_M060_W1:
            return &desc_SIW200G_M060_W1;
        case SIW200G_M070_W1:
            return &desc_SIW200G_M070_W1;
        case SIW200G_M075_W1:
            return &desc_SIW200G_M075_W1;
        case SIW200G_M080_W1:
            return &desc_SIW200G_M080_W1;
        case SIW200G_M090_W1:
            return &desc_SIW200G_M090_W1;
        case SIW200G_M105_W1:
            return &desc_SIW200G_M105_W1;
        case SIW300H_M030_W00:
            return &desc_SIW300H_M030_W00;
        case SIW300H_M050_W00:
            return &desc_SIW300H_M050_W00;
        case SIW300H_M060_W00:
            return &desc_SIW300H_M060_W00;
        case SIW300H_M075_W00:
            return &desc_SIW300H_M075_W00;
        case SIW300H_M080_W00:
            return &desc_SIW300H_M080_W00;
        case SIW300H_M100_W00:
            return &desc_SIW300H_M100_W00;
        case SIW400_ST075:
            return &desc_SIW400_ST075;
        case SIW400G_T012_W0:
            return &desc_SIW400G_T012_W0;
        case SIW400G_T012_W1:
            return &desc_SIW400G_T012_W1;
        case SIW400G_T015_W0:
            return &desc_SIW400G_T015_W0;
        case SIW400G_T015_W1:
            return &desc_SIW400G_T015_W1;
        case SIW400G_T020_W0:
            return &desc_SIW400G_T020_W0;
        case SIW400G_T020_W1:
            return &desc_SIW400G_T020_W1;
        case SIW400G_T025_W0:
            return &desc_SIW400G_T025_W0;
        case SIW400G_T025_W1:
            return &desc_SIW400G_T025_W1;
        case SIW400G_T075_W0:
            return &desc_SIW400G_T075_W0;
        case SIW400G_T100_W0:
            return &desc_SIW400G_T100_W0;
        case SIW400G_T050_W00:
            return &desc_SIW400G_T050_W00;
        case SIW400G_T060_W00:
            return &desc_SIW400G_T060_W00;
        case SIW400G_T075_W01:
            return &desc_SIW400G_T075_W01;
        case SIW400G_K015_W00:
            return &desc_SIW400G_K015_W00;
        case SIW400G_K020_W00:
            return &desc_SIW400G_K020_W00;
        case SIW400G_K025_W00:
            return &desc_SIW400G_K025_W00;
        case SIW400G_K030_W00:
            return &desc_SIW400G_K030_W00;
        case SIW400G_K037_W00:
            return &desc_SIW400G_K037_W00;
        case SIW400H_T015_W10:
            return &desc_SIW400H_T015_W10;
        case SIW400H_T030_W10:
            return &desc_SIW400H_T030_W10;
        case SIW420G_K025_W00:
            return &desc_SIW420G_K025_W00;
        case SIW420G_K075_W00:
            return &desc_SIW420G_K075_W00;
        case SIW500G_T075_W0:
            return &desc_SIW500G_T075_W0;
        case SIW500G_T100_W0:
            return &desc_SIW500G_T100_W0;
        case SIW500G_K050_W00:
            return &desc_SIW500G_K050_W00;
        case SIW500G_K075_W00:
            return &desc_SIW500G_K075_W00;
        case SIW500G_H250_W0:
            return &desc_SIW500G_H250_W0;
        case SIW500H_ST012_M2:
            return &desc_SIW500H_ST012_M2;
        case SIW500H_ST015_M2:
            return &desc_SIW500H_ST015_M2;
        case SIW500H_ST020_M2:
            return &desc_SIW500H_ST020_M2;
        case SIW500H_ST030_M3:
            return &desc_SIW500H_ST030_M3;
        case SIW500H_ST036_M3:
            return &desc_SIW500H_ST036_M3;
        case SIW500H_ST040_M3:
            return &desc_SIW500H_ST040_M3;
        case SIW500H_SK020:
            return &desc_SIW500H_SK020;
        case SIW500H_ST030:
            return &desc_SIW500H_ST030;
        case SIW500H_ST036:
            return &desc_SIW500H_ST036;
        case SIW500H_ST040:
            return &desc_SIW500H_ST040;
        case SIW500H_ST060:
            return &desc_SIW500H_ST060;
        case SIW500H_ST100:
            return &desc_SIW500H_ST100;
        case SIW500H_ST060_HV:
            return &desc_SIW500H_ST060_HV;
        case SIW500H_ST100_HV:
            return &desc_SIW500H_ST100_HV;
        case SIW500H_ST200_H0:
            return &desc_SIW500H_ST200_H0;
        case SIW500H_ST200_H3:
            return &desc_SIW500H_ST200_H3;
        case SIW500H_T012_W00:
            return &desc_SIW500H_T012_W00;
        case SIW500H_T015_W00:
            return &desc_SIW500H_T015_W00;
        case SIW500H_T017_W00:
            return &desc_SIW500H_T017_W00;
        case SIW500H_T020_W00:
            return &desc_SIW500H_T020_W00;
        case SIW500H_T025_W00:
            return &desc_SIW500H_T025_W00;
        case SIW600_T020_44:
            return &desc_SIW600_T020_44;
        case SIW610_T018_W0:
            return &desc_SIW610_T018_W0;
        case SIW610_T075_W0:
            return &desc_SIW610_T075_W0;
        case S700_G2:
            return &desc_S700_G2;
        case S1000_G2:
            return &desc_S1000_G2;
        case S1500_G2:
            return &desc_S1500_G2;
        case S2000_G2:
            return &desc_S2000_G2;
        case S2500_G2:
            return &desc_S2500_G2;
        case S3000_G2:
            return &desc_S3000_G2;
        case S3300_G2:
            return &desc_S3300_G2;
        case F3000_G2:
            return &desc_F3000_G2;
        case F3600_G2:
            return &desc_F3600_G2;
        case F4600_G2:
            return &desc_F4600_G2;
        case F5000_G2:
            return &desc_F5000_G2;
        case F5300_G2:
            return &desc_F5300_G2;
        case F6000_G2:
            return &desc_F6000_G2;
        case G7:
            return &desc_G7;
        case G7_5:
            return &desc_G7_5;
        case G8_:
            return &desc_G8_;
        case G9:
            return &desc_G9;
        case G10:
            return &desc_G10;
        case G10_5:
            return &desc_G10_5;
        case T3_G3:
            return &desc_T3_G3;
        case T4_G3:
            return &desc_T4_G3;
        case T5_G3:
            return &desc_T5_G3;
        case T6_G3:
            return &desc_T6_G3;
        case T8_G3:
            return &desc_T8_G3;
        case T10_G3:
            return &desc_T10_G3;
        case T12_G3:
            return &desc_T12_G3;
        case T15_G3:
            return &desc_T15_G3;
        case T17_G3:
            return &desc_T17_G3;
        case T20_G3:
            return &desc_T20_G3;
        case T23_G3:
            return &desc_T23_G3;
        case T25_G3:
            return &desc_T25_G3;
        case V30:
            return &desc_V30;
        case V33:
            return &desc_V33;
        case V36:
            return &desc_V36;
        case V40:
            return &desc_V40;
        case V50:
            return &desc_V50;
        case V60:
            return &desc_V60;
        case V75:
            return &desc_V75;
        case VL15:
            return &desc_VL15;
        case VL20:
            return &desc_VL20;
        case VL25:
            return &desc_VL25;
        case VL30:
            return &desc_VL30;
        case VL37_5:
            return &desc_VL37_5;
        case R75:
            return &desc_R75;
        case R100:
            return &desc_R100;
        case R110:
            return &desc_R110;
        case GW3000_XS:
            return &desc_GW3000_XS;
        case GW3300_XS_30:
            return &desc_GW3300_XS_30;
        case GW5000_DNS:
            return &desc_GW5000_DNS;
        case GW5K_DNS_G40:
            return &desc_GW5K_DNS_G40;
        case SUN2000_2KTL:
            return &desc_SUN2000_2KTL;
        case SUN2000_3KTL:
            return &desc_SUN2000_3KTL;
        case SUN2000_4KTL:
            return &desc_SUN2000_4KTL;
        case SUN2000_5KTL:
            return &desc_SUN2000_5KTL;
        case SUN2000_6KTL:
            return &desc_SUN2000_6KTL;
        case SUN2000_12KTL_M0:
            return &desc_SUN2000_12KTL_M0;
        case SUN2000_12KTL_M2:
            return &desc_SUN2000_12KTL_M2;
        case SUN2000_15KTL_M0:
            return &desc_SUN2000_15KTL_M0;
        case SUN2000_15KTL_M2:
            return &desc_SUN2000_15KTL_M2;
        case SUN2000_20KTL_M0:
            return &desc_SUN2000_20KTL_M0;
        case SUN2000_20KTL_M2:
            return &desc_SUN2000_20KTL_M2;
        case SUN2000_30KTL:
            return &desc_SUN2000_33KTL_A;
        case SUN2000_36KTL_A:
            return &desc_SUN2000_36KTL_A;
        case SUN2000_30KTL_M3:
            return &desc_SUN2000_30KTL_M3;
        case SUN2000_36KTL_M3:
            return &desc_SUN2000_36KTL_M3;
        case SUN2000_40KTL_M3:
            return &desc_SUN2000_40KTL_M3;
        case SUN2000_60KTL_M0:
            return &desc_SUN2000_60KTL_M0;
        case SUN2000_75KTL_M1:
            return &desc_SUN2000_75KTL_M1;
        case SUN2000_100KTL_M2:
            return &desc_SUN2000_100KTL_M2;
        case SUN2000_100KTL_H1:
            return &desc_SUN2000_100KTL_H1;
        case SUN2000_215KTL_H0:
            return &desc_SUN2000_215KTL_H0;
        case SUN2000_215KTL_H3:
            return &desc_SUN2000_215KTL_H3;
        case SUN2000_250KTL_H1:
            return &desc_SUN2000_250KTL_H1;
    }
}