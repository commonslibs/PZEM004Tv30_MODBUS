#ifndef PZEM004Tv30_MODBUS_H
#define PZEM004Tv30_MODBUS_H

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <ModbusMaster.h> // Library for Modbus protocol

#define PZEM004Tv30_MODBUS_DEBUG    0
#define PZEM_BAUD_RATE              9600

#define PZEM004Tv30_ADDR_VOLTAGE	  0x00  // (V) Voltage Address / Direccion Voltaje
#define PZEM004Tv30_ADDR_CURRENT	  0x01  // (A) Current Address / Direccion Intensidad
#define PZEM004Tv30_ADDR_POWER		  0x03  // (W) Power Address / Direccion Potencia 
#define PZEM004Tv30_ADDR_ENERGY		  0x05  // (kWh) Energy Address / Direccioon Energia    
#define PZEM004Tv30_ADDR_FREQUENCY	0x07  // (Hz) Frequency Address / Direccion Frecuencia
#define PZEM004Tv30_ADDR_PF			    0x08  // Power Factor Address / Factor Potencia
#define PZEM004Tv30_ADDR_ALARM      0x09  // Alarm Address / Direccion Alarma

class PZEM004Tv30_MODBUS {
 public:
    PZEM004Tv30_MODBUS(HardwareSerial* port, int id_modbus);
    void setupPZEM004();
	  double getPZEM004Voltage();
    double getPZEM004Current();
    double getPZEM004Power();
    double getPZEM004Energy();
    double getPZEM004Frequency();
    double getPZEM004Pf();
    double getPZEM004Alarm(); 
 private:
    ModbusMaster _node;
    int _id_modbus;
    Stream* _serial; // Serial interface
};

#endif //  PZEM004Tv30_MODBUS_H
