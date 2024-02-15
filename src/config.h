#ifndef TANAHKU_CONFIG_H
#define TANAHKU_CONFIG_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>


// wifi
const char *ssid = "MyAsus";
const char *password = "hy12345678";


HTTPClient http;

String baseApiUrl = "https://api.tanahku.online/api/v1";
String apiKey = "2cbaf3a3-1438-4a47-97a6-f6d995cba3b6";
long deviceId = 2;

#endif