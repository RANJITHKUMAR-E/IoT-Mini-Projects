#define echoPin 12 //connect echo pin of ultrasonic sensor to D12 of Arduino
#define trigPin 10 //connect trigger pin of ultrasonic sensor to D10 of Arduino
long duration;  // declare variables to hold duration and distance
int distance;
int LED=2;
void setup() //setup() is used for initialization
{
 pinMode(LED,OUTPUT);
 Serial.begin(9600);  //set the baud rate of serial communication to 9600
 pinMode(trigPin,OUTPUT); //set trigPin as output pin of Arduino
 pinMode(echoPin,INPUT);  //set echoPin as output pin of Arduino
}
void loop(){
 digitalWrite(trigPin,LOW); //generate square wave at trigger pin
 delayMicroseconds(2);
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin,LOW);
 duration=pulseIn(echoPin,HIGH);//calculation of distance of obstacle
 distance=(duration*0.034/2);

if(distance<10){
   Serial.println("CAR PARKED!!");
   digitalWrite(LED,HIGH);
}
else{
  digitalWrite(LED, LOW);
}

 Serial.print("Distance : ");
 Serial.print(distance);
 Serial.println(" cm ");
 delay(1000);
}                     