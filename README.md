[![Environment](https://img.shields.io/badge/Arduino-Library-blue)](https://www.arduino.cc/)
[![Environment](https://img.shields.io/badge/ESP32-Environment-red)](https://en.wikipedia.org/wiki/ESP32)

# PZEM-004T v3.0 -with MODBUS PROTOCOL-
Arduino library to connect to the PZEM004T v3.0 sensor, thanks to the Modbus protocol

* [Manufacturer specifications](#Manufacturer-specifications)
* [Example](#Example)
* [Version changes](#Version-changes)
* [Tested boards](#Tested-boards)
* [Improvements](#Improvements)
* [Authors](#Authors)

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.me/josecserrano/2)

# Manufacturer specifications

| Function      | Measuring range    | Resolution      | Accuracy |
|---------------|--------------------|-----------------|----------|
| Voltage       | 80~260V            | 0.1V            | 0.5%     |
| Current       | 0\~10A or 0\~100A    | 0.01A or 0.02A  | 0.5%     |
| Active power  | 0\~2.3kW or 0\~23kW  | 0.1W            | 0.5%     |
| Active energy | 0~9999.99kWh       | 1Wh             | 0.5%     |
| Frequency     | 45~65Hz            | 0.1Hz           | 0.5%     |
| Power factor  | 0.00~1.00          | 0.01            | 1%       |

# Example
```c++
#include <PZEM004Tv30_MODBUS.h>

PZEM004Tv30_MODBUS sensor(&Serial2, 1);

void setup() {
  // Config serial
  Serial.begin(115200);
  // Initialize sensor and connect to it through the Modbus protocol
  Serial.println("Initializing PZEM004-v3.0 ...");
  sensor.setupPZEM004();
}

void loop() {

double value;

  value = sensor.getPZEM004Voltage();
  Serial.print("Voltage / Voltaje: "); Serial.println(value);   // V
  delay(1000);
  
  value = sensor.getPZEM004Current();
  Serial.print("Current / Intensidad: "); Serial.println(value);   // A
  delay(1000);
  
  value = sensor.getPZEM004Power();
  Serial.print("Power / Potencia: "); Serial.println(value);   // W
  delay(1000);
  
  value = sensor.getPZEM004Energy();
  Serial.print("Energy / Energia: "); Serial.println(value);   // kWh
  delay(1000);
  
  value = sensor.getPZEM004Frequency();
  Serial.print("Frecuencia / Frecuencia: "); Serial.println(value);   // Hz
  delay(1000);
  
  value = sensor.getPZEM004Pf();
  Serial.print("Power Factor / Factor de potencia: "); Serial.println(value);
  delay(1000);
  
  value = sensor.getPZEM004Alarm();
  Serial.print("Alarm / Alarma: "); Serial.println(value);
  delay(1000);

  Serial.println("Next =================================");
}
```
# Version changes
v1.0.0
- First Version

# Tested boards
- ESP32

# Improvements
- Currently only connections are used through hardwareserial port, so it would be interesting to include the possibility of using Softwareserial

# Authors:
Jose Carlos Serrano Catena. 

# First Version: 30/08/2019
