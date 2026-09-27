const int trig = 2;
const int echo = 3;
const int pot1 = A0;

const int green = 9;
const int yellow = 10;
const int red = 11;

//custom map function
long customMap(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

//function to print the status
void printStatus(int curr, int warn, String warntext) {
  Serial.print("Measured Distance: ");
  Serial.print(curr);
  Serial.print(" cm | Warning Limit: ");
  Serial.print(warn);
  Serial.print(" cm | Status: ");
  Serial.println(warntext);
}

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {

  int potval = analogRead(pot1);
  int warndist = customMap(potval, 0, 1023, 10, 50);
  int halfwarndist = warndist / 2;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  long duration = pulseIn(echo, HIGH);
 
  int currdist = duration * 0.0343 / 2; //current distnace 

  if (currdist > warndist) {
    //Safe Distance
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    
    printStatus(currdist, warndist, "Safe Distance");
  } 
  else if (currdist <= warndist && currdist > halfwarndist) {
    //Closer
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    
    printStatus(currdist, warndist, "Getting Close");
  } 
  else {
    //Dangerously Close
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    
    printStatus(currdist, warndist, "Dangerously Close");
  }

  delay(200);
}
