# Basic DHT22 Sensor Reading (Arduino/ESP8266)

A simple Arduino/ESP8266 sketch to read temperature and humidity from a DHT22 sensor. This code prints the values to the Serial Monitor and includes error handling for failed readings.

---

## 📋 Features

* Reads **Temperature** (in Celsius) from the DHT22 sensor.
* Reads **Humidity** (in %) from the DHT22 sensor.
* Includes error checking (`isnan`) to handle failed sensor readings.
* Outputs formatted data to the Serial Monitor.
* Configured for `GPIO 4` but can be easily changed.

---

## ⚙️ Requirements

### Hardware
* An Arduino, ESP8266, ESP32, or other compatible microcontroller.
* A DHT22 (or AM2302) sensor.
* A 10k &Omega; pull-up resistor (recommended, though some modules have it built-in).

### Software
* [Arduino IDE](https://www.arduino.cc/en/software) or [PlatformIO](https://platformio.org/).
* **DHT sensor library**: You will need a library to run this code. A common one is the "DHT sensor library" by Adafruit. You can install it via the Arduino IDE Library Manager.
    1.  Go to `Sketch` > `Include Library` > `Manage Libraries...`
    2.  Search for "DHT sensor library" by Adafruit.
    3.  Click `Install`.
    4.  This library may also require the "Adafruit Unified Sensor" library, which will be installed with it.

---

## 🚀 How to Use

1.  **Wiring:**
    * Connect the DHT22 `VCC` pin to `5V` or `3.3V` (check your board's specs).
    * Connect the DHT22 `GND` pin to `GND`.
    * Connect the DHT22 `Data` pin to `GPIO 4` (or the pin you define in `#define DHTPIN 4`).
    * Connect the 10k &Omega; pull-up resistor between the `Data` pin and `VCC`.

2.  **Code:**
    * Open the `.ino` sketch in your Arduino IDE.
    * Select your board (e.g., "NodeMCU 1.0 (ESP-12E Module)" or "Arduino Uno").
    * Select the correct COM port.
    * Upload the code.

3.  **Monitor:**
    * Open the Serial Monitor (`Tools` > `Serial Monitor`).
    * Set the baud rate to **115200** (as defined in `Serial.begin(115200)`).
    * You will see the temperature and humidity readings appear every 2 seconds.

---

## 💻 Main Sketch

Here is the complete source code:

```cpp
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
```
## 📺 Example Serial Output
```cpp
DHT22 Sensor Reading
Temperature: 24.50 °C  |  Humidity: 45.80 %
Temperature: 24.50 °C  |  Humidity: 45.90 %
Failed to read from DHT22 sensor!
Temperature: 24.60 °C  |  Humidity: 46.00 %
```

  delay(2000);
}
