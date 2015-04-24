#include "hBridge.h"

hBridge::hBridge(){
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(STBY, OUTPUT);
  
  velocidadA = 255;
  velocidadB = 255;
}

void hBridge::motoresStandby(){
  digitalWrite(STBY, LOW);
}

void hBridge::detenerMotor(motor nMotor){
  if (nMotor == MOTOR1) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
  }
  else
  {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
  } 
}

void hBridge::frenarMotor(motor nMotor){
  if (nMotor == MOTOR1)
    analogWrite(PWMA, 0);
  else
    analogWrite(PWMB, 0);
}

void hBridge::setVelocidad(motor nMotor, int v){
  if(v >= 0 && v <= 255){
    if (nMotor == MOTOR1)
     velocidadA = v;
    else
     velocidadB = v;
  }
}

void hBridge::moverMotor(motor nMotor, movimiento tMovimiento){
  
  boolean pinIn1;
   
  if (tMovimiento == ADELANTE)
    pinIn1 = HIGH;
  else
    pinIn1 = LOW;

  if(nMotor == MOTOR1){
    digitalWrite(AIN1, pinIn1);
    digitalWrite(AIN2, !pinIn1); 
    analogWrite(PWMA, velocidadA);
  }
  else{
    digitalWrite(BIN1, pinIn1);
    digitalWrite(BIN2, !pinIn1);  
    analogWrite(PWMB, velocidadB);
  }
  digitalWrite(STBY, HIGH);
}

void hBridge::moverMotor(movimiento tMovimiento){
  switch(tMovimiento){
    case ADELANTE:
    moverMotor(MOTOR1, ADELANTE);
    moverMotor(MOTOR2, ADELANTE);
    break;
    case ATRAS:
    moverMotor(MOTOR1, ATRAS);
    moverMotor(MOTOR2, ATRAS);
    break;
    case GIRO_DER:
    moverMotor(MOTOR1, ADELANTE);
    moverMotor(MOTOR2, ATRAS);
    break;
    case GIRO_IZQ:
    moverMotor(MOTOR1, ATRAS);
    moverMotor(MOTOR2, ADELANTE);
    break;
  }
}
