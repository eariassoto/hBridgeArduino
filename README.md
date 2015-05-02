# hBridgeArduino

Un puente H es un circuito que controla la polaridad y velocidad de motores de corriente continua. Con este código podemos manejar uno de estos con un microcontrolador, por ejemplo un Arduino.

## Cómo usar
El sketch es un mero ejemplo. Lo que hace es leer caracteres del puerto Serial que mueven y detienen los motores. Lo importantes que una instancia de la clase hBridge engloba todo lo necesario para poder controlar los motores. Los pines se pueden modificar fácilmente. Este código lo corrí con [este circuito](http://www.crcibernetica.com/motor-driver-1a-dual-tb6612fng/) pero se puede adaptar para similares.

Para más detalles pueden visitar esta página http://probablyageek.com/puentes-h-para-controlar-motores-dc/
