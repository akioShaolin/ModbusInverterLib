/*
  InverterModbusLib - Full Web Panel Example
  ------------------------------------------------------------
  Example for ESP8266 / ESP-07 using WiFi AP + WebServer + RS485/Modbus RTU.

  What this example does:
  - Creates a WiFi access point.
  - Shows a web page with one section for each public function of the library.
  - Provides GET buttons for read-only functions.
  - Provides input fields or toggle buttons for write functions.
  - Provides a separate configuration page for inverter model and Modbus/UART settings.

  Important notes:
  - Write functions change real inverter parameters. Use carefully.
  - On ESP8266, the main UART is often used for RS485/Modbus. Avoid Serial.print()
    while Modbus is active, because it can interfere with the RS485 bus.
  - The library is expected to apply Serial.begin(), mb.begin() and mb.master()
    internally through ModbusConfig / ensureApplied() before Modbus transactions.
  - This example uses one active inverter object at a time. Reconfiguring the web page
    deletes the previous object and creates a new one with the selected model.
*/

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ModbusRTU.h>
#include <InverterModbusLib.h>

// ====================================================== 
// WiFi AP
// ====================================================== 

const char* AP_SSID = "ESP07-Inverter";
const char* AP_PASS = "12345678";

// ====================================================== 
// Modbus / RS485 defaults
// ====================================================== 

#define DEFAULT_DE_RE_PIN 12

ESP8266WebServer server(80);
ModbusRTU mb;

// Active inverter selected in the /config page.
Inverter* inverter = nullptr;

struct ModelOption {
  const char* label;
  InverterModel model;
};

