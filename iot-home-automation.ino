#define BLYNK_TEMPLATE_ID "TMPL6nWns-acG"
#define BLYNK_TEMPLATE_NAME "IoT Home Automation"
#define BLYNK_AUTH_TOKEN "<BLYNK_TOKEN>"

// Virtual Pin for Blynk switch
#define LAMP1_PIN V0
#define LAMP2_PIN V1
#define SOCKET1_PIN V2

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Please enter wifi credentials
const char *ssid = "<WIFI_NAME>";
const char *password = "<WIFI_PASSWORD>";

// Replace with your Blynk authentication token
char auth[] = "<BLYNK_TOKEN";

void setup() {
  Serial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  
  Blynk.begin(auth, ssid, password);
}

void loop() {
  // Your main code goes here
  Blynk.run();
}