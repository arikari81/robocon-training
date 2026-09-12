/*problem statement:
• When both switches are ON:
  - Green LED should be ON.
  - Yellow LED should be OFF.
  - Red LED should be OFF.
  - The robot is moving forward.

• When the first switch is OFF and the second switch is ON:
  - Green LED should be OFF.
  - Yellow LED should be OFF.
  - Red LED should be ON.
  - The robot is moving backward.

• When the second switch is OFF, regardless of the state of the first switch:
  - Green LED should be OFF.
  - Yellow LED should be ON.
  - Red LED should be OFF.
  - The robot is stopped.
*/ 

short int sdsw1 = 2;
short int sdsw2 = 3;
short int grn1 = 13; 
short int yel1 = 12;
short int red1 = 11;

void setup(){
  pinMode(sdsw1, INPUT);
  pinMode(sdsw2, INPUT);
  
  pinMode(grn1, OUTPUT);
  pinMode(yel1, OUTPUT);
  pinMode(red1, OUTPUT);
}

void loop() {
  int sw1 = digitalRead(sdsw1);
  int sw2 = digitalRead(sdsw2);

  if (sw2 == LOW) {                  //condition 3
    digitalWrite(grn1, LOW);
    digitalWrite(yel1, HIGH);
    digitalWrite(red1, LOW);
  }
  else {
    if (sw1 == HIGH) {               //Condition 1
      digitalWrite(grn1, HIGH);
      digitalWrite(yel1, LOW);
      digitalWrite(red1, LOW);
    } 
    else {                           //condition 2
      digitalWrite(grn1, LOW);
      digitalWrite(yel1, LOW);
      digitalWrite(red1, HIGH);
    }
  }
}