ModelOption modelOptions[] = {
  {"SIW200_M030", SIW200_M030},
  {"SIW200_M050", SIW200_M050},
  {"SIW200_M085", SIW200_M085},
  {"SIW200_M100", SIW200_M100},
  {"SIW200H_M050_W00", SIW200H_M050_W00},
  {"SIW200H_M075_W10", SIW200H_M075_W10},
  {"SIW200H_M105_W10", SIW200H_M105_W10},
  {"SIW200G_M030_W0", SIW200G_M030_W0},
  {"SIW200G_M030_W1", SIW200G_M030_W1},
  {"SIW200G_M050_W0", SIW200G_M050_W0},
  {"SIW200G_M050_W1", SIW200G_M050_W1},
  {"SIW200G_M060_W0", SIW200G_M060_W0},
  {"SIW200G_M060_W1", SIW200G_M060_W1},
  {"SIW200G_M070_W1", SIW200G_M070_W1},
  {"SIW200G_M075_W1", SIW200G_M075_W1},
  {"SIW200G_M080_W1", SIW200G_M080_W1},
  {"SIW200G_M090_W1", SIW200G_M090_W1},
  {"SIW200G_M105_W1", SIW200G_M105_W1},
  {"SIW300H_M030_W00", SIW300H_M030_W00},
  {"SIW300H_M050_W00", SIW300H_M050_W00},
  {"SIW300H_M060_W00", SIW300H_M060_W00},
  {"SIW300H_M075_W00", SIW300H_M075_W00},
  {"SIW300H_M080_W00", SIW300H_M080_W00},
  {"SIW300H_M100_W00", SIW300H_M100_W00},
  {"SIW400_ST075", SIW400_ST075},
  {"SIW400G_T012_W0", SIW400G_T012_W0},
  {"SIW400G_T012_W1", SIW400G_T012_W1},
  {"SIW400G_T015_W0", SIW400G_T015_W0},
  {"SIW400G_T015_W1", SIW400G_T015_W1},
  {"SIW400G_T020_W0", SIW400G_T020_W0},
  {"SIW400G_T020_W1", SIW400G_T020_W1},
  {"SIW400G_T025_W0", SIW400G_T025_W0},
  {"SIW400G_T025_W1", SIW400G_T025_W1},
  {"SIW400G_T075_W0", SIW400G_T075_W0},
  {"SIW400G_T100_W0", SIW400G_T100_W0},
  {"SIW400G_T050_W00", SIW400G_T050_W00},
  {"SIW400G_T060_W00", SIW400G_T060_W00},
  {"SIW400G_T075_W01", SIW400G_T075_W01},
  {"SIW400G_K015_W00", SIW400G_K015_W00},
  {"SIW400G_K020_W00", SIW400G_K020_W00},
  {"SIW400G_K025_W00", SIW400G_K025_W00},
  {"SIW400G_K030_W00", SIW400G_K030_W00},
  {"SIW400G_K037_W00", SIW400G_K037_W00},
  {"SIW400H_T015_W10", SIW400H_T015_W10},
  {"SIW400H_T030_W10", SIW400H_T030_W10},
  {"SIW420G_K025_W00", SIW420G_K025_W00},
  {"SIW420G_K075_W00", SIW420G_K075_W00},
  {"SIW500G_T075_W0", SIW500G_T075_W0},
  {"SIW500G_T100_W0", SIW500G_T100_W0},
  {"SIW500G_K050_W00", SIW500G_K050_W00},
  {"SIW500G_K075_W00", SIW500G_K075_W00},
  {"SIW500G_H250_W0", SIW500G_H250_W0},
  {"SIW500H_ST012_M2", SIW500H_ST012_M2},
  {"SIW500H_ST015_M2", SIW500H_ST015_M2},
  {"SIW500H_ST020_M2", SIW500H_ST020_M2},
  {"SIW500H_ST030_M3", SIW500H_ST030_M3},
  {"SIW500H_ST036_M3", SIW500H_ST036_M3},
  {"SIW500H_ST040_M3", SIW500H_ST040_M3},
  {"SIW500H_SK020", SIW500H_SK020},
  {"SIW500H_ST030", SIW500H_ST030},
  {"SIW500H_ST036", SIW500H_ST036},
  {"SIW500H_ST040", SIW500H_ST040},
  {"SIW500H_ST060", SIW500H_ST060},
  {"SIW500H_ST100", SIW500H_ST100},
  {"SIW500H_ST060_HV", SIW500H_ST060_HV},
  {"SIW500H_ST100_HV", SIW500H_ST100_HV},
  {"SIW500H_ST200_H0", SIW500H_ST200_H0},
  {"SIW500H_ST200_H3", SIW500H_ST200_H3},
  {"SIW500H_T012_W00", SIW500H_T012_W00},
  {"SIW500H_T015_W00", SIW500H_T015_W00},
  {"SIW500H_T017_W00", SIW500H_T017_W00},
  {"SIW500H_T020_W00", SIW500H_T020_W00},
  {"SIW500H_T025_W00", SIW500H_T025_W00},
  {"SIW600_T020_44", SIW600_T020_44},
  {"SIW610_T018_W0", SIW610_T018_W0},
  {"SIW610_T075_W0", SIW610_T075_W0},
  {"S700_G2", S700_G2},
  {"S1000_G2", S1000_G2},
  {"S1500_G2", S1500_G2},
  {"S2000_G2", S2000_G2},
  {"S2500_G2", S2500_G2},
  {"S3000_G2", S3000_G2},
  {"S3300_G2", S3300_G2},
  {"F3000_G2", F3000_G2},
  {"F3600_G2", F3600_G2},
  {"F4600_G2", F4600_G2},
  {"F5000_G2", F5000_G2},
  {"F5300_G2", F5300_G2},
  {"F6000_G2", F6000_G2},
  {"G7", G7},
  {"G7_5", G7_5},
  {"G8_", G8_},
  {"G9", G9},
  {"G10", G10},
  {"G10_5", G10_5},
  {"T3_G3", T3_G3},
  {"T4_G3", T4_G3},
  {"T5_G3", T5_G3},
  {"T6_G3", T6_G3},
  {"T8_G3", T8_G3},
  {"T10_G3", T10_G3},
  {"T12_G3", T12_G3},
  {"T15_G3", T15_G3},
  {"T17_G3", T17_G3},
  {"T20_G3", T20_G3},
  {"T23_G3", T23_G3},
  {"T25_G3", T25_G3},
  {"V30", V30},
  {"V33", V33},
  {"V36", V36},
  {"V40", V40},
  {"V50", V50},
  {"V60", V60},
  {"V75", V75},
  {"VL15", VL15},
  {"VL20", VL20},
  {"VL25", VL25},
  {"VL30", VL30},
  {"VL37_5", VL37_5},
  {"R75", R75},
  {"R100", R100},
  {"R110", R110},
  {"GW3000_XS", GW3000_XS},
  {"GW3300_XS_30", GW3300_XS_30},
  {"GW5000_DNS", GW5000_DNS},
  {"GW5K_DNS_G40", GW5K_DNS_G40},
  {"GW8500_MS", GW8500_MS},
  {"GW10K_MS", GW10K_MS},
  {"SUN2000_2KTL", SUN2000_2KTL},
  {"SUN2000_3KTL", SUN2000_3KTL},
  {"SUN2000_4KTL", SUN2000_4KTL},
  {"SUN2000_5KTL", SUN2000_5KTL},
  {"SUN2000_6KTL", SUN2000_6KTL},
  {"SUN2000_12KTL_M0", SUN2000_12KTL_M0},
  {"SUN2000_12KTL_M2", SUN2000_12KTL_M2},
  {"SUN2000_15KTL_M0", SUN2000_15KTL_M0},
  {"SUN2000_15KTL_M2", SUN2000_15KTL_M2},
  {"SUN2000_20KTL_M0", SUN2000_20KTL_M0},
  {"SUN2000_20KTL_M2", SUN2000_20KTL_M2},
  {"SUN2000_30KTL", SUN2000_30KTL},
  {"SUN2000_36KTL_A", SUN2000_36KTL_A},
  {"SUN2000_30KTL_M3", SUN2000_30KTL_M3},
  {"SUN2000_36KTL_M3", SUN2000_36KTL_M3},
  {"SUN2000_40KTL_M3", SUN2000_40KTL_M3},
  {"SUN2000_60KTL_M0", SUN2000_60KTL_M0},
  {"SUN2000_75KTL_M1", SUN2000_75KTL_M1},
  {"SUN2000_100KTL_M2", SUN2000_100KTL_M2},
  {"SUN2000_100KTL_H1", SUN2000_100KTL_H1},
  {"SUN2000_215KTL_H0", SUN2000_215KTL_H0},
  {"SUN2000_215KTL_H3", SUN2000_215KTL_H3},
  {"SUN2000_250KTL_H1", SUN2000_250KTL_H1},
};

const uint16_t MODEL_COUNT = sizeof(modelOptions) / sizeof(modelOptions[0]);

uint16_t activeModelIndex = 0;
ModbusConfigData activeCfg = {1, 9600, SERIAL_8N1, DEFAULT_DE_RE_PIN};

// ====================================================== 
// Formatting helpers
// ====================================================== 

