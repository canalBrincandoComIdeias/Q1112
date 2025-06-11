#include "EmonLib.h"                
#define pinSensor 4   //ARDUINO=A0   ESP32=27   ESP32C3mini=4

EnergyMonitor emon1;                

int tensao = 127;  //volts

void setup()
{  
  Serial.begin(9600);
  
  //ARDUINO
  // .current: porta, calibracao
  //emon1.current(pinSensor, 0.191);  //calibrado para max. 100mA     (teórico: 2000/33000=0.061)
  //emon1.current(pinSensor, 0.646);  //calibrado para max. 500mA     (teórico: 2000/6800=0.294)
  //emon1.current(pinSensor, 1.269);  //calibrado para max. 1A        (teórico: 2000/3300=0.606)
  //emon1.current(pinSensor, 8.84);   //calibrado para max. 10A       (teórico: 2000/330=6.061)


  //ESP32
  // .current: porta, calibracao
  //emon1.current(pinSensor, 0.053);  //calibrado para max. 100mA     (teórico: 2000/22000=0.091)
  //emon1.current(pinSensor, 0.180);  //calibrado para max. 500mA     (teórico: 2000/4300=0.465)
  //emon1.current(pinSensor, 0.344);  //calibrado para max. 1A        (teórico: 2000/2200=0.909)
  emon1.current(pinSensor, 2.466);  //calibrado para max. 10A       (teórico: 2000/220=9.091)
}

void loop()
{
  double Irms = emon1.calcIrms(4096);  //(Arduino=1480    ESP32=4096)

  Serial.print(Irms * tensao);	 // Potencia em Watt
  Serial.print("w ");
  Serial.print(Irms, 4);		         // Irms (Corrente RMS)
  Serial.println("A ");
}