
int firstPin = 13;
int secPin = 12;
int thridPin = 8;
int fourthPin = 2;



void setup(){
  pinMode(firstPin, OUTPUT);
  pinMode(secPin, OUTPUT);
  pinMode(thridPin, OUTPUT);
  pinMode(fourthPin, OUTPUT);
  Serial.begin(9600);
}


void loop(){
  if (Serial.available()){ 
    char message = Serial.read();
    Serial.write(message);

    if (message == '0'){
      digitalWrite(firstPin, HIGH);
      digitalWrite(secPin, LOW);
      digitalWrite(thridPin, LOW);
      digitalWrite(fourthPin, LOW);
    }

    else if (message == '1'){
      digitalWrite(firstPin, LOW);
      digitalWrite(secPin, HIGH);
      digitalWrite(thridPin, LOW);
      digitalWrite(fourthPin, LOW);
    }

    else if (message == '2'){
      digitalWrite(firstPin, LOW);
      digitalWrite(secPin, LOW);
      digitalWrite(thridPin, HIGH);
      digitalWrite(fourthPin, LOW);
    }

    else if (message == '3'){
      digitalWrite(firstPin, LOW);
      digitalWrite(secPin, LOW);
      digitalWrite(thridPin, LOW);
      digitalWrite(fourthPin, HIGH);
    }

    
    
  }
}
