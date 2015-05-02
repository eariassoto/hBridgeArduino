#include "hBridge.h"

hBridge::hBridge(int _AIN1, int _AIN2, int _PWMA, int _BIN1, int _BIN2, int _PWMB, int _STBY): 
AIN1(_AIN1), AIN2(_AIN2), PWMA(_PWMA), BIN1(_BIN1), BIN2(_BIN2), PWMB(_PWMB), STBY(_STBY){
  // defino los pines como de salida
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(STBY, OUTPUT);
  
  // velocidad maxima por defecto
  velocidadA = 255;
  velocidadB = 255;
}
/*
hBridge::hBridge(int v){
  // defino los pines como de salida
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(STBY, OUTPUT);
  
  velocidadA = v;
  velocidadB = v;
}
*/
void hBridge::motoresStandby(){
  digitalWrite(STBY, LOW);
}

void hBridge::detenerMotor(motor nMotor){
  if (nMotor == MOTOR1) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
  }
  else{
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
  } 
}

void hBridge::detenerMotores(){
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}

void hBridge::setVelocidad(motor nMotor, int v){
  if(v >= 0 && v <= 255){
    if (nMotor == MOTOR1)
     velocidadA = v;
    else
     velocidadB = v;
  }
}

void hBridge::setVelocidades(int vA, int vB){
  velocidadA = vA;
  velocidadB = vB;
}

void hBridge::moverMotor(motor nMotor, movimiento tMovimiento){
  
  boolean pinIn1; // util para decidir luego la direccion del motor
   
  if (tMovimiento == ADELANTE)
    pinIn1 = HIGH;
  else
    pinIn1 = LOW;

  if(nMotor == MOTOR1){
    // vemos que los pares de interruptores siempre van al opuesto
    digitalWrite(AIN1, pinIn1);
    digitalWrite(AIN2, !pinIn1); 

    // con esto regulamos la velocidad
    analogWrite(PWMA, velocidadA);
  }
  else{
    digitalWrite(BIN1, pinIn1);
    digitalWrite(BIN2, !pinIn1);  
    analogWrite(PWMB, velocidadB);
  }
  digitalWrite(STBY, HIGH);
}

void hBridge::moverMotores(movimiento tMovimiento){
  switch(tMovimiento){
    case ADELANTE:
    moverMotor(MOTOR1, ADELANTE);
    moverMotor(MOTOR2, ADELANTE);
    break;
    case ATRAS:
    moverMotor(MOTOR1, ATRAS);
    moverMotor(MOTOR2, ATRAS);
    break;
    // para hacer giros movemos los motores en direcciones opuestas
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
