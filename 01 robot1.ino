int speed = 255;
int trigPin = 4;
int echoPin = 2;
int motAF = 5;
int motBF = 6;
int motAB = 9;
int motBB = 10;
int analogPin = 1;

long distance;
long randNumber;

 void setup() { 
 pinMode(motAF, OUTPUT);
 pinMode(motBF, OUTPUT);
 pinMode(motAB, OUTPUT);
 pinMode(motBB, OUTPUT);
  
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 
 randomSeed(analogRead(0));
 } 

 void loop() {
 
 speed = analogRead(analogPin) / 4;  
   
 distance = getDistance();
 if (distance > 80)
   {
   analogWrite(motAF, speed); 
   analogWrite(motBF, speed);
   }
 else  
    {
   analogWrite(motAF, 0); 
   analogWrite(motBF, 0); 
   delay(500);
   randNumber = random(-120,120);
   analogWrite(motAB, speed/2+randNumber); 
   analogWrite(motBB, speed/2-randNumber);
   delay(1000);
   analogWrite(motAB, 0); 
   analogWrite(motBB, 0);
   delay(500);
      
   }  
 delay(100); 
 }
 
 long getEchoTiming() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin,HIGH);
  return duration;
} 
 
 long getDistance() {
  long distacne_cm = getEchoTiming()/29/2;
  return distacne_cm;
}
