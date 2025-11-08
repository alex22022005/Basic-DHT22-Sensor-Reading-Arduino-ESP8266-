#include <DHT22.h>

#define DHTPIN 4        // DHT22 data pin connected to GPIO 4

DHT22 dht(DHTPIN);

void setup() {
  Serial.begin(115200);
  Serial.println("DHT22 Sensor Reading");
}

void loop() {
  float temperature = dht.getTemperature();
  float humidity = dht.getHumidity();

  // Check for valid readings
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT22 sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C  |  Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  delay(2000);
}
