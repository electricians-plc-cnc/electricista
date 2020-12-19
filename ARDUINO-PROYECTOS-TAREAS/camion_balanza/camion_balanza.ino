/*
Autor: María Eugenia Szwedowski Bermúdez
ME Diseño Web - Peak Power Electricistas
Fecha: 17/12/2020

********** EJERCICIO PROPUESTO EN CLASE PLC: BALANZA-CAMIÓN **********
Escuela Técnica de Arroyo Seco, Mantenimiento Industrial.
Montevideo, Uruguay.

Se detecta un camión por sensor, se indica por cartel luminoso que debe subirse a la balanza. El cartel luminoso enciende 15 segundos.
En cada caso hay un registro en que se hará el conteo y establecerá las fechas de la gestión, además de la suma recaudada.
Los camiones de más de 20 toneladas deberán pagar una tasa de $350 más iva (22%).-

POSIBILIDADES: 
* PESO CORRECTO. Si la balanza indica que el peso es entre 2 a 20 toneladas, se enciende la luz verde y se acciona la barrera automáticamente, permitiendo la salida del camión sin inconvenientes. 
* PESO INCORRECTO. En caso de que pese más de 20 toneladas, se llama al inspector con luz de color naranja y quedará la posibilidad de accionarse la barrera por botón, permitiendo al inspector poner la multa correspondiente o aplicando la tasa establecida.
* CAMION EN REVELDÍA. Pasado 15 segundos iniciales más 120 segundos siguientes se accionará luz roja indicandole al inspector que hay camión en rebeldía.

*/

    float pinAnaINx = 600; // Se borará por dato analógico
    float pinAnaINy = 3500; // Se borrará por dato analógico


const int pin_camion_detected = 7 ; // i1 - Sensor de altura que indica la presencia de camión.
const int pin_barrera_up = 8; // i2 - Sensor que detecta que la barrera esta arriba. 
const int pin_barrera_down = 9; // i3 - Sensor que detecta que la barrera esta baja.
const int pin_pulsador_up = 10; // i4 - Pulsador de apertura
const float pin_weight_camion = 11; //  i5 - Peso del camion

const int estado_camion_detected = 0 ; // i1 
const int estado_barrera_up = 0; // i2 
const int estado_barrera_down = 0; // i3 
const int estado_pulsador_up = 0; // i4 

const int pin_cartel_detected =  12; // q0 - detección de camión.
const int pin_contactor_up = 22; // q1 - Contactor inicia motor giro hacia arriba.
const int pin_contactor_down = 23; // q2 - Contactor inicia motor giro hacia abajo.
const int pin_luz_verde = 24; // q3 - Luz verde.
const int pin_luz_naranja = 25; // q4 - Luz naranja.
const int pin_luz_roja = 26; // q5 - Luz roja.

const float bitPlc = 10; // Variable de Arduino.
const float voltMax = 5; // Variable de Voltaje Arduino.
const float yMax = 20000; // Peso máximo 20000 kg o 20 toneladas.
const float yMin = 2000; // Peso mínimo 2000 kg o 2 toneladas.
const float xMax = pow(2,bitPlc); // Variable analógica que son generalmente 1024.
const float xMin = 0;

const int miniTiempo = 1000; // 1 segundos en milisegundos.
const int tiempo = 15000; // 15 segundos en milisegundos.
const int tiempoExtra = 120000; // 120 segudnso en milisegundos.
const int tasa = 350; // Precio de la tasa por exceso de peso.
const int iva = 22; // Porcentaje del impuesto sobre la tasa.
const float tasaIva = float( (tasa * iva) /100); // Calculo Iva de la tasa independientemente.
const float tasaConIva = float(tasa) + tasaIva; // Calculo el Total que debe pagar el camionero.

boolean camion = false;
float pesoCamion = 0;

int contador = 0;
int totalContado = 0;
int sinPagarCta = 0;
int totalSinPagar = 0;


