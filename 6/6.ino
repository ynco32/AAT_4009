#include <Servo.h>

/*
 * Concept: Remote control Fishing Lod with arduino
 * 
 * used: 3 sensors(Water level, PIR, Ultrasonic), 1 servo motor, 1 active buzzer 
 * 
 * roles
 *  - Servo motor: fising lod's wheel
 *  - PIR: remocon for the lod
 *  - Ultrasonic sensor: detect fish's location
 *  - water level: detecht the niddle's location
 *  - active buzzer: detect whether the user get the fish or not
 *  
 *  :users control fishing lod with PIR sensor
 *  if fish is there and the niddle get to the water deep enough, 
 *  the active buzzer would let you know you are successfull!
 */




int ledPin1 = 12; //LED to check PIR input
int ledPin2 = 2; //LED to check water sensor

int pir = 7; // PIR sensor(인체감지센서)
int waterPin = A5; //water sensor (수위센서)
int servo = 10; //servo motor 
int trigPin = 2; //Ultrasonic sensor (초음파센서) _trigger
int echoPin = 4; //Ultrasonic sensor (초음파센서) _trigger
int activeB = 13; //active buzzer (능동부저)

int angle = 0; //angle of servo motor = angle for fising lod
int val = 0; //water level
//long distance; //distance by ultrasonic
//int water;

Servo myservo;

void setup(){  
  myservo.attach(servo);
  myservo.write(0);

  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pir, INPUT);
  pinMode(activeB, OUTPUT);
  
}

void loop(){
  val = digitalRead(pir);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long timeDistance = pulseIn(echoPin, HIGH);
  long distance = (timeDistance/2) / 29.1;

  Serial.print(distance);
  Serial.println("cm");

  if(val == 1){
    Serial.println("Act");
    
    digitalWrite(ledPin1, HIGH);

    angle = 90;
    myservo.write(angle);
  Serial.print(angle);
  } 

  
  else {
    Serial.println("not Act");
    Serial.print("!");
    digitalWrite(ledPin1, LOW);
    
    angle = 0;
    myservo.write(angle);
  }

  int water = analogRead(waterPin);
  Serial.print("water: ");
  Serial.println(water);
 
 


  
//    delay(1000);

    

  
  if (water > 500){
    digitalWrite(ledPin2, HIGH);
    if (distance < 10){
      digitalWrite(activeB, HIGH);
      delay(1000);
      digitalWrite(activeB,LOW);
    }
    else {
      digitalWrite(activeB,LOW);
    }
  }
  else {
    digitalWrite(ledPin2, LOW);
  }
  
}
