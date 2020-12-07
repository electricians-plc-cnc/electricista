/*
Autor: María Eugenia Szwedowski
ME Diseño Web - Peak Power Electricistas
Fecha: 07/12/2020
*/

int sCuenta = 0;
int sMaximo = 3;
int pinSestado = 0;
int pinPVEestado = 0;
int pinPMEestado = 0;
int pinPVIestado = 0;
int pinPMIestado = 0;
int tiempo = 500;
int tiempoExtra = 10000;
boolean opcionPuerta = false;
boolean opcionPuertaInterna = false;


const int pinS = 45; //i3
const int pinPVE = 36; // i1
const int pinPME = 32; // i2
const int pinPVI = 11; // i4
const int pinPMI = 10; // i5
const int pinBOMBILLA1 = 2; // q0
const int pinBOMBILLA2 = 3; // q0
const int pinBOMBILLA3 = 4; // q0
const int pinCV = 51; // q1
const int pinCM = 53; // q2

void setup(){
  
  pinMode(pinS, INPUT);// Declaro la entrada.
  pinMode(pinPVE, INPUT);// Declaro la entrada.
  pinMode(pinPME, INPUT);// Declaro la entrada.
  pinMode(pinBOMBILLA1, OUTPUT); // Declaro la salida
  pinMode(pinBOMBILLA2, OUTPUT); // Declaro la salida
  pinMode(pinBOMBILLA3, OUTPUT); // Declaro la salida
  pinMode(pinCV, OUTPUT); // Declaro la salida
  pinMode(pinCM, OUTPUT); // Declaro la salida

  
  }
  

void loop(){
  
  sensorMonedas();
  if(opcionPuerta==true){
  opciones();
  delay(tiempo);
  }else{
    
    digitalWrite(pinCV, LOW);
    digitalWrite(pinCM, LOW);
    opcionPuerta=false;
    
    }
}


void opciones(){
    Serial.begin(9600);

    pinPVEestado = digitalRead(pinPVE);
    pinPMEestado = digitalRead(pinPME);
    pinPVIestado = digitalRead(pinPVI);
    pinPMIestado = digitalRead(pinPMI);
    digitalWrite(pinBOMBILLA1, HIGH);
    digitalWrite(pinBOMBILLA2, HIGH);
    digitalWrite(pinBOMBILLA3, HIGH);
    opcionPuertaInterna = true;
    
    if(pinPMEestado == HIGH){
        
      Serial.println('Seleccionado Mujeres');
        digitalWrite(pinCM, HIGH);
        delay(tiempoExtra);
        opcionPuerta=false;
        
      
      }else if(pinPVEestado == HIGH){
        
        Serial.println('Seleccionado Varones');
        digitalWrite(pinCV, HIGH);
        delay(tiempoExtra);
        opcionPuerta=false;
        
      
      }else{
        digitalWrite(pinCV, LOW);
        digitalWrite(pinCM, LOW);
     
     
     
     
   } 
}  


void sensorMonedas(){

  Serial.begin(9600);
  pinSestado = digitalRead(pinS);
  
  if(pinSestado == HIGH){
        sCuenta++;
        Serial.println(sCuenta);
        for(int i=0; i <= sMaximo; i++){
                 
          if(i=1){
            digitalWrite(pinBOMBILLA1, HIGH);
            delay(tiempo);
            
            }if(i=2){
            digitalWrite(pinBOMBILLA2, HIGH);
            delay(tiempo);
            
            }if(i=3){
            digitalWrite(pinBOMBILLA3, HIGH);
            delay(tiempo);
            
          }
        }
    	
  }else{
    digitalWrite(pinBOMBILLA1, LOW);
    digitalWrite(pinBOMBILLA2, LOW);
    digitalWrite(pinBOMBILLA3, LOW);
  }
  
  if(sCuenta==3){
    opcionPuerta=true;
    digitalWrite(pinBOMBILLA1, HIGH);
    digitalWrite(pinBOMBILLA2, HIGH);
    digitalWrite(pinBOMBILLA3, HIGH);
    delay(tiempo);
    sCuenta=0;
    
   
 }     
}

void opcionesSalidas(){
    
    
}  

    

