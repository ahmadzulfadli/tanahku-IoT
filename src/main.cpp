#include "config.h"
#include "function.h"

void setup()
{
  Serial.begin(115200);

  // Networking
  connectWifi();
}

void loop()
{
  // millis
  unsigned long currentMillis = millis();
  static unsigned long previousMillis = 0;
  const long interval = 60000;

  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;

    // Cek koneksi WiFi
    if (WiFi.status() != WL_CONNECTED)
    {
      Serial.println("WiFi disconnected. Reconnecting...");
      connectWifi();
    }

    float windSpeed = random(20, 30);
    float soilMoisture = random(20, 30);
    float humidity = random(20, 30);
    float airTemperature = random(20, 30);
    float rainFall = random(20, 30);
    float soailPH = random(20, 30);
    float solarRadiation = random(20, 30);

    // kirim data ke server
    sendDataToServer("/windspeed/create", windSpeed);
    sendDataToServer("/soilmoisture/create", soilMoisture);
    sendDataToServer("/humidity/create", humidity);
    sendDataToServer("/airtemperature/create", airTemperature);
    sendDataToServer("/rainfall/create", rainFall);
    sendDataToServer("/soilph/create", soailPH);
    sendDataToServer("/solarradiation/create", solarRadiation);
  }
}