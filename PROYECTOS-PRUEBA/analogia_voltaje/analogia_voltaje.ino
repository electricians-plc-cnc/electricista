/*
Autor: María Eugenia Szwedowski
ME Diseño Web - Peak Power Electricistas
Fecha: 07/12/2020
*/

    const float bitPLC = 10;
    const float voltMax = 10;
    const float yMax = 32767;
    const float yMin = 200;
    const float xMin = 0;
    float xMax = pow(2,bitPLC);
    float pinAnaINx = 600;
    float pinAnaINy = 3500;

void setup(){
    Serial.begin(9600);
    halloAnalogico();
    
  } 

void loop(){

} 

float entradaAnalogico(float x1, float x2, float y1, float y2){
 float pendiente = (y2-y1)/(x2-x1);
 return pendiente;
} 

float halloX(float x1, float x2, float y1, float y2, float inY){
 float pendiente = (y2-y1)/(x2-x1);
 float b = y1-((y2-y1)/(x2-x1))*x1;
 float y = (pendiente*inY)+b;
 return y;
} 

float halloY(float x1, float x2, float y1, float y2, float inX){
 float pendiente = (y2-y1)/(x2-x1);
 float b = y1-((y2-y1)/(x2-x1))*x1;
 float x = ((inX-b)/pendiente);
 return x;
} 

  void halloAnalogico(){
    
    entradaAnalogico(xMin, xMax, yMin, yMax);
    float valorX = halloX(xMin, xMax, yMin, yMax, pinAnaINx);
    float valorY = halloY(xMin, xMax, yMin, yMax, pinAnaINy);
    
    Serial.println("------------");
    Serial.println("VALOR DE X: ");
    Serial.println(valorX);
    Serial.println();
    
    Serial.println("VALOR DE Y: ");
    Serial.println(valorY);
    Serial.println();
} 

