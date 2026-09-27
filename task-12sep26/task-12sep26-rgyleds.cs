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
