#include "InverterDescriptor.h"
#include "InverterModels.h"

static const InverterDescriptor _​​​​​​​​​​​​​​SIW100G_M010_W00 =       {SINGLE_PHASE, MICRO , ON_GRID,  2, 1000 }; //Colocar quantidade de strings
static const InverterDescriptor _​​​​​​​​​​​​​​SIW100G_M024_W10 =       {SINGLE_PHASE, MICRO , ON_GRID,  2, 2400 };
static const InverterDescriptor _SIW200_M030 =            {SINGLE_PHASE, STRING, ON_GRID,  2, 3000 };
static const InverterDescriptor _SIW200_M050 =            {SINGLE_PHASE, STRING, ON_GRID,  2, 5000 };
static const InverterDescriptor _SIW200_M085 =            {SINGLE_PHASE, STRING, ON_GRID,  3, 8500 };
static const InverterDescriptor _SIW200_M100 =            {SINGLE_PHASE, STRING, ON_GRID,  3, 10000 };
static const InverterDescriptor _SIW200H_M050_W00 =       {SINGLE_PHASE, STRING, HYBRID,   2, 5000 };
static const InverterDescriptor _SIW200H_M075_W10 =       {SINGLE_PHASE, STRING, HYBRID,   3, 7500 };
static const InverterDescriptor _SIW200H_M105_W10 =       {SINGLE_PHASE, STRING, HYBRID,   3, 10500 };
static const InverterDescriptor _SIW200G_M030_W0 =        {SINGLE_PHASE, STRING, ON_GRID,  2, 3000 };
static const InverterDescriptor _SIW200G_M030_W1 =        {SINGLE_PHASE, STRING, ON_GRID,  2, 3000 };
static const InverterDescriptor _SIW200G_M050_W0 =        {SINGLE_PHASE, STRING, ON_GRID,  2, 5000 };
static const InverterDescriptor _SIW200G_M050_W1 =        {SINGLE_PHASE, STRING, ON_GRID,  2, 5000 };
static const InverterDescriptor _SIW200G_M060_W0 =        {SINGLE_PHASE, STRING, ON_GRID,  2, 6000 };
static const InverterDescriptor _SIW200G_M060_W1 =        {SINGLE_PHASE, STRING, ON_GRID,  2, 6000 };
static const InverterDescriptor _SIW200G_M070_W1 =        {SINGLE_PHASE, STRING, ON_GRID,  3, 7000 };
static const InverterDescriptor _SIW200G_M075_W1 =        {SINGLE_PHASE, STRING, ON_GRID,  3, 7500 };
static const InverterDescriptor _SIW200G_M080_W1 =        {SINGLE_PHASE, STRING, ON_GRID,  3, 8000 };
static const InverterDescriptor _SIW200G_M090_W1 =        {SINGLE_PHASE, STRING, ON_GRID,  3, 9000 };
static const InverterDescriptor _SIW200G_M105_W1 =        {SINGLE_PHASE, STRING, ON_GRID,  3, 10500 };
static const InverterDescriptor _SIW300H_M030_W00 =       {SINGLE_PHASE, STRING, HYBRID,   2, 3000 };
static const InverterDescriptor _SIW300H_M050_W00 =       {SINGLE_PHASE, STRING, HYBRID,   2, 5000 };
static const InverterDescriptor _SIW300H_M060_W00 =       {SINGLE_PHASE, STRING, HYBRID,   2, 6000 };
static const InverterDescriptor _SIW300H_M075_W00 =       {SINGLE_PHASE, STRING, HYBRID,   3, 7500 };
static const InverterDescriptor _SIW300H_M080_W00 =       {SINGLE_PHASE, STRING, HYBRID,   3, 8000 };
static const InverterDescriptor _SIW300H_M100_W00 =       {SINGLE_PHASE, STRING, HYBRID,   3, 10000 };
static const InverterDescriptor _SIW400_ST075 =           {THREE_PHASE , STRING, ON_GRID, 16, 75000 };
static const InverterDescriptor _SIW400G_T012_W0 =        {THREE_PHASE , STRING, ON_GRID,  2, 12000 };
static const InverterDescriptor _SIW400G_T012_W1 =        {THREE_PHASE , STRING, ON_GRID,  2, 12000 };
static const InverterDescriptor _SIW400G_T015_W0 =        {THREE_PHASE , STRING, ON_GRID,  4, 15000 };
static const InverterDescriptor _SIW400G_T015_W1 =        {THREE_PHASE , STRING, ON_GRID,  4, 15000 };
static const InverterDescriptor _SIW400G_T020_W0 =        {THREE_PHASE , STRING, ON_GRID,  4, 20000 };
static const InverterDescriptor _SIW400G_T020_W1 =        {THREE_PHASE , STRING, ON_GRID,  4, 20000 };
static const InverterDescriptor _SIW400G_T025_W0 =        {THREE_PHASE , STRING, ON_GRID,  4, 25000 };
static const InverterDescriptor _SIW400G_T025_W1 =        {THREE_PHASE , STRING, ON_GRID,  4, 25000 };
static const InverterDescriptor _SIW400G_T075_W0 =        {THREE_PHASE , STRING, ON_GRID, 18, 75000 };
static const InverterDescriptor _SIW400G_T100_W0 =        {THREE_PHASE , STRING, ON_GRID, 18, 100000 };
static const InverterDescriptor _SIW400G_T050_W00 =       {THREE_PHASE , STRING, ON_GRID, 12, 50000 };
static const InverterDescriptor _SIW400G_T060_W00 =       {THREE_PHASE , STRING, ON_GRID, 12, 60000 };
static const InverterDescriptor _SIW400G_T075_W01 =       {THREE_PHASE , STRING, ON_GRID, 12, 75000 };
static const InverterDescriptor _SIW400G_K015_W00 =       {THREE_PHASE , STRING, ON_GRID,  8, 15000 };
static const InverterDescriptor _SIW400G_K020_W00 =       {THREE_PHASE , STRING, ON_GRID,  8, 20000 };
static const InverterDescriptor _SIW400G_K025_W00 =       {THREE_PHASE , STRING, ON_GRID,  8, 25000 };
static const InverterDescriptor _SIW400G_K030_W00 =       {THREE_PHASE , STRING, ON_GRID,  8, 30000 };
static const InverterDescriptor _SIW400G_K037_W00 =       {THREE_PHASE , STRING, ON_GRID,  8, 37500 };
static const InverterDescriptor _SIW400H_T015_W10 =       {THREE_PHASE , STRING, HYBRID,   6, 15000 };
static const InverterDescriptor _SIW400H_T030_W10 =       {THREE_PHASE , STRING, HYBRID,   6, 30000 };
static const InverterDescriptor _SIW420G_K025_W00 =       {THREE_PHASE , STRING, ON_GRID,  8, 25000 };
static const InverterDescriptor _SIW420G_K075_W00 =       {THREE_PHASE , STRING, ON_GRID,  8, 75000 };
static const InverterDescriptor _SIW500G_T075_W0 =        {THREE_PHASE , STRING, ON_GRID,  8, 75000 };
static const InverterDescriptor _SIW500G_T100_W0 =        {THREE_PHASE , STRING, ON_GRID, 20, 100000 }; //Não consegui encontrar a quantidade de strings para esses modelos, então deixei sem valor, o que pode ser interpretado como 0 ou desconhecido. Se for possível obter essa informação, é recomendado preenchê-la para manter a consistência dos dados.
static const InverterDescriptor _SIW500G_K050_W00 =       {THREE_PHASE , STRING, ON_GRID,  8, 50000 };
static const InverterDescriptor _SIW500G_K075_W00 =       {THREE_PHASE , STRING, ON_GRID,  8, 75000 };
static const InverterDescriptor _SIW500G_H250_W0 =        {THREE_PHASE , STRING, ON_GRID, 28, 250000 };
static const InverterDescriptor _SIW500H_ST012_M2 =       {THREE_PHASE , STRING, ON_GRID,  4, 12000 };
static const InverterDescriptor _SIW500H_ST015_M2 =       {THREE_PHASE , STRING, ON_GRID,  4, 15000 };
static const InverterDescriptor _SIW500H_ST020_M2 =       {THREE_PHASE , STRING, ON_GRID,  4, 20000 };
static const InverterDescriptor _SIW500H_ST030_M3 =       {THREE_PHASE , STRING, ON_GRID,  8, 30000 };
static const InverterDescriptor _SIW500H_ST036_M3 =       {THREE_PHASE , STRING, ON_GRID,  8, 36000 };
static const InverterDescriptor _SIW500H_ST040_M3 =       {THREE_PHASE , STRING, ON_GRID,  8, 40000 };
static const InverterDescriptor _SIW500H_SK020 =          {THREE_PHASE , STRING, ON_GRID,  8, 20000 };
static const InverterDescriptor _SIW500H_ST030 =          {THREE_PHASE , STRING, ON_GRID,  8, 30000 };
static const InverterDescriptor _SIW500H_ST036 =          {THREE_PHASE , STRING, ON_GRID,  8, 36000 };
static const InverterDescriptor _SIW500H_ST040 =          {THREE_PHASE , STRING, ON_GRID,  8, 40000 };
static const InverterDescriptor _SIW500H_ST060 =          {THREE_PHASE , STRING, ON_GRID, 12, 60000 };
static const InverterDescriptor _SIW500H_ST100 =          {THREE_PHASE , STRING, ON_GRID, 18, 100000 };
static const InverterDescriptor _SIW500H_ST200_H3 =       {THREE_PHASE , STRING, ON_GRID, 14, 200000 };
static const InverterDescriptor _SIW500H_ST200_H0 =       {THREE_PHASE , STRING, ON_GRID, 20, 200000 };
static const InverterDescriptor _SIW500H_ST060_HV =       {THREE_PHASE , STRING, ON_GRID, 8,  600000 };
static const InverterDescriptor _SIW500H_ST100_HV =       {THREE_PHASE , STRING, ON_GRID, 12, 1000000 };
static const InverterDescriptor _SIW500H_T012_W00 =       {THREE_PHASE , STRING, HYBRID,  4,  12000 };
static const InverterDescriptor _SIW500H_T015_W00 =       {THREE_PHASE , STRING, HYBRID,  4,  15000 };
static const InverterDescriptor _SIW500H_T017_W00 =       {THREE_PHASE , STRING, HYBRID,  4,  17000 };
static const InverterDescriptor _SIW500H_T020_W00 =       {THREE_PHASE , STRING, HYBRID,  4,  20000 };
static const InverterDescriptor _SIW500H_T025_W00 =       {THREE_PHASE , STRING, HYBRID,  4,  25000 };
static const InverterDescriptor _SIW600_T020_44 =         {THREE_PHASE , STRING, ON_GRID,  8, 20000 };
static const InverterDescriptor _SIW610_T018_W0 =         {THREE_PHASE , STRING, ON_GRID,  8, 18000 };
static const InverterDescriptor _SIW610_T075_W0 =         {THREE_PHASE , STRING, ON_GRID,  8, 75000 };
static const InverterDescriptor _S700_G2 =                {SINGLE_PHASE , STRING, ON_GRID,  1, 700 };
static const InverterDescriptor _S1000_G2 =               {SINGLE_PHASE , STRING, ON_GRID,  1, 1000 };
static const InverterDescriptor _S1500_G2 =               {SINGLE_PHASE , STRING, ON_GRID,  1, 1500 };
static const InverterDescriptor _S2000_G2 =               {SINGLE_PHASE , STRING, ON_GRID,  1, 2000 };
static const InverterDescriptor _S2500_G2 =               {SINGLE_PHASE , STRING, ON_GRID,  1, 2500 };
static const InverterDescriptor _S3000_G2 =               {SINGLE_PHASE , STRING, ON_GRID,  1, 3000 };
static const InverterDescriptor _S3300_G2 =               {SINGLE_PHASE, STRING, ON_GRID,  1, 3300 };
static const InverterDescriptor _F3000_G2 =               {SINGLE_PHASE, STRING, ON_GRID,  2, 3000 };
static const InverterDescriptor _F3600_G2 =               {SINGLE_PHASE, STRING, ON_GRID,  2, 3600 };
static const InverterDescriptor _F4600_G2 =               {SINGLE_PHASE, STRING, ON_GRID,  2, 4600 };
static const InverterDescriptor _F5000_G2 =               {SINGLE_PHASE, STRING, ON_GRID,  2, 5000 };
static const InverterDescriptor _F5300_G2 =               {SINGLE_PHASE, STRING, ON_GRID,  2, 5300 };
static const InverterDescriptor _F6000_G2 =               {SINGLE_PHASE, STRING, ON_GRID,  2, 6000 };
static const InverterDescriptor _G7 =                     {SINGLE_PHASE, STRING, ON_GRID,  3, 7000 };
static const InverterDescriptor _G7_5 =                   {SINGLE_PHASE, STRING, ON_GRID,  3, 7500 };
static const InverterDescriptor _G8_ =                    {SINGLE_PHASE, STRING, ON_GRID,  3, 8000 };
static const InverterDescriptor _G9 =                     {SINGLE_PHASE, STRING, ON_GRID,  3, 9000 };
static const InverterDescriptor _G10 =                    {SINGLE_PHASE, STRING, ON_GRID,  3, 10000 };
static const InverterDescriptor _G10_5 =                  {SINGLE_PHASE, STRING, ON_GRID,  3, 10500 };
static const InverterDescriptor _T3_G3 =                  {THREE_PHASE , STRING, ON_GRID,  2, 3000 };
static const InverterDescriptor _T4_G3 =                  {THREE_PHASE , STRING, ON_GRID,  2, 4000 };
static const InverterDescriptor _T5_G3 =                  {THREE_PHASE , STRING, ON_GRID,  2, 5000 };
static const InverterDescriptor _T6_G3 =                  {THREE_PHASE , STRING, ON_GRID,  2, 6000 };
static const InverterDescriptor _T8_G3 =                  {THREE_PHASE , STRING, ON_GRID,  2, 8000 };
static const InverterDescriptor _T10_G3 =                 {THREE_PHASE , STRING, ON_GRID,  2, 10000 };
static const InverterDescriptor _T12_G3 =                 {THREE_PHASE , STRING, ON_GRID,  2, 12000 };
static const InverterDescriptor _T15_G3 =                 {THREE_PHASE , STRING, ON_GRID,  2, 15000 };
static const InverterDescriptor _T17_G3 =                 {THREE_PHASE , STRING, ON_GRID,  2, 17000 };
static const InverterDescriptor _T20_G3 =                 {THREE_PHASE , STRING, ON_GRID,  2, 20000 };
static const InverterDescriptor _T23_G3 =                 {THREE_PHASE , STRING, ON_GRID,  2, 23000 };
static const InverterDescriptor _T25_G3 =                 {THREE_PHASE , STRING, ON_GRID,  2, 25000 };
static const InverterDescriptor _V30 =                    {THREE_PHASE , STRING, ON_GRID,  2, 30000 };
static const InverterDescriptor _V33 =                    {THREE_PHASE , STRING, ON_GRID,  2, 33000 };
static const InverterDescriptor _V36 =                    {THREE_PHASE , STRING, ON_GRID,  2, 36000 };
static const InverterDescriptor _V40 =                    {THREE_PHASE , STRING, ON_GRID,  2, 40000 };
static const InverterDescriptor _V50 =                    {THREE_PHASE , STRING, ON_GRID,  2, 50000 };
static const InverterDescriptor _V60 =                    {THREE_PHASE , STRING, ON_GRID,  2, 60000 };
static const InverterDescriptor _V75 =                    {THREE_PHASE , STRING, ON_GRID,  2, 75000 };
static const InverterDescriptor _VL15 =                   {THREE_PHASE , STRING, ON_GRID,  2, 15000 };
static const InverterDescriptor _VL20 =                   {THREE_PHASE , STRING, ON_GRID,  2, 20000 };
static const InverterDescriptor _VL25 =                   {THREE_PHASE , STRING, ON_GRID,  2, 25000 };
static const InverterDescriptor _VL30 =                   {THREE_PHASE , STRING, ON_GRID,  2, 30000 };
static const InverterDescriptor _VL37_5 =                 {THREE_PHASE , STRING, ON_GRID,  2, 37500 };
static const InverterDescriptor _R75 =                    {THREE_PHASE , STRING, ON_GRID,  2, 75000 };
static const InverterDescriptor _R100 =                   {THREE_PHASE , STRING, ON_GRID,  2, 100000 };
static const InverterDescriptor _R110 =                   {THREE_PHASE , STRING, ON_GRID,  2, 110000 };
static const InverterDescriptor _GW3000_XS =              {SINGLE_PHASE, STRING, ON_GRID,  2, 3000 };
static const InverterDescriptor _GW3300_XS_30 =           {SINGLE_PHASE, STRING, ON_GRID,  2, 3300 };
static const InverterDescriptor _GW5000_DNS =             {SINGLE_PHASE, STRING, ON_GRID,  2, 5000 };
static const InverterDescriptor _GW5K_DNS_G40 =           {SINGLE_PHASE, STRING, ON_GRID,  2, 5000 };
static const InverterDescriptor _SUN2000_2KTL =           {SINGLE_PHASE, STRING, ON_GRID,  2, 2000 };
static const InverterDescriptor _SUN2000_3KTL =           {SINGLE_PHASE, STRING, ON_GRID,  2, 3000 };
static const InverterDescriptor _SUN2000_4KTL =           {SINGLE_PHASE, STRING, ON_GRID,  2, 4000 };
static const InverterDescriptor _SUN2000_5KTL =           {SINGLE_PHASE, STRING, ON_GRID,  2, 5000 };
static const InverterDescriptor _SUN2000_6KTL =           {SINGLE_PHASE, STRING, ON_GRID,  2, 6000 };
static const InverterDescriptor _SUN2000_12KTL_M0 =       {THREE_PHASE , STRING, ON_GRID,  2, 12000 };
static const InverterDescriptor _SUN2000_12KTL_M2 =       {THREE_PHASE , STRING, ON_GRID,  2, 12000 };
static const InverterDescriptor _SUN2000_15KTL_M0 =       {THREE_PHASE , STRING, ON_GRID,  2, 15000 };
static const InverterDescriptor _SUN2000_15KTL_M2 =       {THREE_PHASE , STRING, ON_GRID,  2, 15000 };
static const InverterDescriptor _SUN2000_20KTL_M0 =       {THREE_PHASE , STRING, ON_GRID,  2, 20000 };
static const InverterDescriptor _SUN2000_20KTL_M2 =       {THREE_PHASE , STRING, ON_GRID,  2, 20000 };
static const InverterDescriptor _SUN2000_33KTL_A =        {THREE_PHASE , STRING, ON_GRID,  2, 33000 };
static const InverterDescriptor _SUN2000_36KTL_A =        {THREE_PHASE , STRING, ON_GRID,  2, 36000 };
static const InverterDescriptor _SUN2000_30KTL_M3 =       {THREE_PHASE , STRING, ON_GRID,  2, 30000 };
static const InverterDescriptor _SUN2000_36KTL_M3 =       {THREE_PHASE , STRING, ON_GRID,  2, 36000 };
static const InverterDescriptor _SUN2000_40KTL_M3 =       {THREE_PHASE , STRING, ON_GRID,  2, 40000 };
static const InverterDescriptor _SUN2000_60KTL_M0 =       {THREE_PHASE , STRING, ON_GRID,  2, 60000 };
static const InverterDescriptor _SUN2000_75KTL_M1 =       {THREE_PHASE , STRING, ON_GRID,  2, 75000 };
static const InverterDescriptor _SUN2000_100KTL_M2 =      {THREE_PHASE , STRING, ON_GRID,  2, 100000 };
static const InverterDescriptor _SUN2000_100KTL_H1 =      {THREE_PHASE , STRING, ON_GRID,  2, 100000 };
static const InverterDescriptor _SUN2000_215KTL_H0 =      {THREE_PHASE , STRING, ON_GRID,  2, 215000 };
static const InverterDescriptor _SUN2000_215KTL_H3 =      {THREE_PHASE , STRING, ON_GRID,  2, 215000 };
static const InverterDescriptor _SUN2000_250KTL_H1 =      {THREE_PHASE , STRING, ON_GRID,  2, 250000 };

