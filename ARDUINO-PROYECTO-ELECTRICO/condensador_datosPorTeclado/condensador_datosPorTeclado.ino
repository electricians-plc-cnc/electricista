/* Autor: María Eugenia Szwedowski - ME Diseño Web - Peak Power Eléctricistas.
AJUSTE DEL COSENO DE PHI POR CONDENSADORES. En esta segunda instancia se plantea la aplicación de datos ingresados externamente.
El objetivo es aplicar las fórmulas adquiridas en el curso técnico de Mantenimiento Industrial para el proyecto arduino.
Observación: en esta etapa estoy analizando que los datos parseados de string a int no pueden superar más de 4 char sino creashea
Montevideo, Uruguay.
Fecha: 19/12/2020
*/

String dato=""; // Ingreso valor numérico de potencia activa por teclado
String dato1=""; // Ingreso valor numérico de frecuencia por teclado
String dato2=""; // Ingreso valor numérico de voltaje de la línea por teclado
String dato3=""; // Ingreso valor numérico de amperaje de la línea por teclado
const float lin = 1.00;
const float linTrifasica = sqrt(3);
const float cosPhiUTE = 0.9200;




void setup() { 
  Serial.begin(9600); // Abre puerto serie con la velocidad de 9600 baudios (bit por segundo) 
  inicio();
}


void loop() {
}



// -------------- FÓRMULA CALCULO EL GRADO DE COSENO PHI  ------------------------//
float cosPhiGrados(float cosPhi){
  float grados = acos(cosPhi)*180/PI;
  return grados;
} 

// -------------- FÓRMULA CALCULO LA TANGENTE DEL COSENO PHI ------------------------//
  float tanPhi(float cosPhi){
  float tangente = tan(acos(cosPhi))*180/PI*PI/180;
  return tangente;
} 

// -------------- FÓRMULA CALCULO POTENCIA APARENTE --> valor a hallar ------------------------//

  float pAparente(float voltaje, float amperaje, float lin){
  float potAparente = voltaje * amperaje * lin;
  return potAparente;
} 

// -------------- FÓRMULA CALCULO COSENO DE PHI --> valor a hallar  ------------------------//
  float cosPhiHallo(float potActiva,float potAparente){
  float cosPhiHallado=potActiva/potAparente;
  return cosPhiHallado;
} 

// -------------- FÓRMULA CALCULO DE CONDENSADOR --> valor a hallar  ------------------------//
  float halloC(float v,float i,float phi,float line){
  float condensador=v*i*phi*line;
  return condensador;
} 

// -------------- FÓRMULA CALCULO DE CONDENSADOR --> valor a hallar  ------------------------//
  float halloMicroFaradio( float var, float hz,float v){
  float microFaradio = (var * pow(10,9)) / (2*PI*hz*pow(v,2));
  return microFaradio;
} 



void inicio(){
  int pActiva;
  int frecuencia;
  int voltaje;
  int amperaje;
  
  Serial.println("Ingrese la Potencia Activa : ");
  while(Serial.available()==0){};// Pausa
  
  if(Serial.available() > 0){
    delay(20);
    while (Serial.available() > 0) {
    dato += (char)Serial.read();
      }
    Serial.print("El valor es: ");
    Serial.println(dato);
    pActiva = dato.toInt();
    Serial.flush();
  }
  
  Serial.println("Ingrese la frecuencia : ");
  while(Serial.available()==0){};// Pausa
  
  if(Serial.available() > 0){
    delay(20);
    while (Serial.available() > 0) {
    dato1 += (char)Serial.read();
      }
    Serial.print("El valor es: ");
    Serial.println(dato1);
    frecuencia = dato1.toInt();
    Serial.flush();
  }  
  
  
  
  Serial.println("Ingrese el voltaje de línea : ");
  while(Serial.available()==0){};// Pausa
  
  if(Serial.available() > 0){
    delay(20);
    while (Serial.available() > 0) {
    dato2 += (char)Serial.read();
      }
    Serial.print("El valor es: ");
    Serial.println(dato2);
    voltaje = dato2.toInt();
    Serial.flush();
  } 
  
  
  Serial.println("Ingrese el amperaje de línea : ");
  while(Serial.available()==0){};// Pausa
  
  if(Serial.available() > 0){
    delay(20);
    while (Serial.available() > 0) {
    dato3 += (char)Serial.read();
      }
    Serial.print("El valor es: ");
    Serial.println(dato3);
    amperaje = dato3.toInt();
    Serial.flush();
  } 
  Serial.println("");
  Serial.println("------------");
  halloDatos(pActiva, frecuencia, amperaje, voltaje);
}


