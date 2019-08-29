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
