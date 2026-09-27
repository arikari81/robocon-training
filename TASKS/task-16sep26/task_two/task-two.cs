short int red1 = 6; // defning pins
short int grn2 = 5;
int pot = A0;

void setup(){
  pinMode(red1, OUTPUT); //basic setup
  pinMode(grn2, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop(){
  
  int potval = analogRead(pot); //reading potentiometer value
  int bright = (255.0/1023.0)*potval; //level of brightness
  int antibright = 255 - bright; 
  analogWrite(red1, bright); //led1 increases with the pot
  delay(20);
  analogWrite(grn2, antibright); //led2 will be as dim as pot is high
  delay(20);
  
  //printing output status
  Serial.println("");
  Serial.print("brighntess level for red(led 1): ");
  Serial.println(bright);
  Serial.print("brighntess level for green(led2): ");
  Serial.println(antibright);
  delay(20);
  
}