// -------------- DATOS A HALLAR ------------------------//
    void halloDatos(int p, int f, int a, int v){
    
    float potenciaACTIVA =(float)p;
    float frecuencia = (float)f;
    float amper=(float)a;
    float volt=(float)v;
    
    Serial.println("DATOS HALLADOS DE LA LINEA");
    Serial.print("LINEA - Potencia Aparente : ");
    float potenciaAp = pAparente(volt, amper, lin);
    Serial.println(potenciaAp, 4);
    Serial.print("LINEA- Potencia Activa : ");
    Serial.println(potenciaACTIVA, 4);
    Serial.print("LINEA - Coseno Phi: ");
    float coseno = cosPhiHallo(potenciaACTIVA,potenciaAp);
    float phi = coseno;
    Serial.println(coseno, 4);
    float grados = cosPhiGrados(coseno);
    Serial.print("LINEA - Coseno Phi Grados : ");
    Serial.println(grados, 4);
    Serial.print("LINEA - Frecuencia Hz : ");
    Serial.println(frecuencia, 4);

    for(int i=0; i<=1; i++){
    Serial.println();
      } 
    Serial.print("------------");
    Serial.println("CONDENSADOR INICIAL: ");
    Serial.print("Calculado en VAR - ");
    float senoPhi = sin(acos(coseno)*180/PI*PI/180) ;
    float conVAR = halloC(volt, amper, senoPhi, lin);
    Serial.println(conVAR, 4);
    Serial.println(senoPhi, 4);
    
    for(int i=0; i<=1; i++){
    Serial.println();
      } 
    Serial.print("------------");
    Serial.print("DATOS CORREGIDOS LUEGO DE AGREGAR CONDENSADOR");
    Serial.println();
    Serial.println("POTENCIA APARENTE CORREGIDA: ");
    float sCorregida = potenciaACTIVA / cosPhiUTE;
    Serial.print("Calculado en VA - ");
    Serial.println(sCorregida);
    Serial.println();
    Serial.println("POTENCIA REACTIVA CORREGIDA: ");
    float sCorr = pow(sCorregida,2);
    float pActive = pow(potenciaACTIVA,2);
    float resta = sCorr - pActive;
    float rCorregida = sqrt(resta);
    Serial.print("Calculado en VAR - ");
    Serial.println(rCorregida);
    Serial.println();
    Serial.println("INTENSIDAD FINAL: ");
    float intFinal = sCorregida / volt;
    Serial.print("Calculado en AMPER - ");
    Serial.print(intFinal);
    
    for(int i=0; i<=1; i++){
    Serial.println();
      } 
    Serial.print("------------");
    Serial.println("CONDENSADOR A SOLICITAR: ");
    float varCond = potenciaACTIVA * ((tanPhi(coseno) - tanPhi(cosPhiUTE)));
    Serial.print("Calculado en VAR - ");
    Serial.print(varCond);
    
    Serial.println("Microfaradios del Condensador: ");
    float microFarad = halloMicroFaradio(varCond,frecuencia,volt);
    Serial.print("Calculado en  µF -  ");
    Serial.print(microFarad);
    
    Serial.println("Intensidad del Condensador: ");
    float amperCondensador = varCond/volt;
    Serial.print("Calculado en  µF -  ");
    Serial.print(microFarad);
    
    }



// -------------- DATOS UTE ------------------------//
    void uteDatos(){
    Serial.begin(9600);
    Serial.println("DATOS INICIALES POR UTE");
    Serial.print("UTE - Coseno de Phi : ");
    Serial.println(cosPhiUTE, 4);
    Serial.print("UTE - Coseno de Phi Grados : ");
    Serial.println(cosPhiGrados(cosPhiUTE), 4);
    Serial.print("UTE - Tangente de Phi : ");
    Serial.println(tanPhi(cosPhiUTE), 4);
    for(int i=0; i<=1; i++){
    Serial.println();
    } 
    Serial.print("------------");
    
    } 
