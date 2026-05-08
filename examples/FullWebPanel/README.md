# FullWebPanel

Exemplo completo de interface web para controle e monitoramento de inversores Modbus RTU utilizando ESP8266/ESP32.

## Recursos

- Interface web WiFi
- Leitura de parâmetros do inversor
- Escrita de parâmetros
- Configuração Modbus dinâmica
- Seleção do modelo do inversor
- Suporte a múltiplos inversores

## Hardware utilizado

- ESP8266 ESP-07
- Conversor RS485 TTL
- Inversor compatível

## Configuração WiFi

SSID:
ESP07-Inverter

Senha:
12345678

## Acesso

Após conectar ao WiFi:

http://192.168.4.1

## Observações

- Não utilizar Serial.print() na UART utilizada pelo RS485.
- Alguns registradores podem variar conforme firmware/modelo do inversor.
- O mapa Modbus ainda está em validação prática.