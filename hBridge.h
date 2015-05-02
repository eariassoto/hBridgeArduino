#ifndef HBRIDGE_H_
#define HBRIDGE_H_

#include <Arduino.h>

class hBridge{
  public:
  typedef enum{ADELANTE, ATRAS, GIRO_DER, GIRO_IZQ} movimiento; 
  typedef enum{MOTOR1, MOTOR2} motor;
  
  hBridge(int, int, int, int, int, int, int);

  void motoresStandby();
  void detenerMotor(motor);
  void detenerMotores();
  void setVelocidad(motor, int);
  void setVelocidades(int, int);
  
  void moverMotores(movimiento);
  void moverMotor(motor, movimiento);
  
  private:
  const int AIN1, AIN2, PWMA, BIN1, BIN2, PWMB, STBY;
  int velocidadA, velocidadB;
};

#endif // HBRIDGE_H_
