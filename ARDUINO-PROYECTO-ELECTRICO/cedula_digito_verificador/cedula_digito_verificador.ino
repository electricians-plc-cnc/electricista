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

//ARGENTINA
int dni[10] = {1,2,3,4,5,6,7,8,1,1};
int algoritmoDni[10] = {5,4,3,2,7,6,5,4,3,2};
int valoresDni[10];
int resultadoDni;
int sumaDni;
int datoDni;


void setup() { 
  Serial.begin(9600); // Abre puerto serie con la velocidad de 9600 baudios (bit por segundo) 

  Argentina();
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

void Argentina(){

    for(int i=0; i<10; i++){
      resultadoDni= dni[i]*algoritmoDni[i];
      valoresDni[i]=resultadoDni;
      Serial.println(dni[i]);

    }
    for(int x=0; x<7; x++){
      sumaDni=sumaDni+valoresDni[x];
    }
    
    int sumaDniResult = sumaDni/11;
    datoDni = 10-(sumaDniResult%10);
    int valorOnce = 10-datoDni;
    
    if(valorOnce==10){
    datoDni = 9;
    }if(valorOnce==11){
    datoDni = 0;
    }
    Serial.println(datoDni);
    
    
}


