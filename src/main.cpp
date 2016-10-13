#include <Arduino.h>
#include <esp8266/ESP8266wifi.h>

const byte resetPin = 5;

void setup() {
    Serial.begin(115200);
    Serial3.begin(115200);
}

void loop() {
    ESP8266wifi *wifi = new ESP8266wifi(Serial3, Serial3, resetPin, Serial);

    Serial.println("CONNECTING...");
    wifi->begin();
    wifi->connectToAP("network", "pass");
    wifi->setTransportToTCP();
    wifi->connectToServer("54.197.225.88", "443");

    wifi->send('4', "GET / HTTP/1.1\nHost: grammarly.com\n\n");
    WifiMessage msg = wifi->listenForIncomingMessage(1000);
    Serial.println(msg.message);
    wifi->disconnectFromServer();

    delay(10000);
}
