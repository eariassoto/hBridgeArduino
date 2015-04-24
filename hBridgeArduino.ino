#include "hBridge.h"

hBridge puenteH;

void setup(){}

void loop(){
  puenteH.moverMotor(hBridge::ADELANTE);
  delay(2000);
  puenteH.moverMotor(hBridge::ATRAS);
  delay(2000);
}








