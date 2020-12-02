
void sendUARTPayload() {
  Serial2.write("Mantap jiwa!\n");
}

void setup() {
  Serial.begin(115200);
  Serial.println("Arduino Mega Ready!");
  
  Serial2.begin(115200);
  Serial2.write("Hello, Friend! - from Mega\n");
  sendUARTPayload();
}

void loop() {
  if (Serial2.available() > 0) {
      Serial.println(Serial2.readStringUntil('\n'));
  }
}
