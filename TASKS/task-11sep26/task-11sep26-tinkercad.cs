const int pinled[4] = {5, 4, 3, 2}; 

void setup(){
  for (int i = 0; i < 4; i++){
    pinMode(pinled[i], OUTPUT);
  }
  
  Serial.begin(9600);
  Serial.println("Enter an integer in the range of 0 to 15:");
}

void loop(){
  if (Serial.available() > 0){
    int num = Serial.parseInt();
    
    if (num >= 0 && num <= 15){
      Serial.println("the number in decimal base: ");
      Serial.println(num);
      Serial.println("is written in its binary form as: ");
        
      for (int i = 0; i < 4; i++){
        int bitnum = (num >> (3 - i)) & 1;
        Serial.print(bitnum);
        
        if (bitnum == 1){
          digitalWrite(pinled[i], HIGH);
        }
        else{
          digitalWrite(pinled[i], LOW);
        }
      }
      Serial.println();
    }
    else{
      Serial.println("KINDLY ENTER THE NUMBERS WITHIN THE 4-bit  RANGE(0-15): ");
    }
    
    while (Serial.available() > 0){
      Serial.read();
    }
  }
}