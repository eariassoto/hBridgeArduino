#include "hBridge.h"

hBridge puenteH;

void setup(){}

void loop(){
  puenteH.moverMotores(hBridge::ADELANTE);
  delay(1000);
  puenteH.moverMotores(hBridge::ATRAS);
  delay(1000);
  puenteH.moverMotores(hBridge::GIRO_DER);
  delay(1000);
  puenteH.moverMotores(hBridge::GIRO_IZQ);
  
  
  puenteH.detenerMotores();
  delay(2000);
  
  puenteH.setVelocidades(128, 128);
  
  puenteH.moverMotores(hBridge::ADELANTE);
  delay(1000);
  puenteH.moverMotores(hBridge::ATRAS);
  delay(1000);
  puenteH.moverMotores(hBridge::GIRO_DER);
  delay(1000);
  puenteH.moverMotores(hBridge::GIRO_IZQ);
  delay(1000);
}








