#include <Arduino.h>
#include "Inverter.h"

Inverter myInverter(SIW200H_M050_W00);

void setup() {
    Serial.begin(115200);
    delay(1000);

    myInverter.modbus.setId(1);
    myInverter.modbus.setBaud(9600);

    Serial.print("Modbus ID: ");
    Serial.println(myInverter.modbus.getId());

    Serial.print("Baud rate: ");
    Serial.println(myInverter.modbus.getBaud());

    float power = myInverter.getPower();
    Serial.print("Power: ");
    Serial.println(power);

    bool ok = myInverter.setMaxPower(4500);
    Serial.print("setMaxPower result: ");
    Serial.println(ok ? "OK" : "FAIL");
}

void loop() {
}