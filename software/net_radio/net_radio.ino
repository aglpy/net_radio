// Net Radio
#include <WiFi.h>
#include <Audio.h>

#include "config.h"

int counter = 0;
int previousStateCLK = 0;
unsigned long lastUpdateTime = 0;

Audio audio;

void IRAM_ATTR rotation() {
  int currentStateCLK = digitalRead(CLK_PIN);
  int currentStateDT = digitalRead(DT_PIN);

  if (currentStateCLK != previousStateCLK) {
    if (currentStateDT != currentStateCLK) {
      counter--;
    } else {
      counter++;
    }
  }
  previousStateCLK = currentStateCLK;
}

void setup() {
  Serial.begin(115200);
  Serial.println("Connecting WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    for (int i = 0; i < sizeof(ssidList) / sizeof(ssidList[0]); i++) {
      Serial.print("Connecting to: ");
      Serial.println(ssidList[i]);

      WiFi.begin(ssidList[i], passwordList[i]);

      int attempts = 0;
      while (WiFi.status() != WL_CONNECTED && attempts < 10) {
        delay(500);
        Serial.print(".");
        attempts++;
      }

      if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nConnected!");
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
        break;
      } else {
        Serial.println("\nCan't connect.");
      }
    }
    Serial.println("Trying connecting again...");
  }

  audio.setPinout(AUDIO_BCLK, AUDIO_LRC, AUDIO_DATA_IN);
  audio.setBufsize(1600 * 10, 4096 * 10);
  audio.connecttohost(radio_url);
  
  pinMode(BUILT_IN_LED, OUTPUT);
  digitalWrite(BUILT_IN_LED, LOW);

  pinMode(CLK_PIN, INPUT_PULLUP);
  pinMode(DT_PIN, INPUT_PULLUP);

  previousStateCLK = digitalRead(CLK_PIN);
  attachInterrupt(digitalPinToInterrupt(CLK_PIN), rotation, CHANGE);

  dacWrite(AUDIO_GAIN, 0);
}

void loop() {
  audio.loop();

  if (millis() - lastUpdateTime > 300) {
    lastUpdateTime = millis();
    counter = max(min(counter, 10), -10);
    Serial.print("Volume counter: ");
    Serial.println(counter);
    audio.setVolume(map(counter, 10, -10, 1, 21));
  }
}