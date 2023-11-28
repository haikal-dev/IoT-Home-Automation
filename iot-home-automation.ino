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
char auth[] = "<BLYNK_TOKEN>";

// outputs
const uint8_t lamp1 = 14;
const uint8_t lamp2 = 12;
const uint8_t socket1 = 13;
const uint8_t socket2 = 15;

// inputs
const uint8_t PIR = D0;

int count = 0;

void setup() {
  Serial.begin(9600);

  // outputs
  pinMode(lamp1, OUTPUT);
  pinMode(lamp2, OUTPUT);
  pinMode(socket1, OUTPUT);
  pinMode(socket2, OUTPUT);

  // inputs
  pinMode(PIR, INPUT);

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

  // Serial.begin(9600);
  Blynk.begin(auth, ssid, password);

  // initial state
  digitalWrite(lamp1, LOW);
  digitalWrite(lamp2, LOW);
  digitalWrite(socket1, LOW);
  digitalWrite(socket2, LOW);

  Blynk.virtualWrite(LAMP1_PIN, LOW); // Set the initial state of the switch
  Blynk.syncVirtual(LAMP1_PIN);
  Blynk.virtualWrite(LAMP2_PIN, LOW); // Set the initial state of the switch
  Blynk.syncVirtual(LAMP2_PIN);
  Blynk.virtualWrite(SOCKET1_PIN, LOW); // Set the initial state of the switch
  Blynk.syncVirtual(SOCKET1_PIN);
}

void loop() {
  // Your main code goes here
  Blynk.run();

  // int pir_value = digitalRead(PIR);
  
  // if(pir_value == HIGH) {
  //   Serial.print("Motion detected: ");
  //   Serial.println(count);

  //   Blynk.virtualWrite(LAMP1_PIN, HIGH); // Set the initial state of the switch
  //   Blynk.syncVirtual(LAMP1_PIN);
  //   Blynk.virtualWrite(LAMP2_PIN, HIGH); // Set the initial state of the switch
  //   Blynk.syncVirtual(LAMP2_PIN);
  //   Blynk.virtualWrite(SOCKET1_PIN, HIGH); // Set the initial state of the switch
  //   Blynk.syncVirtual(SOCKET1_PIN);

  //   delay(1000);
  //   count++;
  // }

  // else {
  //   Blynk.virtualWrite(LAMP1_PIN, LOW); // Set the initial state of the switch
  //   Blynk.syncVirtual(LAMP1_PIN);
  //   Blynk.virtualWrite(LAMP2_PIN, LOW); // Set the initial state of the switch
  //   Blynk.syncVirtual(LAMP2_PIN);
  //   Blynk.virtualWrite(SOCKET1_PIN, LOW); // Set the initial state of the switch
  //   Blynk.syncVirtual(SOCKET1_PIN);
  //   delay(1000);
  // }
}

// Blynk virtual pin handler
BLYNK_WRITE(LAMP1_PIN) {
  int switchState = param.asInt(); // Get the state of the switch

  // Toggle the LED based on the switch state
  if (switchState == HIGH) {
    Serial.println("Lamp 1 ON");
    digitalWrite(lamp1, LOW); // Turn ON the LED
  } else {
    Serial.println("Lamp 1 OFF");
    digitalWrite(lamp1, HIGH); // Turn OFF the LED
  }
}

BLYNK_WRITE(LAMP2_PIN) {
  int switchState = param.asInt(); // Get the state of the switch

  // Toggle the LED based on the switch state
  if (switchState == HIGH) {
    Serial.println("Lamp 2 ON");
    digitalWrite(lamp2, LOW); // Turn ON the LED
  } else {
    Serial.println("Lamp 2 OFF");
    digitalWrite(lamp2, HIGH); // Turn OFF the LED
  }
}

BLYNK_WRITE(SOCKET1_PIN) {
  int switchState = param.asInt(); // Get the state of the switch

  // Toggle the LED based on the switch state
  if (switchState == HIGH) {
    Serial.println("Socket 1 ON");
    digitalWrite(socket1, LOW); // Turn ON the LED
  } else {
    Serial.println("Socket 1 OFF");
    digitalWrite(socket1, HIGH); // Turn OFF the LED
  }
}