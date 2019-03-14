/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
#define m1 7
#define m2 8
#define m3 11
#define m4 12
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(m1, OUTPUT);
pinMode(m2, OUTPUT);
pinMode(m3, OUTPUT);
pinMode(m4, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*3.4/2;
if(distance<=38)
{
  digitalWrite(m1,HIGH);
   digitalWrite(m2,LOW);
    digitalWrite(m3,HIGH);
     digitalWrite(m4,LOW);
  
}
else
{
    digitalWrite(m1,LOW);
   digitalWrite(m2,LOW);
    digitalWrite(m3,LOW);
     digitalWrite(m4,LOW);
  
}
Serial.print("Distance: ");
Serial.println(distance);
delayMicroseconds(1000);
}
