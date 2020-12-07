
const double minK = 273.15;
const double minF = 32;
const double minC = 0;


double celsius; // i1
double kelvin; // i2
double farhenheit; //i3




void setup(){
    Serial.begin(9600);
    
    Serial.println("Ingrese Celsius:");
    while (Serial.available() <=0){}; 
    celsius = Serial.parseInt();
    Serial.println(celsius);
    Serial.println();
    
    Serial.println("Ingrese Kelvin:");
    while (Serial.available() <=0){}; 
    kelvin = Serial.parseInt();
    Serial.println(kelvin);
    Serial.println();
    
    Serial.println("Ingrese Farhenheit:");
    while (Serial.available() <=0){}; 
    farhenheit = Serial.parseInt();
    Serial.println(farhenheit);
    Serial.println();
    
    Serial.println("CELSIUS A FARHEINHEIT, desde valor: ");
    Serial.print(celsius);
    Serial.println("");
    Serial.println(celsiusAfahrenheit(celsius));
    Serial.println("CELSIUS A KELVIN, desde valor celsius ");
    Serial.print(celsius);
    Serial.println("");
    Serial.println(celsiusAkelvin(celsius));
    Serial.println("");
    Serial.println("");
    
    Serial.println("KELVIN A FARHEINHEIT, desde valor kelvin ");
    Serial.print(kelvin);
    Serial.println("");
    Serial.println(kelvinAfarhenheit(kelvin));
    Serial.println("KELVIN A CELSIUS, desde valor kelvin  ");
    Serial.print(kelvin);
    Serial.println("");
    Serial.println(kelvinAcelsius(kelvin));
    Serial.println("");
    Serial.println("");
    
    Serial.println("FARHEINHEIT A KELVIN, desde valor farheinheit ");
    Serial.print(farhenheit);
    Serial.println("");
    Serial.println(farhenheitAkelvin(farhenheit));
    Serial.println("FARHEINHEIT A CELSIUS, desde valor parheinheit ");
    Serial.print(farhenheit);
    Serial.println("");
    Serial.println(farhenheitACelsius(farhenheit));
    Serial.println("");
    Serial.println("");
    
    
   
  } 
  
double celsiusAfahrenheit(double entrada){
  
  double resultC = (entrada * 1.8) + minF;
  return resultC;
  } 
  
double celsiusAkelvin(double entrada){
  
  double resultC = (entrada + minK);
  return resultC;
  } 

double kelvinAfarhenheit(double entrada){
 
  double resultC = ( (entrada - minK) * (9/5) + minF);
  return resultC;
  } 
  
double kelvinAcelsius(double entrada){
 
  double resultC = (entrada - minK);
  return resultC;
  } 
  
double farhenheitACelsius(double entrada){
 
  double resultC = ( (entrada - minF) / 1.8 );
  return resultC;
  } 
  
double farhenheitAkelvin(double entrada){
 
  double resultC = ( (entrada - minF) * (5/9) + minK);
  return resultC;
  } 
    
void loop(){} 


