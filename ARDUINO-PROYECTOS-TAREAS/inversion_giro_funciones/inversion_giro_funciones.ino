/*
  Autor: María Eugenia Szwedowski
  ME WEB Diseños && Peak Power Instalaciones Eléctricas
  Sitio web: me-webs.github.io
  Sitio web: peak-power-electricistas.github.io
  Fecha 18/12/2020
  
  Objetivo: Apertura de barrera.
  
  Sensores de Entrada:
  - I3 - Sensor en piso que detecta el auto que esta deseando salir y activa la barrera que está en posición baja.
  - I4 - Sensor en piso que detectará que el auto ya pasó y está yéndose.
  - I1 - Sensor inductivo que detecta que la barrera esta arriba.
  - I2 - Sensor inductivo que detecta que la barrera esta baja. 
  
  Sensores de Salida:
  - Q1 - Se activará relé NC que estará conectado a un contactor de 230v en circuito de control de un motor. Giro de apertura.
  - Q2 - Se activará otro rele NC, desactivándose obligatoriamente el anterior, a un contacto de 230v en circuito de control de motor. Giro de cierre.
 */



const int pin_contactor_up = 2; // q1 - Contactor inicia motor giro hacia arriba. 
const int pin_contactor_down = 3; // q2 - Contactor inicia motor giro hacia abajo. 

int pin_barrera_up = 6; // i1 - Giro hacia la derecha, activará el contactor número 1
int pin_barrera_down = 4; // i2 - Giro hacia la izquierda , activará el contactor número 2
int pin_auto_sale = 9; // i3 - Sensor que activará la aplicación de la función del giro hacia la derecha
int pin_auto_salio = 10; // i4 - Sensor que activará la aplicación de la función del giro hacia la izquierda

const int tiempo = 1000;


void setup() {                
  
  Serial.begin(9600);

  pinMode(pin_contactor_up, OUTPUT); // Declaro la salida.
  pinMode(pin_contactor_down, OUTPUT); // Declaro la salida
  
  pinMode(pin_barrera_up, INPUT_PULLUP);// Declaro la entrada.
  pinMode(pin_barrera_down, INPUT_PULLUP);// Declaro la entrada.
  
  pinMode(pin_auto_sale, INPUT_PULLUP);// Declaro la entrada.
  pinMode(pin_auto_salio, INPUT_PULLUP);// Declaro la entrada.
}


void loop() {
    Serial.begin(9600);

    
    
    derecha();
    delay(tiempo);
    izquierda();
    delay(tiempo);

    
 }
 
 
void derecha(){
  int estado_auto_sale = digitalRead(pin_auto_sale); // pin 9
  boolean activado = false;
  if (estado_auto_sale == LOW){
    activado = true;
    if(activado==true){
      inversionGiroIzquierda();
    }
  }
}

void izquierda(){
  int estado_auto_salio = digitalRead(pin_auto_salio); // pin 10
  boolean activado = false;
  if (estado_auto_salio == LOW){
    activado = true;
    if(activado==true){
      inversionGiroDerecha();
    }
  }
}

void inversionGiroDerecha(){
  
  boolean giro_cierro = false;
  boolean giro_abro = false;
  
  int estado_barrera_up = digitalRead(pin_barrera_up); // i2 - pin 6
  int estado_barrera_down = digitalRead(pin_barrera_down); // i3 - pin 4
 
        if (estado_barrera_up == HIGH && estado_barrera_down == LOW ){
          
          giro_cierro = true;
          giro_abro = false;

              if(giro_cierro == true && giro_abro == false ){
              
                  digitalWrite(pin_contactor_up, HIGH);   
                  digitalWrite(pin_contactor_down, LOW); 
                  
              }
   
        }if (estado_barrera_up == LOW && estado_barrera_down == HIGH ){
          
          giro_cierro = false;
          giro_abro = true;
                
                if (giro_cierro == false && giro_abro == true ){
            
                  digitalWrite(pin_contactor_up, LOW);   
                  digitalWrite(pin_contactor_down, LOW); 
                 

              }      
       }
       
}       
       
       
       
       
void inversionGiroIzquierda(){
  
  boolean giro_cierro = false;
  boolean giro_abro = false;
  
  int estado_barrera_up = digitalRead(pin_barrera_up); 
  int estado_barrera_down = digitalRead(pin_barrera_down); 
 
        if (estado_barrera_up == LOW && estado_barrera_down == HIGH ){
          
          giro_cierro = true;
          giro_abro = false;

              if(giro_cierro == true && giro_abro == false ){
              
                  digitalWrite(pin_contactor_up, LOW);   
                  digitalWrite(pin_contactor_down, HIGH); 
                  
              }
   
        }if (estado_barrera_up == HIGH && estado_barrera_down == LOW ){
          
          giro_cierro = false;
          giro_abro = true;
                
                if (giro_cierro == false && giro_abro == true ){
            
                  digitalWrite(pin_contactor_up, LOW);   
                  digitalWrite(pin_contactor_down, LOW); 
                 

              }      
       }
 
}
