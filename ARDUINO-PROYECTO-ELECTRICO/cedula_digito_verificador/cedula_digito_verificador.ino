/* Autor: María Eugenia Szwedowski - ME Diseño Web - Peak Power Eléctricistas.
DETERMINAR DÍGITO VERIFICADOR. 
Montevideo, Uruguay.
Fecha: 20/12/2020
*/


//URUGUAY
int ci[7] = {7,6,5,4,3,2,1};
int algoritmo[7] = {2,9,8,7,6,3,4};
int valores[7];
int resultado;
int suma;
int dato;


void setup() { 
  Serial.begin(9600); // Abre puerto serie con la velocidad de 9600 baudios (bit por segundo) 

  Uruguay();
}


void loop() {
}


void Uruguay(){

    for(int i=0; i<7; i++){
      resultado= ci[i]*algoritmo[i];
      valores[i]=resultado;
      Serial.println(ci[i]);

    }
    for(int x=0; x<7; x++){
      suma=suma+valores[x];
    }
    
    if(dato<10){
    dato = 10-(suma%10);
    }if(dato==10){
    dato = 0;
    }
    Serial.println(dato);
    
    
}


