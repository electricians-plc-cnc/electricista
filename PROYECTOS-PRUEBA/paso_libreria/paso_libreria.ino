#include <Stepper.h>

Stepper motor(2048, 4, 6, 5, 7);
int derechaB = 3;
int izquierdaB = 9;
int estadoBotonD;
int estadoBotonI;
int led =8;
int tiempo = 1000;
int demora = 11;   		// demora entre pasos, no debe ser menor a 10 ms.


void setup() {
  Serial.begin(9600);
  
  pinMode(derechaB, INPUT);		// todos los pines como salida
  pinMode(izquierdaB, INPUT);
   
  pinMode(derechaB, LOW);
  pinMode(izquierdaB, LOW);
  
  pinMode(led, OUTPUT);
  
  motor.setSpeed(10); // en RPM valores 1,2,3 para 28BYJ-48
}

void loop() {
  int estadoBotonD=digitalRead(derechaB);
  int estadoBotonI=digitalRead(izquierdaB);
  
         if(estadoBotonD == HIGH){
    
        digitalWrite(led,HIGH);
        motor.step(2048); // cantidad de pasos.
        delay(tiempo);
    
      } if (estadoBotonI == HIGH){
        
        digitalWrite(led,LOW);
        motor.step(-2048); // cantidad de pasos.
        delay(tiempo);
        
    }if ((estadoBotonD == HIGH) && (estadoBotonI == HIGH)){
      
      Serial.println("Error Diseño");
  }
}