void setup(){
    Serial.begin(9600);
    
    pinMode(pin_camion_detected, INPUT);// Declaro la entrada.
    pinMode(pin_barrera_up, INPUT);// Declaro la entrada.
    pinMode(pin_barrera_down, INPUT);// Declaro la entrada.
    pinMode(pin_pulsador_up, INPUT);// Declaro la entrada.
    pinMode(pin_pulsador_up, INPUT);// Declaro la entrada.
    pinMode(pin_weight_camion, INPUT);// Declaro la entrada.
    
    pinMode(pin_cartel_detected, OUTPUT); // Declaro la salida
    pinMode(pin_contactor_up, OUTPUT); // Declaro la salida
    pinMode(pin_contactor_down, OUTPUT); // Declaro la salida
    pinMode(pin_luz_verde, OUTPUT); // Declaro la salida
    pinMode(pin_luz_naranja, OUTPUT); // Declaro la salida
    pinMode(pin_luz_roja, OUTPUT); // Declaro la salida

  } // cierro setup
  
void loop(){
  
  camionDetected();

  } //cierro loop

void camionDetected (){
  
  //estado_camion_detected = digitalRead(pin_camion_detected);  // i1 
  //estado_barrera_up = digitalRead(pin_barrera_up); // i2 
  //estado_barrera_down = digitalRead(pin_barrera_down); // i3 
  //estado_pulsador_up = digitalRead(pin_pulsador_up); // i4 
  
  digitalWrite(pin_cartel_detected, LOW); // q0 
  digitalWrite(pin_contactor_up, LOW); // q1
  digitalWrite(pin_contactor_down, HIGH); // q2
  digitalWrite(pin_luz_verde, LOW); // q3 
  digitalWrite(pin_luz_naranja, LOW); // q5
  digitalWrite(pin_luz_roja, LOW); // q5
  
  if ( estado_camion_detected == HIGH ){
    camion = true;
    Serial.println('Se ha detectado un CAMION');
    delay(miniTiempo); 
  }
  
  if (camion = true){ 
    digitalWrite(pin_cartel_detected, HIGH); // q0 
    delay(tiempo);
    digitalWrite(pin_cartel_detected, LOW); // q0 
    
    float pesoCamion = halloY(xMin, xMax, yMin, yMax, pinAnaINy);
    
    if ( pesoCamion >= 20000){ 
      digitalWrite(pin_luz_naranja, HIGH); // q5
      Serial.print('El peso del camion es: ');
      Serial.print(pesoCamion);
        
        if ( estado_camion_detected == HIGH ){
          camion = true;
          Serial.println('Se abre puerta por botón pulsado');
          delay(miniTiempo); 
          digitalWrite(pin_luz_verde, HIGH); // q3 
          puerta();
          pesoCamion = 0;
          totalContado = contador++;
          }else{
            digitalWrite(pin_luz_roja, HIGH); // q5
            Serial.println('Alerta reveldía');
            }
     
      }else { 
        digitalWrite(pin_luz_verde, HIGH); // q3 
        Serial.println('Peso correcto');
        puerta();
        pesoCamion = 0;
        totalSinPagar = sinPagarCta++;
        delay(miniTiempo);
        digitalWrite(pin_luz_verde, LOW); // q3 
        }

  }
  
  
} // cierra camionDetected


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



void puerta(){
    boolean cerrado = true;
    boolean abierto = false;
    //estado_barrera_up = digitalRead(pin_barrera_up); // i2 
    //estado_barrera_down = digitalRead(pin_barrera_down); // i3
    
    if ( (estado_barrera_down == HIGH) && (estado_barrera_up == LOW)){
      cerrado = false;
      
      if (cerrado = false){
        digitalWrite(pin_contactor_up, HIGH); // q1
        digitalWrite(pin_contactor_down, LOW); // q2
        cerrado = true;
        }
     }else if ( (estado_barrera_down == LOW) && (estado_barrera_up == HIGH)){
       delay(tiempo);
       abierto = true;
       
        if (abierto = true){
        digitalWrite(pin_contactor_up, LOW); // q1
        digitalWrite(pin_contactor_down, HIGH); // q2
        }
      }else {
        digitalWrite(pin_contactor_up, LOW); // q1
        digitalWrite(pin_contactor_down, LOW); // q2
        } 
        
} 

