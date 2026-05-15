// Partes da arquitetura, documentação e exemplos desta biblioteca foram desenvolvidas com auxílio de inteligência artificial para acelerar prototipagem, revisão e organização do código.

/*
  Exemplo: lendo o serial de 2 inversores no mesmo barramento RS485

  Placa: ESP8266 / ESP-07
  Biblioteca: inverterLib

  Um inversor está com Endereço 1 e o outro inversor está com o Endereço 2
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ModbusRTU.h>
#include <InverterModbusLib.h>

int8_t deRePin = -1;  // Defina o pino DE_RE

const char* AP_SSID = "ESP07-Inverter";
const char* AP_PASS = "12345678";

ESP8266WebServer server(80);
ModbusRTU mb;

// ModbusConfigData:
// { slaveId, baudRate, serialConfig, deRePin }
//
// O primeiro inversor define o pino DE/RE porque ambos estão no mesmo barramento RS485.
// Caso use barramentos separados, cada inversor pode ter seu próprio ModbusRTU,
// HardwareSerial e pino DE/RE.

ModbusConfigData mbCfg400G = {2, 9600, SERIAL_8N1, deRePin};
ModbusConfigData mbCfg500H = {1, 9600, SERIAL_8N1, deRePin};

// Inversores no mesmo barramento RS485
Inverter inverter400G(SIW400G_T100_W0);
Inverter inverter500H(SIW500H_ST030_M3);

Inverter* getSelectedInverter(const String& model) {
  if (model == "SIW400G") return &inverter400G;
  if (model == "SIW500H") return &inverter500H;
  return nullptr;
}

void handleRoot() {
  String html = R"rawliteral(
  <!DOCTYPE html>
  <html>
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Lendo serial de 2 inversores</title>
    <style>
      body {
        font-family: Arial, sans-serif;
        background: #f4f6f8;
        margin: 0;
        padding: 20px;
        color: #222;
      }

      .card {
        max-width: 420px;
        margin: 40px auto;
        background: #fff;
        padding: 24px;
        border-radius: 12px;
        box-shadow: 0 4px 14px rgba(0,0,0,0.12);
      }

      h2 {
        margin-top: 0;
        text-align: center;
        color: #123;
      }

      label {
        display: block;
        margin-bottom: 8px;
        font-weight: bold;
      }

      select, button {
        width: 100%;
        padding: 12px;
        font-size: 16px;
        border-radius: 8px;
        box-sizing: border-box;
      }

      select {
        border: 1px solid #ccc;
        margin-bottom: 18px;
        background: #fff;
      }

      button {
        border: none;
        background: #0066cc;
        color: white;
        font-weight: bold;
        cursor: pointer;
      }

      button:hover {
        background: #004f99;
      }

      .footer {
        margin-top: 18px;
        font-size: 13px;
        color: #666;
        text-align: center;
      }
    </style>
  </head>
  <body>
    <div class="card">
      <h2>Ler serial do inversor</h2>

      <form action="/read" method="GET">
        <label>Modelo do inversor</label>
        <select name="model">
          <option value="SIW400G">SIW400G T100 W0</option>
          <option value="SIW500H">SIW500H ST030 M3</option>
        </select>

        <button type="submit">Ler Serial</button>
      </form>

      <div class="footer">
        ESP07-Inverter · Modbus RTU
      </div>
    </div>
  </body>
  </html>
  )rawliteral";

  server.send(200, "text/html", html);
}

void handleRead() {
  if (!server.hasArg("model")) {
    server.send(400, "text/plain", "Informe o modelo.");
    return;
  }

  String model = server.arg("model");
  Inverter* selectedInverter = getSelectedInverter(model);

  if (selectedInverter == nullptr) {
    server.send(400, "text/plain", "Modelo invalido.");
    return;
  }

  String serialNumber;
  bool ok = selectedInverter->getSerialNumber(serialNumber);

  String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  html += "<title>Resultado</title>";
  html += "<style>";
  html += "body{font-family:Arial,sans-serif;background:#f4f6f8;margin:0;padding:20px;color:#222;}";
  html += ".card{max-width:420px;margin:40px auto;background:#fff;padding:24px;border-radius:12px;box-shadow:0 4px 14px rgba(0,0,0,0.12);}";
  html += "h2{margin-top:0;text-align:center;color:#123;}";
  html += ".ok{background:#e8f7ee;color:#135c2e;padding:12px;border-radius:8px;}";
  html += ".fail{background:#fdecec;color:#8a1f1f;padding:12px;border-radius:8px;}";
  html += "a{display:block;text-align:center;margin-top:18px;padding:12px;background:#0066cc;color:white;text-decoration:none;border-radius:8px;font-weight:bold;}";
  html += "</style></head><body><div class='card'>";
  html += "<h2>Resultado</h2>";

  if (ok) {
    html += "<div class='ok'><b>Serial:</b><br>" + serialNumber + "</div>";
  } else {
    html += "<div class='fail'><b>Falha:</b><br>Nao foi possivel ler o serial.</div>";
  }

  html += "<a href='/'>Voltar</a>";
  html += "</div></body></html>";

  server.send(200, "text/html", html);
}

void setup() {

/*
  ATENÇÃO SOBRE A PORTA SERIAL:

  Neste exemplo, a UART principal do ESP8266 é usada para comunicação RS485/Modbus.
  Portanto, evite usar Serial.print() para debug enquanto o barramento Modbus estiver em uso,
  pois isso pode interferir nos dados enviados ao inversor.

  Se precisar depurar:
  - use LEDs;
  - use mensagens na própria página HTML;
  - use outro microcontrolador/placa com mais UARTs;
  - ou migre para ESP32, que possui múltiplas UARTs de hardware.
*/

  inverter400G.attachModbus(mb);
  inverter400G.attachConfig(mbCfg400G);

  inverter500H.attachModbus(mb);
  inverter500H.attachConfig(mbCfg500H);

// Serial.begin() é iniciado automaticamente pela biblioteca ao aplicar ModbusConfigData.
// Não usar Serial.print() neste exemplo, pois a UART está reservada para RS485/Modbus.

  if (!inverter400G.begin() || !inverter500H.begin()) {
    return;
  }

  WiFi.mode(WIFI_AP);
  WiFi.softAP(AP_SSID, AP_PASS);

  server.on("/", handleRoot);
  server.on("/read", handleRead);
  server.begin();
}

void loop() {
  server.handleClient();
  mb.task();
  yield();
}