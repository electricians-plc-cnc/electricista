const int sensorInductivo = 7;
const int led1 = 6; 
const int led2 = 5; 
const int led3 = 4; 

void setup()
{
   Serial.begin(9600);
   pinMode(sensorInductivo, INPUT);
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
}
 
void loop()
{
   bool sensor = digitalRead(sensorInductivo);
   
   if (sensor == HIGH)
   {
     digitalWrite(led1,HIGH);
     digitalWrite(led2,HIGH);
     digitalWrite(led3,LOW);
  
   }if (sensor == LOW)
   {
     digitalWrite(led1,LOW);
     digitalWrite(led2,LOW);
     digitalWrite(led3,HIGH);
  
   }
   delay(1000);
}