String escapeHtml(const String& input) {
  String out;
  for (uint16_t i = 0; i < input.length(); i++) {
    char c = input[i];
    if (c == '&') out += "&amp;";
    else if (c == '<') out += "&lt;";
    else if (c == '>') out += "&gt;";
    else if (c == '"') out += "&quot;";
    else out += c;
  }
  return out;
}

String boolText(bool v) {
  return v ? "true" : "false";
}

String okFail(bool ok) {
  return ok ? "OK" : "FALHA";
}

String phaseText(const PhaseData& p, const char* unit) {
  String s;
  s += "R: " + String(p.r, 3) + " " + unit + "<br>";
  s += "S: " + String(p.s, 3) + " " + unit + "<br>";
  s += "T: " + String(p.t, 3) + " " + unit;
  return s;
}

String stringValuesText(const StringValues& values, const char* unit) {
  String s = "Count: " + String(values.count) + "<br>";
  for (uint8_t i = 0; i < values.count; i++) {
    s += "String " + String(i + 1) + ": " + String(values.values[i], 3) + " " + unit + "<br>";
  }
  return s;
}

String batteryValuesText(const BatteryValues& values, const char* unit) {
  String s = "Count: " + String(values.count) + "<br>";
  for (uint8_t i = 0; i < values.count; i++) {
    s += "Battery " + String(i + 1) + ": " + String(values.values[i], 3) + " " + unit + "<br>";
  }
  return s;
}

String datetimeText(const Datetime& dt) {
  String s;
  s += String(dt.year) + "-";
  if (dt.month < 10) s += "0";
  s += String(dt.month) + "-";
  if (dt.day < 10) s += "0";
  s += String(dt.day) + " ";
  if (dt.hour < 10) s += "0";
  s += String(dt.hour) + ":";
  if (dt.minute < 10) s += "0";
  s += String(dt.minute) + ":";
  if (dt.second < 10) s += "0";
  s += String(dt.second);
  return s;
}

String serialConfigToText(uint32_t config) {
  if (config == SERIAL_8N1) return "SERIAL_8N1";
  if (config == SERIAL_8N2) return "SERIAL_8N2";
  if (config == SERIAL_8E1) return "SERIAL_8E1";
  if (config == SERIAL_8E2) return "SERIAL_8E2";
  if (config == SERIAL_8O1) return "SERIAL_8O1";
  if (config == SERIAL_8O2) return "SERIAL_8O2";
  return "UNKNOWN";
}

uint32_t makeSerialConfig(char parity, uint8_t stopBits) {
  if (parity == 'N' && stopBits == 1) return SERIAL_8N1;
  if (parity == 'N' && stopBits == 2) return SERIAL_8N2;
  if (parity == 'E' && stopBits == 1) return SERIAL_8E1;
  if (parity == 'E' && stopBits == 2) return SERIAL_8E2;
  if (parity == 'O' && stopBits == 1) return SERIAL_8O1;
  if (parity == 'O' && stopBits == 2) return SERIAL_8O2;
  return SERIAL_8N1;
}

String pageHeader(const String& title) {
  String html;
  html += "<!DOCTYPE html><html><head><meta charset='UTF-8'>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<title>" + title + "</title>";
  html += "<style>";
  html += "body{font-family:Arial,Helvetica,sans-serif;background:#f4f6f8;margin:0;color:#222;}";
  html += "header{background:#0b3d5c;color:white;padding:16px 20px;}";
  html += "header h1{font-size:22px;margin:0 0 10px 0;}";
  html += "nav a{display:inline-block;color:white;text-decoration:none;background:#1565c0;padding:8px 12px;border-radius:8px;margin-right:8px;}";
  html += ".wrap{max-width:1180px;margin:0 auto;padding:18px;}";
  html += ".status{background:#fff;border-left:5px solid #1565c0;padding:12px;border-radius:10px;margin-bottom:16px;box-shadow:0 1px 5px rgba(0,0,0,.08);}";
  html += ".grid{display:grid;grid-template-columns:repeat(auto-fit,minmax(280px,1fr));gap:14px;}";
  html += ".card{background:white;border-radius:12px;padding:14px;box-shadow:0 2px 8px rgba(0,0,0,.12);}";
  html += ".card h2{font-size:17px;margin:0 0 10px 0;color:#0b3d5c;}";
  html += "form{margin:0 0 10px 0;}";
  html += "label{display:block;font-size:13px;font-weight:bold;margin-top:8px;margin-bottom:4px;}";
  html += "input,select{width:100%;box-sizing:border-box;padding:9px;border:1px solid #bbb;border-radius:8px;font-size:15px;background:white;}";
  html += "button,.btn{display:inline-block;width:100%;box-sizing:border-box;border:0;border-radius:8px;background:#1565c0;color:white;padding:10px 12px;font-size:15px;font-weight:bold;text-align:center;text-decoration:none;cursor:pointer;}";
  html += ".danger button{background:#b3261e;}";
  html += ".toggle button{background:#5b2da0;}";
  html += ".display{background:#eef3f7;border-radius:8px;padding:10px;min-height:42px;line-height:1.45;margin-top:10px;font-size:14px;overflow-wrap:anywhere;}";
  html += ".ok{border-left:5px solid #16833a;}.fail{border-left:5px solid #b3261e;}";
  html += ".small{font-size:12px;color:#666;line-height:1.4;}";
  html += ".row{display:grid;grid-template-columns:1fr 1fr;gap:10px;}";
  html += "@media(max-width:700px){.row{grid-template-columns:1fr;}}";
  html += "</style></head><body>";
  html += "<header><h1>" + title + "</h1><nav><a href='/'>Painel</a><a href='/config'>Configuração</a></nav></header>";
  html += "<div class='wrap'>";
  return html;
}


