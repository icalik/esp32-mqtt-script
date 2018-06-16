#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "mawrick";
const char* password =  "goismfbybe";
const char* mqttServer = "m20.cloudmqtt.com";
const int mqttPort = 18184;
const char* mqttUser = "rehdgmoc";
const char* mqttPassword = "8WCdbN19nDUF";

WiFiClient espClient;
PubSubClient client(espClient);
 
void setup() {

  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");

    if (client.connect("ESP32Client", mqttUser, mqttPassword )) {
      Serial.println("connected");
    } else {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
  client.publish("esp/test", "Hello from ESP32");
}
 
void loop() {
  client.loop();
}
