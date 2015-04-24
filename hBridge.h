#ifndef HBRIDGE_H_
#define HBRIDGE_H_

/// Como esto es C prefiero usar macros que const
//Motor 1
#define AIN1 9 //Direccion
#define AIN2 8 //Direccion
#define PWMA 3 //Velocidad
//Motor 2
#define BIN1 11 //Direcccion
#define BIN2 12 //Direccion
#define PWMB 5 //Velocidad

#define STBY 10
#include <Arduino.h>

class hBridge{
  public:
  typedef enum{ADELANTE, ATRAS, GIRO_DER, GIRO_IZQ} movimiento; 
  typedef enum{MOTOR1, MOTOR2} motor;
  
  hBridge();
  void motoresStandby();
  void detenerMotor(motor);
  void detenerMotores();
  void setVelocidad(motor, int);
  void setVelocidades(int, int);
  
  void moverMotores(movimiento);
  void moverMotor(motor, movimiento);
  
  private:
  int velocidadA, velocidadB;
};

#endif // HBRIDGE_H_