const InverterDescriptor* getDescriptor(InverterModel model) {
    switch (model) {
        case ​​​​​​​​​​​​​​SIW100G_M010_W00:
            return &_​​​​​​​​​​​​​​SIW100G_M010_W00;
        case ​​​​​​​​​​​​​​SIW100G_M024_W10:
            return &_​​​​​​​​​​​​​​SIW100G_M024_W10;
        case SIW200_M030:
            return &_SIW200_M030;
        case SIW200_M050:
            return &_SIW200_M050;
        case SIW200_M085:
            return &_SIW200_M085;
        case SIW200_M100:
            return &_SIW200_M100;
        case SIW200H_M050_W00:
            return &_SIW200H_M050_W00;
        case SIW200H_M075_W10:
            return &_SIW200H_M075_W10;
        case SIW200H_M105_W10:
            return &_SIW200H_M105_W10;
        case SIW200G_M030_W0:
            return &_SIW200G_M030_W0;
        case SIW200G_M030_W1:
            return &_SIW200G_M030_W1;
        case SIW200G_M050_W0:
            return &_SIW200G_M050_W0;
        case SIW200G_M050_W1:
            return &_SIW200G_M050_W1;
        case SIW200G_M060_W0:
            return &_SIW200G_M060_W0;
        case SIW200G_M060_W1:
            return &_SIW200G_M060_W1;
        case SIW200G_M070_W1:
            return &_SIW200G_M070_W1;
        case SIW200G_M075_W1:
            return &_SIW200G_M075_W1;
        case SIW200G_M080_W1:
            return &_SIW200G_M080_W1;
        case SIW200G_M090_W1:
            return &_SIW200G_M090_W1;
        case SIW200G_M105_W1:
            return &_SIW200G_M105_W1;
        case SIW300H_M030_W00:
            return &_SIW300H_M030_W00;
        case SIW300H_M050_W00:
            return &_SIW300H_M050_W00;
        case SIW300H_M060_W00:
            return &_SIW300H_M060_W00;
        case SIW300H_M075_W00:
            return &_SIW300H_M075_W00;
        case SIW300H_M080_W00:
            return &_SIW300H_M080_W00;
        case SIW300H_M100_W00:
            return &_SIW300H_M100_W00;
        case SIW400_ST075:
            return &_SIW400_ST075;
        case SIW400G_T012_W0:
            return &_SIW400G_T012_W0;
        case SIW400G_T012_W1:
            return &_SIW400G_T012_W1;
        case SIW400G_T015_W0:
            return &_SIW400G_T015_W0;
        case SIW400G_T015_W1:
            return &_SIW400G_T015_W1;
        case SIW400G_T020_W0:
            return &_SIW400G_T020_W0;
        case SIW400G_T020_W1:
            return &_SIW400G_T020_W1;
        case SIW400G_T025_W0:
            return &_SIW400G_T025_W0;
        case SIW400G_T025_W1:
            return &_SIW400G_T025_W1;
        case SIW400G_T075_W0:
            return &_SIW400G_T075_W0;
        case SIW400G_T100_W0:
            return &_SIW400G_T100_W0;
        case SIW400G_T050_W00:
            return &_SIW400G_T050_W00;
        case SIW400G_T060_W00:
            return &_SIW400G_T060_W00;
        case SIW400G_T075_W01:
            return &_SIW400G_T075_W01;
        case SIW400G_K015_W00:
            return &_SIW400G_K015_W00;
        case SIW400G_K020_W00:
            return &_SIW400G_K020_W00;
        case SIW400G_K025_W00:
            return &_SIW400G_K025_W00;
        case SIW400G_K030_W00:
            return &_SIW400G_K030_W00;
        case SIW400G_K037_W00:
            return &_SIW400G_K037_W00;
        case SIW400H_T015_W10:
            return &_SIW400H_T015_W10;
        case SIW400H_T030_W10:
            return &_SIW400H_T030_W10;
        case SIW420G_K025_W00:
            return &_SIW420G_K025_W00;
        case SIW420G_K075_W00:
            return &_SIW420G_K075_W00;
        case SIW500G_T075_W0:
            return &_SIW500G_T075_W0;
        case SIW500G_T100_W0:
            return &_SIW500G_T100_W0;
        case SIW500G_K050_W00:
            return &_SIW500G_K050_W00;
        case SIW500G_K075_W00:
            return &_SIW500G_K075_W00;
        case SIW500G_H250_W0:
            return &_SIW500G_H250_W0;
        case SIW500H_ST012_M2:
            return &_SIW500H_ST012_M2;
        case SIW500H_ST015_M2:
            return &_SIW500H_ST015_M2;
        case SIW500H_ST020_M2:
            return &_SIW500H_ST020_M2;
        case SIW500H_ST030_M3:
            return &_SIW500H_ST030_M3;
        case SIW500H_ST036_M3:
            return &_SIW500H_ST036_M3;
        case SIW500H_ST040_M3:
            return &_SIW500H_ST040_M3;
        case SIW500H_SK020:
            return &_SIW500H_SK020;
        case SIW500H_ST030:
            return &_SIW500H_ST030;
        case SIW500H_ST036:
            return &_SIW500H_ST036;
        case SIW500H_ST040:
            return &_SIW500H_ST040;
        case SIW500H_ST060:
            return &_SIW500H_ST060;
        case SIW500H_ST100:
            return &_SIW500H_ST100;
        case SIW500H_ST060_HV:
            return &_SIW500H_ST060_HV;
        case SIW500H_ST100_HV:
            return &_SIW500H_ST100_HV;
        case SIW500H_ST200_H0:
            return &_SIW500H_ST200_H0;
        case SIW500H_ST200_H3:
            return &_SIW500H_ST200_H3;
        case SIW500H_T012_W00:
            return &_SIW500H_T012_W00;
        case SIW500H_T015_W00:
            return &_SIW500H_T015_W00;
        case SIW500H_T017_W00:
            return &_SIW500H_T017_W00;
        case SIW500H_T020_W00:
            return &_SIW500H_T020_W00;
        case SIW500H_T025_W00:
            return &_SIW500H_T025_W00;
        case SIW600_T020_44:
            return &_SIW600_T020_44;
        case SIW610_T018_W0:
            return &_SIW610_T018_W0;
        case SIW610_T075_W0:
            return &_SIW610_T075_W0;
        case S700_G2:
            return &_S700_G2;
        case S1000_G2:
            return &_S1000_G2;
        case S1500_G2:
            return &_S1500_G2;
        case S2000_G2:
            return &_S2000_G2;
        case S2500_G2:
            return &_S2500_G2;
        case S3000_G2:
            return &_S3000_G2;
        case S3300_G2:
            return &_S3300_G2;
        case F3000_G2:
            return &_F3000_G2;
        case F3600_G2:
            return &_F3600_G2;
        case F4600_G2:
            return &_F4600_G2;
        case F5000_G2:
            return &_F5000_G2;
        case F5300_G2:
            return &_F5300_G2;
        case F6000_G2:
            return &_F6000_G2;
        case G7:
            return &_G7;
        case G7_5:
            return &_G7_5;
        case G8_:
            return &_G8_;
        case G9:
            return &_G9;
        case G10:
            return &_G10;
        case G10_5:
            return &_G10_5;
        case T3_G3:
            return &_T3_G3;
        case T4_G3:
            return &_T4_G3;
        case T5_G3:
            return &_T5_G3;
        case T6_G3:
            return &_T6_G3;
        case T8_G3:
            return &_T8_G3;
        case T10_G3:
            return &_T10_G3;
        case T12_G3:
            return &_T12_G3;
        case T15_G3:
            return &_T15_G3;
        case T17_G3:
            return &_T17_G3;
        case T20_G3:
            return &_T20_G3;
        case T23_G3:
            return &_T23_G3;
        case T25_G3:
            return &_T25_G3;
        case V30:
            return &_V30;
        case V33:
            return &_V33;
        case V36:
            return &_V36;
        case V40:
            return &_V40;
        case V50:
            return &_V50;
        case V60:
            return &_V60;
        case V75:
            return &_V75;
        case VL15:
            return &_VL15;
        case VL20:
            return &_VL20;
        case VL25:
            return &_VL25;
        case VL30:
            return &_VL30;
        case VL37_5:
            return &_VL37_5;
        case R75:
            return &_R75;
        case R100:
            return &_R100;
        case R110:
            return &_R110;
        case GW3000_XS:
            return &_GW3000_XS;
        case GW3300_XS_30:
            return &_GW3300_XS_30;
        case GW5000_DNS:
            return &_GW5000_DNS;
        case GW5K_DNS_G40:
            return &_GW5K_DNS_G40;
        case SUN2000_2KTL:
            return &_SUN2000_2KTL;
        case SUN2000_3KTL:
            return &_SUN2000_3KTL;
        case SUN2000_4KTL:
            return &_SUN2000_4KTL;
        case SUN2000_5KTL:
            return &_SUN2000_5KTL;
        case SUN2000_6KTL:
            return &_SUN2000_6KTL;
        case SUN2000_12KTL_M0:
            return &_SUN2000_12KTL_M0;
        case SUN2000_12KTL_M2:
            return &_SUN2000_12KTL_M2;
        case SUN2000_15KTL_M0:
            return &_SUN2000_15KTL_M0;
        case SUN2000_15KTL_M2:
            return &_SUN2000_15KTL_M2;
        case SUN2000_20KTL_M0:
            return &_SUN2000_20KTL_M0;
        case SUN2000_20KTL_M2:
            return &_SUN2000_20KTL_M2;
        case SUN2000_30KTL:
            return &_SUN2000_33KTL_A;
        case SUN2000_36KTL_A:
            return &_SUN2000_36KTL_A;
        case SUN2000_30KTL_M3:
            return &_SUN2000_30KTL_M3;
        case SUN2000_36KTL_M3:
            return &_SUN2000_36KTL_M3;
        case SUN2000_40KTL_M3:
            return &_SUN2000_40KTL_M3;
        case SUN2000_60KTL_M0:
            return &_SUN2000_60KTL_M0;
        case SUN2000_75KTL_M1:
            return &_SUN2000_75KTL_M1;
        case SUN2000_100KTL_M2:
            return &_SUN2000_100KTL_M2;
        case SUN2000_100KTL_H1:
            return &_SUN2000_100KTL_H1;
        case SUN2000_215KTL_H0:
            return &_SUN2000_215KTL_H0;
        case SUN2000_215KTL_H3:
            return &_SUN2000_215KTL_H3;
        case SUN2000_250KTL_H1:
            return &_SUN2000_250KTL_H1;
    }
}