String pageFooter() {
  return "</div></body></html>";
}

String resultDisplay(const String& fn, const String& currentFn, const String& result) {
  if (fn == currentFn) return "<div class='display'>" + result + "</div>";
  return "<div class='display small'>Aguardando leitura/comando.</div>";
}

void addCard(String& html, const String& title, const String& body) {
  html += "<div class='card'><h2>" + title + "</h2>" + body + "</div>";
}

String getForm(const char* label, const char* fn) {
  String html;
  html += "<form action='/get' method='GET'>";
  html += "<input type='hidden' name='fn' value='" + String(fn) + "'>";
  html += "<button type='submit'>" + String(label) + "</button>";
  html += "</form>";
  return html;
}

String setFloatForm(const char* label, const char* fn, const char* unit, const char* placeholder) {
  String html;
  html += "<form action='/set' method='GET'>";
  html += "<input type='hidden' name='fn' value='" + String(fn) + "'>";
  html += "<label>Valor (" + String(unit) + ")</label>";
  html += "<input type='number' step='0.001' name='value' placeholder='" + String(placeholder) + "'>";
  html += "<button type='submit'>" + String(label) + "</button>";
  html += "</form>";
  return html;
}

String setUIntForm(const char* label, const char* fn, const char* placeholder) {
  String html;
  html += "<form action='/set' method='GET'>";
  html += "<input type='hidden' name='fn' value='" + String(fn) + "'>";
  html += "<label>Valor</label>";
  html += "<input type='number' step='1' name='value' placeholder='" + String(placeholder) + "'>";
  html += "<button type='submit'>" + String(label) + "</button>";
  html += "</form>";
  return html;
}

String setBoolForm(const char* label, const char* fn) {
  String html;
  html += "<form action='/set' method='GET'>";
  html += "<input type='hidden' name='fn' value='" + String(fn) + "'>";
  html += "<label>Estado</label>";
  html += "<select name='value'><option value='1'>true / habilitar</option><option value='0'>false / desabilitar</option></select>";
  html += "<button type='submit'>" + String(label) + "</button>";
  html += "</form>";
  return html;
}

String actionButton(const char* label, const char* fn, bool danger = false) {
  String html;
  html += danger ? "<div class='danger'>" : "";
  html += "<form action='/set' method='GET'>";
  html += "<input type='hidden' name='fn' value='" + String(fn) + "'>";
  html += "<button type='submit'>" + String(label) + "</button>";
  html += "</form>";
  html += danger ? "</div>" : "";
  return html;
}

// ====================================================== 
// Inverter configuration
// ====================================================== 

bool configureActiveInverter(uint16_t modelIndex, const ModbusConfigData& cfg) {
  if (modelIndex >= MODEL_COUNT) return false;

  if (inverter != nullptr) {
    delete inverter;
    inverter = nullptr;
  }

  inverter = new Inverter(modelOptions[modelIndex].model);
  if (inverter == nullptr) return false;

  activeModelIndex = modelIndex;
  activeCfg = cfg;

  inverter->attachModbus(mb);
  inverter->attachSerial(Serial);
  inverter->attachConfig(activeCfg);

  return inverter->begin();
}

bool ensureInverterConfigured() {
  if (inverter != nullptr) return true;
  return configureActiveInverter(activeModelIndex, activeCfg);
}

// ====================================================== 
// Pages
// ====================================================== 

