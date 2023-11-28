#define BLYNK_TEMPLATE_ID "TMPL6nWns-acG"
#define BLYNK_TEMPLATE_NAME "IoT Home Automation"
#define BLYNK_AUTH_TOKEN "<BLYNK_TOKEN>"

// Virtual Pin for Blynk switch
#define LAMP1_PIN V0
#define LAMP2_PIN V1
#define LAMP3_PIN V2
#define FAN1_PIN V3

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Please enter wifi credentials
const char *ssid = "<WIFI_NAME>";
const char *password = "<WIFI_PASSWORD>";

// Replace with your Blynk authentication token
char auth[] = "<BLYNK_TOKEN>";

//outputs
// const uint8_t lamp1 = 14;
const uint8_t lamp1 = 5;
const uint8_t lamp2 = 12;
const uint8_t lamp3 = 4;
const uint8_t fan1 = 13;


// inputs
// const uint8_t PIR = D0;

int count = 0;

void setup() {
  Serial.begin(9600);

  // outputs
  pinMode(lamp1, OUTPUT);
  pinMode(lamp2, OUTPUT);
  pinMode(lamp3, OUTPUT);
  pinMode(fan1, OUTPUT);

  // inputs
  // pinMode(PIR, INPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  // Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println("\nConnected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Serial.begin(9600);
  Blynk.begin(auth, ssid, password);

  // initial state
  digitalWrite(lamp1, LOW);
  digitalWrite(lamp2, LOW);
  digitalWrite(lamp3, LOW);
  digitalWrite(fan1, LOW);

  Blynk.virtualWrite(LAMP1_PIN, LOW); // Set the initial state of the switch
  Blynk.syncVirtual(LAMP1_PIN);
  Blynk.virtualWrite(LAMP2_PIN, LOW); // Set the initial state of the switch
  Blynk.syncVirtual(LAMP2_PIN);
  Blynk.virtualWrite(LAMP3_PIN, LOW); // Set the initial state of the switch
  Blynk.syncVirtual(LAMP3_PIN);
  Blynk.virtualWrite(FAN1_PIN, LOW); // Set the initial state of the switch
  Blynk.syncVirtual(FAN1_PIN);
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

BLYNK_WRITE(LAMP3_PIN) {
  int switchState = param.asInt(); // Get the state of the switch

  // Toggle the LED based on the switch state
  if (switchState == HIGH) {
    Serial.println("Lamp 3 ON");
    digitalWrite(lamp3, LOW); // Turn ON the LED
  } else {
    Serial.println("Lamp 3 OFF");
    digitalWrite(lamp3, HIGH); // Turn OFF the LED
  }
}

BLYNK_WRITE(FAN1_PIN) {
  int switchState = param.asInt(); // Get the state of the switch

  // Toggle the LED based on the switch state
  if (switchState == HIGH) {
    Serial.println("Fan 1 ON");
    digitalWrite(fan1, LOW); // Turn ON the LED
  } else {
    Serial.println("Fan 1 OFF");
    digitalWrite(fan1, HIGH); // Turn OFF the LED
  }
}