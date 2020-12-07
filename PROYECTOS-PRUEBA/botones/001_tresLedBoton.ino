/* EN ESTE SENCILLO PROGRAMA PRENDO TRES LED
CONSECUTIVAMENTE HASTA QUE PRENDO LAS TRES Y RESETEO.
Se usa un botón y tres led. 
*/

int sCuenta = 0;
int sMaximo = 3;
int pinSestado = 0;
int tiempo = 3000;

const int pinS = 8; //i3
int pinBOMBILLA1 = 2; // q0
int pinBOMBILLA2 = 3; // q0
int pinBOMBILLA3 = 4; // q0


void setup(){
  
  pinMode(pinS, INPUT);// Declaro la entrada.
  pinMode(pinBOMBILLA1, OUTPUT); // Declaro la salida
  pinMode(pinBOMBILLA2, OUTPUT); // Declaro la salida
  pinMode(pinBOMBILLA3, OUTPUT); // Declaro la salida
   
  }
  

void loop(){
  Serial.begin(9600);
  pinSestado = digitalRead(pinS);
  if(pinSestado == HIGH){
    
    	for(sCuenta; sCuenta <= sMaximo; sCuenta++){
          //Serial.println(sCuenta);
          if(sCuenta==1){
            digitalWrite(pinBOMBILLA1, HIGH);
            digitalWrite(pinBOMBILLA2, LOW);
            digitalWrite(pinBOMBILLA3, LOW);
            Serial.println(sCuenta);
            delay(tiempo);
            Serial.println("hola");
            
            //while (Serial.available() <=0){}; // este codigo le da un descanso. No funciona en simulación, sí en arduino.
          }else if(sCuenta==2){
            digitalWrite(pinBOMBILLA2, HIGH);
            digitalWrite(pinBOMBILLA1, LOW);
            digitalWrite(pinBOMBILLA3, LOW);
            Serial.println(sCuenta);
            
            //while (Serial.available() <=0){}; // este codigo le da un descanso. No funciona en simulación, sí en arduino.
            delay(tiempo);
            //sCuenta = sCuenta++;
          }else if(sCuenta==3){
            digitalWrite(pinBOMBILLA1, HIGH);
            digitalWrite(pinBOMBILLA2, HIGH);
            digitalWrite(pinBOMBILLA3, HIGH);
            Serial.println(sCuenta);
            //while (Serial.available() <=0){}; // este codigo le da un descanso. No funciona en simulación, sí en arduino.
            delay(tiempo);
            sCuenta =0;
          }
        }
    
    
  }else{
    digitalWrite(pinBOMBILLA1, LOW);
    digitalWrite(pinBOMBILLA2, LOW);
    digitalWrite(pinBOMBILLA3, LOW);
    delay(tiempo);
  }
}
    
    
  }else{
    digitalWrite(pinBOMBILLA1, LOW);
    digitalWrite(pinBOMBILLA2, LOW);
    digitalWrite(pinBOMBILLA3, LOW);
    delay(tiempo);
  }
}