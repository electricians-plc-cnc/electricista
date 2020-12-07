
/* Autor: María Eugenia Szwedowski & Diego Velázquez - ME Diseño Web - Peak Power Eléctricistas.
El objetivo es aplicar las fórmulas adquiridas en el curso técnico de Mantenimiento Industrial para el proyecto arduino.
Fecha: 07/12/2020
*/

    const float Inductancia = 0.1;  // MODIFICAR: ingresará por dato analógico
    const float Capacitancia = 500; // MODIFICAR: ingresará por dato analógico
    const float hertz = 50; // MODIFICAR: ingresará por dato analógico

void setup(){
  Serial.begin(9600);
    
    halloDatos(); 
  } 

void loop(){} 



// -------------- FÓRMULA RESONANCIA FRECUENCIA  ------------------------//
float halloFrecuencia(float hy, float mF){
  float hz = ( 1 / ( 2*PI*sqrt(hy*mF) ) );
  return hz;
} 

// -------------- FÓRMULA AJUSTO CAPACITANCIA  ------------------------//
float halloCapacitancia(float hy, float f){
  float dato = 1/(2*PI);
  float capacitores = (pow(dato,2))/(pow(f,2)*hy);
  return capacitores;
} 

// -------------- FÓRMULA AJUSTO INDUCTANCIA  ------------------------//
float halloInductancia(float faradio, float f){
  float inductores = pow((1/(2*PI)),2)/(pow(f,2)*faradio);
  return inductores;
} 

// -------------- DATOS A HALLAR ------------------------//
    void halloDatos(){
      
    Serial.println();
    
    Serial.println("DATOS INGRESADOS:");
    Serial.print("Ingreso - Hz : ");
    Serial.println(hertz,4);
    Serial.print("Ingreso - Hy : ");
    Serial.println(Inductancia,4);
    Serial.print("Ingreso - uF : ");
    Serial.println(Capacitancia,4);
    Serial.println("- - - - - - - - - - ");
    Serial.println();
    
    Serial.println("FRECUENCIA DE RESONANCIA");
    Serial.print("RESULTADO - Hz : ");
    float resultado = halloFrecuencia(Inductancia, Capacitancia);
    Serial.print(resultado,4);
    
    Serial.println();
    Serial.println();
    
    Serial.println("AJUSTE DE RESONANCIA POR CAPACITOR:");
    Serial.print("RESULTADO - uF : ");
    float capacitor = halloCapacitancia(Inductancia,hertz);
    Serial.print(capacitor,10);
    Serial.println();
    
    Serial.println();
    Serial.println("AJUSTE DE RESONANCIA POR INDUCTOR:");
    Serial.print("RESULTADO - Hy : ");
    float inductor = halloInductancia(Capacitancia,hertz);
    Serial.print(inductor,10);

    }


