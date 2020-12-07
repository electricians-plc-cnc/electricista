/*
Autor: María Eugenia Szwedowski
ME Diseño Web - Peak Power Electricistas
Fecha: 07/12/2020
*/
    const float bitPLC = 10;
    const float voltMax = 5;
    const float yMax = 100;
    const float yMin = 0;
    const float xMin = 0;
    float xMax = 1023;
    
    
    int sensorHumedad = A0;  
    int sensorLluvia = A1; 
    
    int rele = 8;
    int led1 = 6;      
    int led2 = 5; 
    int led3 = 4; 
    int tiempo = 1000;

float halloY(float x1, float x2, float y1, float y2, float inX){
 float m = (y2-y1)/(x2-x1);
 float b = y1-(((y2-y1)/(x2-x1))*x1);
 float x = (m*inX)+b;
 return x;
}



void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);  
  pinMode(led2, OUTPUT);  
  pinMode(led3, OUTPUT); 
  pinMode(rele, OUTPUT);  
  pinMode(sensorHumedad, INPUT); 
  pinMode(sensorLluvia, INPUT); 
}

void loop() {
  // read the value from the sensor:
  int sensorValor = analogRead(sensorHumedad);  
  int sensorLluv = analogRead(sensorLluvia); 
  float valorY = halloY(xMin, xMax, yMin, yMax, sensorValor);
  float valorYtotal = yMax - valorY;
  Serial.print(sensorLluv);
  Serial.print(": valor lluvia - ");
  Serial.print(valorYtotal);
  Serial.print("% de humedad - Valor bit: ");
  Serial.println(sensorValor);
  
  if(sensorLluv <= 500){
          if(sensorValor >=500 ){ // prende por huemedad
            digitalWrite(led1, HIGH); 
            digitalWrite(led2, LOW);  
            digitalWrite(led3, LOW);  
            digitalWrite(rele, LOW);
            delay(tiempo);    
          }if(sensorValor <= 499 ){
            digitalWrite(led1, LOW);
            digitalWrite(led2, HIGH);  
            digitalWrite(led3, HIGH); 
            digitalWrite(rele, HIGH);
            delay(tiempo);    
    }
    delay(tiempo); 
          }if(sensorLluv >= 500){
            digitalWrite(led1, LOW);
            digitalWrite(led2, HIGH);  
            digitalWrite(led3, HIGH); 
            digitalWrite(rele, HIGH);
            delay(tiempo);                  
            }
 }
