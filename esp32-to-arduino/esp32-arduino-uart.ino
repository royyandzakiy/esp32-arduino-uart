#include "Arduino.h"
#include "HardwareSerial.h"

#define ESP32_RX2 16
#define ESP32_TX2 17

HardwareSerial SerialArduino(2);

void sendUARTPayload() {
  SerialArduino.write("text1\n");
  SerialArduino.write("text2\n");
  SerialArduino.write("text3\n");
}

void setup() {
    Serial.begin(115200);
    Serial.println("ESP32 Ready!");

    SerialArduino.begin(115200, SERIAL_8N1, ESP32_RX2, ESP32_TX2); SerialArduino.write("Hello, Friend! - from ESP32\n"); sendUARTPayload();
}

void loop() {
  if (SerialArduino.available() > 0) {
      Serial.println(SerialArduino.readStringUntil('\n'));
  }
}
