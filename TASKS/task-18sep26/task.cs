//using an L293D motor driver to control a motor
//for which, the input is to be taken using a potentiometer

int in2 = 9;
int in1 = 6;
int pot = A0;
void setup()
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}
void loop()
{
  int potval = analogRead (pot);
  int motval = map(potval, 0, 1023, 0, 255);
  int speedlevel = map(motval, 0, 255, 0, 100);
  analogWrite(in2, motval);
  digitalWrite(in1, LOW);
  Serial.print("The current speed level is: ");
  Serial.println(speedlevel);
  if (speedlevel == 100){
    Serial.println("max speed");
  }
  else if (speedlevel == 0){
    Serial.println("motor halted");
  }
  delay(20);
