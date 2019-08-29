# PZEM-004T v3.0 -with MODBUS PROTOCOL-
Arduino library to connect, with the Modbus protocol, with the PZEM004T-v3.0 sensor.


### Manufacturer (optimistic) specifications

| Function      | Measuring range    | Resolution      | Accuracy | TODO: Realistic specifications |
|---------------|--------------------|-----------------|----------|--------------------------------|
| Voltage       | 80~260V            | 0.1V            | 0.5%     |                                |
| Current       | 0\~10A or 0\~100A*   | 0.01A or 0.02A* | 0.5%     |                                |
| Active power  | 0\~2.3kW or 0\~23kW* | 0.1W            | 0.5%     |                                |
| Active energy | 0~9999.99kWh       | 1Wh             | 0.5%     |                                |
| Frequency     | 45~65Hz            | 0.1Hz           | 0.5%     |                                |
| Power factor  | 0.00~1.00          | 0.01            | 1%       |                                |

\* Using the external current transformer instead of the built in shunt

### Example
```c++
#include "PZEM004Tv30_MODBUS.h"

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

Author: José Carlos Serrano Catena