short int ld = 5; //pins defined
short int trig = 11;
short int echo = 10;

//custom map function defined here
float custmap(long x,long in_min,float in_max,long out_min,long out_max){
  float resmap = out_min + (x - in_min) * float((out_max - out_min) / (in_max - in_min));
  return resmap;
}

void setup(){
  pinMode(ld, OUTPUT); / /defining input/output for different pins
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop(){
  
  digitalWrite(trig, LOW); //working of the trig pin
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW); 
  
  int time = pulseIn(echo, HIGH); //echo pins input 
  int dist = time*(0.0343/2.0);  //distanc calculation
  if (dist <= 200 && dist >= 20){  //to make sure the dist range is correct
    int ldlevel = custmap(dist, 20, 200, 0, 255); / /custom man function is used
    analogWrite(ld, ldlevel); //led as bright as mapped brightness level
    Serial.println(ldlevel);
    delay(50);
    
  }
  else{     //when the distance is out of 20-200 range
    Serial.println("OUT OF RANGE!");
  }
}
