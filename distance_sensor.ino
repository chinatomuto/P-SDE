int trigPin = 11;    // Trigger
int echoPin = 10;    // Echo
long duration, cm, inches;
int led1pin = 4;
int led2pin = 7;
int led3pin = 8;
//int buzzer = 9;

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1pin, OUTPUT);
  pinMode(led2pin, OUTPUT);
  pinMode(led3pin, OUTPUT);
  //pinMode(buzzer, OUTPUT);
}
  
void loop (){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = (duration / 2) / 29.1;
  inches = (duration / 2) / 74;

  if (inches >= 6) {
    digitalWrite(led1pin, HIGH);
    digitalWrite(led2pin, LOW);
    digitalWrite(led3pin, LOW);

    //tone(buzzer, 1000); // Send 1KHz sound signal...
    //delay(1000);        // ...for 1 sec
    //noTone(buzzer);     // Stop sound...
    //delay(1000);

  }else if (inches <= 5 || inches >=3) {
    digitalWrite(led2pin, HIGH);
    digitalWrite(led1pin, LOW);
    digitalWrite(led3pin, LOW);
  }else if (inches <= 2) {
    digitalWrite(led3pin, HIGH);
    digitalWrite(led1pin, LOW);
    digitalWrite(led2pin, LOW);
  }else {
    digitalWrite(led1pin, LOW);
    digitalWrite(led2pin, LOW);
    digitalWrite(led3pin, LOW);
  }


  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(250);
}