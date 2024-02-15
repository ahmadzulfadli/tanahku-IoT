#ifndef TANAHKU_FUNCTION_H
#define TANAHKU_FUNCTION_H

#include "config.h"

void connectWifi()
{
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void sendDataToServer(String detailUrl, float windSpeed)
{

    StaticJsonDocument<200> jsonDocument;
    jsonDocument["deviceId"] = deviceId;
    jsonDocument["value"] = windSpeed;

    String jsonString;
    serializeJson(jsonDocument, jsonString);

    http.begin(baseApiUrl + detailUrl);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("apiKey", apiKey);

    int httpResponseCode = http.POST(jsonString);

    if (httpResponseCode > 0)
    {
        Serial.printf("HTTP Response code: %d\n", httpResponseCode);
        String response = http.getString();
        Serial.println(response);
    }
    else
    {
        Serial.printf("HTTP POST request failed, error: %s\n", http.errorToString(httpResponseCode).c_str());
    }

    http.end();
}

#endif