String buildMainPage(const String& activeFn = "", const String& result = "") {
  ensureInverterConfigured();

  String html = pageHeader("InverterModbusLib - Web Panel");

  html += "<div class='status'>";
  html += "<b>Modelo ativo:</b> " + String(modelOptions[activeModelIndex].label) + "<br>";
  html += "<b>Slave ID:</b> " + String(activeCfg.id) + " | <b>Baud:</b> " + String(activeCfg.baud);
  html += " | <b>Serial:</b> " + serialConfigToText(activeCfg.serialConfig);
  html += " | <b>DE/RE:</b> GPIO " + String(activeCfg.deRePin);
  html += "<div class='small'>Use a página de configuração para alterar modelo, ID e parâmetros Modbus/UART.</div>";
  html += "</div>";

  html += "<div class='grid'>";

  addCard(html, "Identificação", getForm("Ler número serial", "getSerialNumber") + resultDisplay("getSerialNumber", activeFn, result));

  String control;
  control += getForm("isBooted", "isBooted") + resultDisplay("isBooted", activeFn, result);
  control += getForm("isPowerLimitEnabled", "isPowerLimitEnabled") + resultDisplay("isPowerLimitEnabled", activeFn, result);
  control += getForm("getPowerLimit", "getPowerLimit") + resultDisplay("getPowerLimit", activeFn, result);
  control += getForm("getPowerLimitPercent", "getPowerLimitPercent") + resultDisplay("getPowerLimitPercent", activeFn, result);
  control += getForm("isExportLimitEnabled", "isExportLimitEnabled") + resultDisplay("isExportLimitEnabled", activeFn, result);
  control += getForm("getExportLimit", "getExportLimit") + resultDisplay("getExportLimit", activeFn, result);
  control += getForm("getExportLimitPercent", "getExportLimitPercent") + resultDisplay("getExportLimitPercent", activeFn, result);
  control += getForm("isPowerFactorEnabled", "isPowerFactorEnabled") + resultDisplay("isPowerFactorEnabled", activeFn, result);
  control += getForm("getPowerFactorSetpoint", "getPowerFactorSetpoint") + resultDisplay("getPowerFactorSetpoint", activeFn, result);
  addCard(html, "Leituras - Controle e Limites", control);

  String controlSet;
  controlSet += actionButton("boot()", "boot");
  controlSet += actionButton("shutdown()", "shutdown", true);
  controlSet += setBoolForm("setBoot", "setBoot");
  controlSet += setBoolForm("setPowerLimitEnabled", "setPowerLimitEnabled");
  controlSet += setFloatForm("setPowerLimit", "setPowerLimit", "W", "3000");
  controlSet += setFloatForm("setPowerLimitPercent", "setPowerLimitPercent", "%", "80");
  controlSet += setBoolForm("setExportLimitEnabled", "setExportLimitEnabled");
  controlSet += setFloatForm("setExportLimit", "setExportLimit", "W", "1000");
  controlSet += setFloatForm("setExportLimitPercent", "setExportLimitPercent", "%", "10");
  controlSet += setBoolForm("setPowerFactorEnabled", "setPowerFactorEnabled");
  controlSet += setFloatForm("setPowerFactor", "setPowerFactor", "PF", "0.98");
  controlSet += "<form action='/set' method='GET'><input type='hidden' name='fn' value='setPowerFactorExcitationMode'><label>Modo de excitação</label><select name='value'><option value='0'>LAGGING</option><option value='1'>LEADING</option><option value='2'>INDUCTIVE</option><option value='3'>CAPACITIVE</option><option value='4'>OVER_EXCITED</option><option value='5'>UNDER_EXCITED</option></select><button type='submit'>setPowerFactorExcitationMode</button></form>";
  controlSet += resultDisplay("set", activeFn, result);
  addCard(html, "Escritas - Controle e Limites", controlSet);

  String timeGet;
  timeGet += getForm("getDatetime", "getDatetime") + resultDisplay("getDatetime", activeFn, result);
  timeGet += getForm("getYear", "getYear") + resultDisplay("getYear", activeFn, result);
  timeGet += getForm("getMonth", "getMonth") + resultDisplay("getMonth", activeFn, result);
  timeGet += getForm("getDay", "getDay") + resultDisplay("getDay", activeFn, result);
  timeGet += getForm("getHour", "getHour") + resultDisplay("getHour", activeFn, result);
  timeGet += getForm("getMinute", "getMinute") + resultDisplay("getMinute", activeFn, result);
  timeGet += getForm("getSecond", "getSecond") + resultDisplay("getSecond", activeFn, result);
  timeGet += getForm("getEpochTime", "getEpochTime") + resultDisplay("getEpochTime", activeFn, result);
  addCard(html, "Leituras - Data/Hora", timeGet);

  String timeSet;
  timeSet += "<form action='/set' method='GET'><input type='hidden' name='fn' value='setDatetime'><div class='row'><div><label>Ano</label><input name='year' type='number' value='2026'></div><div><label>Mês</label><input name='month' type='number' value='1'></div><div><label>Dia</label><input name='day' type='number' value='1'></div><div><label>Hora</label><input name='hour' type='number' value='12'></div><div><label>Minuto</label><input name='minute' type='number' value='0'></div><div><label>Segundo</label><input name='second' type='number' value='0'></div></div><button type='submit'>setDatetime</button></form>";
  timeSet += setUIntForm("setYear", "setYear", "2026");
  timeSet += setUIntForm("setMonth", "setMonth", "1");
  timeSet += setUIntForm("setDay", "setDay", "1");
  timeSet += setUIntForm("setHour", "setHour", "12");
  timeSet += setUIntForm("setMinute", "setMinute", "0");
  timeSet += setUIntForm("setSecond", "setSecond", "0");
  timeSet += setUIntForm("setEpochTime", "setEpochTime", "1767225600");
  timeSet += resultDisplay("setTime", activeFn, result);
  addCard(html, "Escritas - Data/Hora", timeSet);

  String ac;
  ac += getForm("getActivePower", "getActivePower") + resultDisplay("getActivePower", activeFn, result);
  ac += getForm("getReactivePower", "getReactivePower") + resultDisplay("getReactivePower", activeFn, result);
  ac += getForm("getApparentPower", "getApparentPower") + resultDisplay("getApparentPower", activeFn, result);
  ac += getForm("getPowerFactor", "getPowerFactor") + resultDisplay("getPowerFactor", activeFn, result);
  ac += getForm("getGridVoltage", "getGridVoltage") + resultDisplay("getGridVoltage", activeFn, result);
  ac += getForm("getGridCurrent", "getGridCurrent") + resultDisplay("getGridCurrent", activeFn, result);
  ac += getForm("getGridFrequency", "getGridFrequency") + resultDisplay("getGridFrequency", activeFn, result);
  addCard(html, "Medições AC", ac);

  String energy;
  energy += getForm("getTotalEnergy", "getTotalEnergy") + resultDisplay("getTotalEnergy", activeFn, result);
  energy += getForm("getDailyEnergy", "getDailyEnergy") + resultDisplay("getDailyEnergy", activeFn, result);
  addCard(html, "Energia", energy);

  String strings;
  strings += getForm("getStringVoltage", "getStringVoltage") + resultDisplay("getStringVoltage", activeFn, result);
  strings += getForm("getStringCurrent", "getStringCurrent") + resultDisplay("getStringCurrent", activeFn, result);
  strings += getForm("getStringPower", "getStringPower") + resultDisplay("getStringPower", activeFn, result);
  addCard(html, "Strings FV", strings);

  String battery;
  battery += getForm("getBatteryVoltage", "getBatteryVoltage") + resultDisplay("getBatteryVoltage", activeFn, result);
  battery += getForm("getBatteryCurrent", "getBatteryCurrent") + resultDisplay("getBatteryCurrent", activeFn, result);
  battery += getForm("getBatteryPower", "getBatteryPower") + resultDisplay("getBatteryPower", activeFn, result);
  battery += getForm("getBatterySoC", "getBatterySoC") + resultDisplay("getBatterySoC", activeFn, result);
  battery += getForm("getBatterySoH", "getBatterySoH") + resultDisplay("getBatterySoH", activeFn, result);
  addCard(html, "Bateria", battery);

  String eps;
  eps += getForm("getEPSVoltage", "getEPSVoltage") + resultDisplay("getEPSVoltage", activeFn, result);
  eps += getForm("getEPSCurrent", "getEPSCurrent") + resultDisplay("getEPSCurrent", activeFn, result);
  eps += getForm("getEPSActivePower", "getEPSActivePower") + resultDisplay("getEPSActivePower", activeFn, result);
  addCard(html, "EPS", eps);

  String health;
  health += getForm("getTemperature", "getTemperature") + resultDisplay("getTemperature", activeFn, result);
  health += getForm("getInsulationResistance", "getInsulationResistance") + resultDisplay("getInsulationResistance", activeFn, result);
  addCard(html, "Diagnóstico e Saúde", health);

  String status;
  status += getForm("getInverterStatus", "getInverterStatus") + resultDisplay("getInverterStatus", activeFn, result);
  status += getForm("getAlarm", "getAlarm") + resultDisplay("getAlarm", activeFn, result);
  addCard(html, "Status e Alarmes", status);

  html += "</div>";
  html += pageFooter();
  return html;
}

