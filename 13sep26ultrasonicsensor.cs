// WAP in c# to use an arduino and an ultrasonic sensor, if the distance is under 10 cm the red light should be HIGH otherwise the green one.
// they shouldnt be HIGH together.

const int trig = 10;
const int echo = 9;
long duration;
int distance;
short int red = 6;
short int green = 5;


void setup(){
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); // 10 microsends
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH);
  distance = duration*0.034/2.0;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance < 10){
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
  }
  else{
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
  }
  
  delay(500);
  
}