//task one

const int pot1 = A0;
const int green = 9;
const int yellow = 10;
const int red = 11;   

//custom map function 
long custommap(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int potval = analogRead(pot1);
  int brightness = 0;

  if (potval >= 0 && potval <= 340) {
    //condition 1
    brightness = custommap(potval, 0, 340, 0, 255);
    analogWrite(green, brightness);
    analogWrite(yellow, 0);
    analogWrite(red, 0);
    
    Serial.print("Value: ");
    Serial.print(potval);
    Serial.print("State: Green is on and Brightness: ");
    Serial.println(brightness);
  } 
  else if (potval >= 341 && potval <= 680) {
    //condition 2
    brightness = custommap(potval, 341, 680, 0, 255);
    analogWrite(green, 0);
    analogWrite(yellow, brightness);
    analogWrite(red, 0);
    
    Serial.print("Value: ");
    Serial.print(potval);
    Serial.print("State: yellow is on and Brightness: ");
    Serial.println(brightness);
  } 
  else if (potval >= 681 && potval <= 1023) {
    //condition 3
    brightness = custommap(potval, 681, 1023, 0, 255);
    analogWrite(green, 0);
    analogWrite(yellow, 0);
    analogWrite(red, brightness);
    
    Serial.print("Value: ");
    Serial.print(potval);
    Serial.print("State: red is on and Brightness: ");
    Serial.println(brightness);
  }
  
  delay(50);
}
