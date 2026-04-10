#include "InverterDescriptor.h"

const InverterDescriptor* getDescriptor(InverterModel model) {
    switch (model) {
        case SIW400G_T075_W0:
            return { SIW400G_T075_W0, THREE_PHASE, STRING, ON_GRID };
        case SIW400G_T100_W0:
            return { SIW400G_T100_W0, THREE_PHASE, STRING, ON_GRID };
        case GW3000_XS:
            return { GW3000_XS, SINGLE_PHASE, STRING, ON_GRID };
        case UNKNOWN_INVERTER:
            return { UNKNOWN_INVERTER, SINGLE_PHASE, STRING, ON_GRID };
        default:
            return { UNKNOWN_INVERTER, SINGLE_PHASE, STRING, ON_GRID };
    }
}