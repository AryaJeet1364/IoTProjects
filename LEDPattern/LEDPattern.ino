int pot = A5;
int value = 0;
int redled1 = 8;
int redled2 = 9;
int yellowled1 = 10;
int yellowled2 = 11;
int greenled1 = 12;
int greenled2 = 13;

void setup(){
  Serial.begin(9600);
  pinMode(greenled2, OUTPUT);
  pinMode(greenled1, OUTPUT);
  pinMode(yellowled2, OUTPUT);
  pinMode(yellowled1, OUTPUT);
  pinMode(redled2, OUTPUT);
  pinMode(redled1, OUTPUT);
  pinMode(pot, INPUT);
}

void loop(){
  value = analogRead(pot);
  Serial.println(value);
  delay(400);
  
  if(value == 0){
    digitalWrite(greenled2, LOW);
    digitalWrite(greenled1, LOW);
  }
  else if(value > 0 && value <= 250){
    digitalWrite(greenled2, HIGH);
    digitalWrite(greenled1, HIGH);
    digitalWrite(yellowled2, LOW);
    digitalWrite(yellowled1, LOW);
  }
  else if(value >= 251 && value <= 500){
    digitalWrite(yellowled2, HIGH);
    digitalWrite(yellowled1, HIGH);
    digitalWrite(redled2, LOW);
    digitalWrite(redled1, LOW);
  }
  else if(value >= 501){
    digitalWrite(redled2, HIGH);
    digitalWrite(redled1, HIGH);
  }
}