String buildConfigPage(const String& message = "") {
  String html = pageHeader("Configuração Modbus");

  if (message.length() > 0) {
    html += "<div class='status'>" + message + "</div>";
  }

  html += "<div class='card'>";
  html += "<form action='/config/apply' method='GET'>";

  html += "<label>Modelo do inversor</label>";
  html += "<select name='model'>";
  for (uint16_t i = 0; i < MODEL_COUNT; i++) {
    html += "<option value='" + String(i) + "'";
    if (i == activeModelIndex) html += " selected";
    html += ">" + String(i) + " - " + String(modelOptions[i].label) + "</option>";
  }
  html += "</select>";

  html += "<div class='row'>";
  html += "<div><label>Slave ID</label><input type='number' name='id' min='1' max='247' value='" + String(activeCfg.id) + "'></div>";
  html += "<div><label>Baud rate</label><select name='baud'>";
  uint32_t bauds[] = {1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200};
  for (uint8_t i = 0; i < sizeof(bauds) / sizeof(bauds[0]); i++) {
    html += "<option value='" + String(bauds[i]) + "'";
    if (bauds[i] == activeCfg.baud) html += " selected";
    html += ">" + String(bauds[i]) + "</option>";
  }
  html += "</select></div>";

  html += "<div><label>Paridade</label><select name='parity'>";
  html += "<option value='N'>None</option><option value='E'>Even</option><option value='O'>Odd</option>";
  html += "</select></div>";

  html += "<div><label>Stop bits</label><select name='stopBits'>";
  html += "<option value='1'>1</option><option value='2'>2</option>";
  html += "</select></div>";

  html += "<div><label>Pino DE/RE</label><input type='number' name='dere' min='-1' max='16' value='" + String(activeCfg.deRePin) + "'></div>";
  html += "</div>";

  html += "<p class='small'>Data bits fixo em 8. Use DE/RE = -1 apenas se não houver controle RS485 por pino.</p>";
  html += "<button type='submit'>Atualizar Serial/Modbus</button>";
  html += "</form>";
  html += "</div>";
  html += pageFooter();
  return html;
}

// ====================================================== 
// HTTP handlers
// ====================================================== 

void handleRoot() {
  server.send(200, "text/html", buildMainPage());
}

void handleConfig() {
  server.send(200, "text/html", buildConfigPage());
}


