#ifndef INVERTER_DESCRIPTOR_H
#define INVERTER_DESCRIPTOR_H

#include <Arduino.h>

enum InverterPhaseType {
    SINGLE_PHASE,
    THREE_PHASE
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

struct InverterDescriptor {
    InverterPhaseType phaseType;
    InverterTopology topology;
    InverterGridConnection gridConnection;
};

#endif