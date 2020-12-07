/*
Autor: María Eugenia Szwedowski
ME Diseño Web - Peak Power Electricistas
Fecha: 07/12/2020
*/

int IN1 = 4;			// pin digital 8 de Arduino a IN1 de modulo controlador
int IN2 = 5;			// pin digital 9 de Arduino a IN2 de modulo controlador
int IN3 = 6;			// pin digital 10 de Arduino a IN3 de modulo controlador
int IN4 = 7;			// pin digital 11 de Arduino a IN4 de modulo controlador
int boton = 3;
int boton2 = 9;
int led =8;
int tiempo = 500;
int demora = 11;   		// demora entre pasos, no debe ser menor a 10 ms.
// paso completo con maximo torque
int paso [4][4] =		// matriz (array bidimensional) con la secuencia de PASO DOBLE
{
  {1, 1, 0, 0},
  {1, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);		// todos los pines como salida
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(boton, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int botonON=digitalRead(boton);
  int botonOFF=digitalRead(boton2);
  
  if(botonON == HIGH){
    digitalWrite(led,HIGH);
    Serial.println(" boton - ON");
    //delay(tiempo);
      for (int i = 0; i < 512; i++)	// 512*4 = 2048 pasos
      {
        for (int i = 0; i < 4; i++)		// bucle recorre la matriz de a una fila por vez
        {			
        		// para obtener los valores logicos a aplicar
          digitalWrite(IN1, paso[i][0]);	// a IN1, IN2, IN3 e IN4
          digitalWrite(IN2, paso[i][1]);
          digitalWrite(IN3, paso[i][2]);
          digitalWrite(IN4, paso[i][3]);
          
          delay(demora);
        }
      }
    }else if(botonOFF == HIGH){
      digitalWrite(led, LOW);
      Serial.println(" boton - OFF");
      delay(tiempo);
      digitalWrite(IN1, LOW);	// detiene 
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(demora);
    }else{
      
      //Serial.println(" boton - OF");
      //digitalWrite(led,LOW);
      //delay(tiempo);
     
     }

}
