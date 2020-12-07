
int led1=2;//redifino variables


int tiempo = 300;
const int contante1 =22; // constante global
byte num0;
short numPequeo; // 8 bit
int entero; // 16 bit -32768...o...32768
int num1 = 10;
int num2 = 9;
int num3 = 8;
int num4 =7 ;
int num5 =6;

boolean abierto = true;
boolean cerrado = false;
long numeroGrande; // 1000344
char letra ='a'; //1 byte
float decimales; // 64 bit
double decimales2; // decimales 64 a 128
double resultado1;
double resultado2;
float resultado3;
unsigned positivo;//

/* Operadores de Comparación*/
int variable1=1;
int variable2=2;
int variable3=2;
/*variable1 <= variable2
  variable1 && variable2
  variable1 || variable2*/




//int miArray[6]=1,2,3,4,5,6;


void setup() {    // esta función se invoca una sola vez   
      const int constante2 = 5; // constante para esta funcion
      Serial.begin(9600);
      resultado1 = num1 + num2; //suma
      resultado2 = num3 / num4; // dividido
      double pi = PI;
      resultado3 = pi;
      int resultado1modif = resultado1--;
      Serial.print("primer resultado");
      Serial.println(resultado1);//imprime con salto de linea
      Serial.print("primer resultado modificado");
      Serial.println(resultado1modif);//imprime con salto de linea
      Serial.print("segundo resultado");
      Serial.println(resultado2);
      Serial.print("tercer resultado");
      Serial.println(resultado3);
      //Serial.print(miArray);
      
      
      
      for (led1=2; led1 <= 5; led1++){
        pinMode(led1, OUTPUT);
        }
      
}

void funcion1(){
for (led1=2; led1 < 5; led1++){
         digitalWrite(led1,HIGH);
         delay(tiempo);
         digitalWrite(led1,LOW);
         delay(tiempo);
        }
}


void funcion2(){
for (led1=5; led1 > 2; led1--){
         digitalWrite(led1,HIGH);
         delay(tiempo);
         digitalWrite(led1,LOW);
         delay(tiempo);
        }
}

void loop() {
       funcion1();
       funcion2();
}