void handleConfigApply() {
  uint16_t modelIndex = server.hasArg("model") ? server.arg("model").toInt() : activeModelIndex;
  int idRaw = server.hasArg("id") ? server.arg("id").toInt() : activeCfg.id;
  uint8_t id = 1;

  if (idRaw < 1) id = 1;
  else if (idRaw > 247) id = 247;
  else id = (uint8_t)idRaw;

  uint32_t baud = server.hasArg("baud") ? server.arg("baud").toInt() : activeCfg.baud;
  char parity = server.hasArg("parity") ? server.arg("parity")[0] : 'N';
  uint8_t stopBits = server.hasArg("stopBits") ? server.arg("stopBits").toInt() : 1;
  int8_t deRePin = server.hasArg("dere") ? server.arg("dere").toInt() : DEFAULT_DE_RE_PIN;

  ModbusConfigData cfg = {
    id,
    baud,
    (SerialConfig)makeSerialConfig(parity, stopBits),
    deRePin
  };

  bool ok = configureActiveInverter(modelIndex, cfg);

  if (!ok) {
    server.send(200, "text/html", buildConfigPage("Falha ao aplicar configuração. Verifique o modelo e os parâmetros Modbus."));
    return;
  }

  // Depois de atualizar modelo/UART/Modbus, volta para a tela principal.
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleGet() {
  if (!ensureInverterConfigured()) {
    server.send(200, "text/html", buildMainPage("config", "Falha ao configurar inversor."));
    return;
  }

  String fn = server.arg("fn");
  String result;
  bool ok = false;

  if (fn == "getSerialNumber") { String v; ok = inverter->getSerialNumber(v); result = ok ? escapeHtml(v) : "Falha"; }
  else if (fn == "isBooted") { bool v; ok = inverter->isBooted(v); result = ok ? boolText(v) : "Falha"; }
  else if (fn == "isPowerLimitEnabled") { bool v; ok = inverter->isPowerLimitEnabled(v); result = ok ? boolText(v) : "Falha"; }
  else if (fn == "getPowerLimit") { float v; ok = inverter->getPowerLimit(v); result = ok ? String(v, 3) + " W" : "Falha"; }
  else if (fn == "getPowerLimitPercent") { float v; ok = inverter->getPowerLimitPercent(v); result = ok ? String(v, 3) + " %" : "Falha"; }
  else if (fn == "isExportLimitEnabled") { bool v; ok = inverter->isExportLimitEnabled(v); result = ok ? boolText(v) : "Falha"; }
  else if (fn == "getExportLimit") { float v; ok = inverter->getExportLimit(v); result = ok ? String(v, 3) + " W" : "Falha"; }
  else if (fn == "getExportLimitPercent") { float v; ok = inverter->getExportLimitPercent(v); result = ok ? String(v, 3) + " %" : "Falha"; }
  else if (fn == "isPowerFactorEnabled") { bool v; ok = inverter->isPowerFactorEnabled(v); result = ok ? boolText(v) : "Falha"; }
  else if (fn == "getPowerFactorSetpoint") { float v; ok = inverter->getPowerFactorSetpoint(v); result = ok ? String(v, 4) : "Falha"; }
  else if (fn == "getDatetime") { Datetime v; ok = inverter->getDatetime(v); result = ok ? datetimeText(v) : "Falha"; }
  else if (fn == "getYear") { uint16_t v; ok = inverter->getYear(v); result = ok ? String(v) : "Falha"; }
  else if (fn == "getMonth") { uint16_t v; ok = inverter->getMonth(v); result = ok ? String(v) : "Falha"; }
  else if (fn == "getDay") { uint16_t v; ok = inverter->getDay(v); result = ok ? String(v) : "Falha"; }
  else if (fn == "getHour") { uint16_t v; ok = inverter->getHour(v); result = ok ? String(v) : "Falha"; }
  else if (fn == "getMinute") { uint16_t v; ok = inverter->getMinute(v); result = ok ? String(v) : "Falha"; }
  else if (fn == "getSecond") { uint16_t v; ok = inverter->getSecond(v); result = ok ? String(v) : "Falha"; }
  else if (fn == "getEpochTime") { uint32_t v; ok = inverter->getEpochTime(v); result = ok ? String(v) : "Falha"; }
  else if (fn == "getActivePower") { float v; ok = inverter->getActivePower(v); result = ok ? String(v, 3) + " W" : "Falha"; }
  else if (fn == "getReactivePower") { float v; ok = inverter->getReactivePower(v); result = ok ? String(v, 3) + " VAr" : "Falha"; }
  else if (fn == "getApparentPower") { float v; ok = inverter->getApparentPower(v); result = ok ? String(v, 3) + " VA" : "Falha"; }
  else if (fn == "getPowerFactor") { float v; ok = inverter->getPowerFactor(v); result = ok ? String(v, 4) : "Falha"; }
  else if (fn == "getGridVoltage") { PhaseData v; ok = inverter->getGridVoltage(v); result = ok ? phaseText(v, "V") : "Falha"; }
  else if (fn == "getGridCurrent") { PhaseData v; ok = inverter->getGridCurrent(v); result = ok ? phaseText(v, "A") : "Falha"; }
  else if (fn == "getGridFrequency") { PhaseData v; ok = inverter->getGridFrequency(v); result = ok ? phaseText(v, "Hz") : "Falha"; }
  else if (fn == "getTotalEnergy") { float v; ok = inverter->getTotalEnergy(v); result = ok ? String(v, 3) + " kWh" : "Falha"; }
  else if (fn == "getDailyEnergy") { float v; ok = inverter->getDailyEnergy(v); result = ok ? String(v, 3) + " kWh" : "Falha"; }
  else if (fn == "getStringVoltage") { StringValues v; ok = inverter->getStringVoltage(v); result = ok ? stringValuesText(v, "V") : "Falha"; }
  else if (fn == "getStringCurrent") { StringValues v; ok = inverter->getStringCurrent(v); result = ok ? stringValuesText(v, "A") : "Falha"; }
  else if (fn == "getStringPower") { StringValues v; ok = inverter->getStringPower(v); result = ok ? stringValuesText(v, "W") : "Falha"; }
  else if (fn == "getBatteryVoltage") { BatteryValues v; ok = inverter->getBatteryVoltage(v); result = ok ? batteryValuesText(v, "V") : "Falha"; }
  else if (fn == "getBatteryCurrent") { BatteryValues v; ok = inverter->getBatteryCurrent(v); result = ok ? batteryValuesText(v, "A") : "Falha"; }
  else if (fn == "getBatteryPower") { BatteryValues v; ok = inverter->getBatteryPower(v); result = ok ? batteryValuesText(v, "W") : "Falha"; }
  else if (fn == "getBatterySoC") { BatteryValues v; ok = inverter->getBatterySoC(v); result = ok ? batteryValuesText(v, "%") : "Falha"; }
  else if (fn == "getBatterySoH") { BatteryValues v; ok = inverter->getBatterySoH(v); result = ok ? batteryValuesText(v, "%") : "Falha"; }
  else if (fn == "getEPSVoltage") { PhaseData v; ok = inverter->getEPSVoltage(v); result = ok ? phaseText(v, "V") : "Falha"; }
  else if (fn == "getEPSCurrent") { PhaseData v; ok = inverter->getEPSCurrent(v); result = ok ? phaseText(v, "A") : "Falha"; }
  else if (fn == "getEPSActivePower") { PhaseData v; ok = inverter->getEPSActivePower(v); result = ok ? phaseText(v, "W") : "Falha"; }
  else if (fn == "getTemperature") { float v; ok = inverter->getTemperature(v); result = ok ? String(v, 3) + " °C" : "Falha"; }
  else if (fn == "getInsulationResistance") { float v; ok = inverter->getInsulationResistance(v); result = ok ? String(v, 3) + " kΩ" : "Falha"; }
  else if (fn == "getInverterStatus") { InverterStatus v; ok = inverter->getInverterStatus(v); result = ok ? String((int)v) : "Falha"; }
  else if (fn == "getAlarm") { Alarm v; ok = inverter->getAlarm(v); result = ok ? String((int)v) : "Falha"; }
  else { result = "Função desconhecida."; }

  result = "<b>" + okFail(ok) + "</b><br>" + result;
  server.send(200, "text/html", buildMainPage(fn, result));
}

void handleSet() {
  if (!ensureInverterConfigured()) {
    server.send(200, "text/html", buildMainPage("set", "Falha ao configurar inversor."));
    return;
  }

  String fn = server.arg("fn");
  float f = server.hasArg("value") ? server.arg("value").toFloat() : 0.0f;
  uint32_t u = server.hasArg("value") ? (uint32_t)server.arg("value").toInt() : 0;
  bool b = server.hasArg("value") ? (server.arg("value").toInt() != 0) : false;
  bool ok = false;
  String group = "set";

  if (fn == "boot") ok = inverter->boot();
  else if (fn == "shutdown") ok = inverter->shutdown();
  else if (fn == "setBoot") ok = inverter->setBoot(b);
  else if (fn == "setPowerLimitEnabled") ok = inverter->setPowerLimitEnabled(b);
  else if (fn == "setPowerLimit") ok = inverter->setPowerLimit(f);
  else if (fn == "setPowerLimitPercent") ok = inverter->setPowerLimitPercent(f);
  else if (fn == "setExportLimitEnabled") ok = inverter->setExportLimitEnabled(b);
  else if (fn == "setExportLimit") ok = inverter->setExportLimit(f);
  else if (fn == "setExportLimitPercent") ok = inverter->setExportLimitPercent(f);
  else if (fn == "setPowerFactorEnabled") ok = inverter->setPowerFactorEnabled(b);
  else if (fn == "setPowerFactor") ok = inverter->setPowerFactor(f);
  else if (fn == "setPowerFactorExcitationMode") ok = inverter->setPowerFactorExcitationMode((PfExcitationMode)u);
  else if (fn == "setDatetime") {
    group = "setTime";
    Datetime dt;
    dt.year = server.arg("year").toInt();
    dt.month = server.arg("month").toInt();
    dt.day = server.arg("day").toInt();
    dt.hour = server.arg("hour").toInt();
    dt.minute = server.arg("minute").toInt();
    dt.second = server.arg("second").toInt();
    ok = inverter->setDatetime(dt);
  }
  else if (fn == "setYear") { group = "setTime"; ok = inverter->setYear((uint16_t)u); }
  else if (fn == "setMonth") { group = "setTime"; ok = inverter->setMonth((uint16_t)u); }
  else if (fn == "setDay") { group = "setTime"; ok = inverter->setDay((uint16_t)u); }
  else if (fn == "setHour") { group = "setTime"; ok = inverter->setHour((uint16_t)u); }
  else if (fn == "setMinute") { group = "setTime"; ok = inverter->setMinute((uint16_t)u); }
  else if (fn == "setSecond") { group = "setTime"; ok = inverter->setSecond((uint16_t)u); }
  else if (fn == "setEpochTime") { group = "setTime"; ok = inverter->setEpochTime(u); }

  String result = "<b>" + okFail(ok) + "</b><br>" + escapeHtml(fn);
  server.send(200, "text/html", buildMainPage(group, result));
}


// ====================================================== 

void setup() {
  // Do not call Serial.begin() for debug here when using Serial as RS485.
  // The library applies the UART configuration before Modbus transactions.

  WiFi.mode(WIFI_AP);
  WiFi.softAP(AP_SSID, AP_PASS);

  ensureInverterConfigured();

  server.on("/", handleRoot);
  server.on("/config", handleConfig);
  server.on("/config/apply", handleConfigApply);
  server.on("/get", handleGet);
  server.on("/set", handleSet);
  server.begin();
}

void loop() {
  server.handleClient();
  mb.task();
  yield();
}
