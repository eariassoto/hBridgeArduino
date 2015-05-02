#include "hBridge.h"

hBridge puenteH(9,8,3,11,12,5,10);
byte byteLeido;

void setup(){
  Serial.begin(9600);
}

void loop(){
  if (Serial.available()) {
    // si la comunicacion en serie esta disponible
    byteLeido = Serial.read(); // lee el primer byte que
    
    switch(byteLeido){
      case 'q':
      puenteH.moverMotores(hBridge::ADELANTE);
      break;
      case 'w':
      puenteH.moverMotores(hBridge::ATRAS);
      break;
      case 'e':
      puenteH.moverMotores(hBridge::GIRO_DER);
      break;
      case 'r':
      puenteH.moverMotores(hBridge::GIRO_IZQ);
      break;
      case 't':
      puenteH.detenerMotores();
      break;
    }
  }
}








