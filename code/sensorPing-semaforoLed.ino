/*
   ################
   #   Lab15125   #
   ################
Este programa usa un sensor de proximidad PING para 
medir la distancia entre un objeto y el sensor. Se escogen 
una distancia máxima y una distancia mínima de 327.0 cm
y 2.5 cm respectivamente, las cuales son muy cercanas al 
rango de operación del instrumento.

Cuando el objeto detectado se encuentra dentro de un rango
previamente definido, se enciende un led de un color específico.
- Led verde:    entre   2.5 cm y 109.0 cm
- Led amarillo: entre 109.0 cm y 218.0 cm
- Led rojo:     entre 218.0 cm y 327.0 cm

El programa también ejecuta comunicación serial e imprime 
continuamente el valor de la distancia mínima, la distancia 
máxima y la distancia actual a la que se encuentra un objeto
detectado por el sensor.

// ********************************************** //
  Ping))) Sensor

  This sketch reads a PING))) ultrasonic
  rangefinder and returns the distance to the
  closest object in range. To do this, it sends a
  pulse to the sensor to initiate a reading, then
  listens for a pulse to return.  The length of
  the returning pulse is proportional to the
  distance of the object from the sensor.

  The circuit:
   * +V connection of the PING))) attached to +5V
   * GND connection attached to ground
   * SIG connection attached to digital pin 7
  http://www.arduino.cc/en/Tutorial/Ping

  This example code is in the public domain.
*/

float distancia = 0.0;
int ledVerde = 2;
int ledAmarillo = 3;
int ledRojo = 4;
float distMin = 2.5; // distancia mínima de operación
float distMax = 327.0; // distancia máxima de operación

long readUltrasonicDistance(int triggerPin, int echoPin){
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup(){
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  // measure the ping time in cm
  float distancia = 0.01723 * readUltrasonicDistance(7, 7);
  
  if ((distancia >= distMin) && distancia <= distMax/3){
    digitalWrite(ledVerde, HIGH);
  }
  else {
    digitalWrite(ledVerde, LOW);
  }
  if ((distancia > distMax/3) && (distancia <= distMax*2/3)){
    digitalWrite(ledAmarillo, HIGH);
  }
  else {
    digitalWrite(ledAmarillo, LOW);
  }
  if ((distancia > distMax*2/3) && (distancia <= distMax)){
    digitalWrite(ledRojo, HIGH);
  }
  else {
    digitalWrite(ledRojo, LOW);
  }
  
  Serial.print("distancia minima: ");
  Serial.print(distMin);
  Serial.print("\t distancia maxima: ");
  Serial.print(distMax);
  Serial.print("\t distancia: ");
  Serial.println(distancia);
      
  delay(10);
}
 #######################
 #   Fin de programa   #
 #######################
*/
