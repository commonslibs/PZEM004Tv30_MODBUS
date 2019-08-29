/*************************************************** 
  This is a library for the PZEM004T (v3.0) Current + Power + 
  Energy + Frequency + Power Factor + Alarm Sensors
  Written by Jose Carlos Serrano Catena.  
 ****************************************************/

#include "PZEM004Tv30_MODBUS.h"

// PZEM004Tv30_MODBUS Constructor
PZEM004Tv30_MODBUS::PZEM004Tv30_MODBUS(HardwareSerial* port, int id_modbus) {
  port->begin(PZEM_BAUD_RATE);
  this->_serial = port;
  this->_id_modbus = id_modbus; 
}


// Start communication with PZEM004T v3.0 sensor
void PZEM004Tv30_MODBUS::setupPZEM004() {
  _node.begin(1, *_serial);
  #if PZEM004Tv30_MODBUS_DEBUG == 1
  	Serial.println("Start PZEM");
  #endif
}


// Get the voltage
double PZEM004Tv30_MODBUS::getPZEM004Voltage() {
double voltage;
uint8_t result;

  result = _node.readInputRegisters(0x0000, 10);
  if (result == _node.ku8MBSuccess)  {
  	voltage = (_node.getResponseBuffer(PZEM004Tv30_ADDR_VOLTAGE)/10.0f);
  #if PZEM004Tv30_MODBUS_DEBUG == 1
  	Serial.print("Voltage: "); Serial.println(voltage);
  #endif 
  }
  else {
  #if PZEM004Tv30_MODBUS_DEBUG == 1
  		Serial.print("Error (voltage)");
  #endif    
    }
  return voltage;  
}


// Get the current
double PZEM004Tv30_MODBUS::getPZEM004Current() {
double current;
uint8_t result;

  result = _node.readInputRegisters(0x0000, 10);
  if (result == _node.ku8MBSuccess)  {
    current = (_node.getResponseBuffer(PZEM004Tv30_ADDR_CURRENT)/1000.000f);
  
  #if PZEM004Tv30_MODBUS_DEBUG == 1
    Serial.print("Current: "); Serial.println(current,3);
  #endif
  }
  else {
  #if PZEM004Tv30_MODBUS_DEBUG == 1 
      Serial.print("Error (Current)");
  #endif
    }
  return current;
}

// Get the power
double PZEM004Tv30_MODBUS::getPZEM004Power() {
double power;
uint8_t result;

  result = _node.readInputRegisters(0x0000, 10);
  if (result == _node.ku8MBSuccess)  {
    power = (_node.getResponseBuffer(PZEM004Tv30_ADDR_POWER)/10.0f);
  #if PZEM004Tv30_MODBUS_DEBUG == 1
    Serial.print("Power: "); Serial.println(power);
  #endif 
  }
  else {
  #if PZEM004Tv30_MODBUS_DEBUG == 1
      Serial.print("Error (power)");
  #endif    
    }
  return power;  
}

// Get the energy
double PZEM004Tv30_MODBUS::getPZEM004Energy() {
double energy;
uint8_t result;

  result = _node.readInputRegisters(0x0000, 10);
  if (result == _node.ku8MBSuccess)  {
    energy = (_node.getResponseBuffer(PZEM004Tv30_ADDR_ENERGY)/1000.0f);
  #if PZEM004Tv30_MODBUS_DEBUG == 1
    Serial.print("Energy: "); Serial.println(energy);
  #endif 
  }
  else {
  #if PZEM004Tv30_MODBUS_DEBUG == 1
      Serial.print("Error (energy)");
  #endif    
    }
  return energy;  
}

// Get the frequency
double PZEM004Tv30_MODBUS::getPZEM004Frequency() {
double frequency;
uint8_t result;

  result = _node.readInputRegisters(0x0000, 10);
  if (result == _node.ku8MBSuccess)  {
    frequency = (_node.getResponseBuffer(PZEM004Tv30_ADDR_FREQUENCY)/10.0f);
  #if PZEM004Tv30_MODBUS_DEBUG == 1
    Serial.print("Frequency: "); Serial.println(frequency);
  #endif 
  }
  else {
  #if PZEM004Tv30_MODBUS_DEBUG == 1
      Serial.print("Error (frequency)");
  #endif    
    }
  return frequency;  
}

// Get the power factor
double PZEM004Tv30_MODBUS::getPZEM004Pf() {
double pf;
uint8_t result;

  result = _node.readInputRegisters(0x0000, 10);
  if (result == _node.ku8MBSuccess)  {
    pf = (_node.getResponseBuffer(PZEM004Tv30_ADDR_FREQUENCY)/100.0f);
  #if PZEM004Tv30_MODBUS_DEBUG == 1
    Serial.print("Pf: "); Serial.println(pf);
  #endif 
  }
  else {
  #if PZEM004Tv30_MODBUS_DEBUG == 1
      Serial.print("Error (pf)");
  #endif    
    }
  return pf;  
}

// Get the alarm
double PZEM004Tv30_MODBUS::getPZEM004Alarm() {
double alarm;
uint8_t result;

  result = _node.readInputRegisters(0x0000, 10);
  if (result == _node.ku8MBSuccess)  {
    alarm = (_node.getResponseBuffer(PZEM004Tv30_ADDR_ALARM));
  #if PZEM004Tv30_MODBUS_DEBUG == 1
    Serial.print("Alarm: "); Serial.println(alarm);
  #endif 
  }
  else {
  #if PZEM004Tv30_MODBUS_DEBUG == 1
      Serial.print("Error (alarm)");
  #endif    
    }
  return alarm;  
}
