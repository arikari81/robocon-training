/*
Task: Decimal to Binary Conversion Using LEDs in Tinkercad

Using Arduino in Tinkercad, design and implement a circuit that converts a decimal number entered through the Serial Monitor into its corresponding 4-bit binary representation.

What is 4-bit Binary?

A binary number uses only two digits: 0 and 1.

In a 4-bit binary number, there are 4 positions. Each position represents a power of 2:

8 4 2 1
↓ ↓ ↓ ↓
2³ 2² 2¹ 2⁰

For example:

10 = 8 + 2

Therefore:

10 = 1010

Here, the leftmost bit represents 8 and the rightmost bit represents 1.

MSB and LSB

MSB means Most Significant Bit. It is the leftmost bit of a binary number and has the highest value.
LSB means Least Significant Bit. It is the rightmost bit and has the lowest value.
For example, in:
1010
The positions are:
1 0 1 0
↑ ↑
MSB LSB

For this task, LED 1 should represent the MSB and LED 4 should represent the LSB.

So for 10 (1010):

LED 1 → ON → 1
LED 2 → OFF → 0
LED 3 → ON → 1
LED 4 → OFF → 0

Requirements

1. Create the circuit in Tinkercad Circuits using:
Arduino Uno
4 LEDs
4 appropriate resistors
Breadboard and jumper wires
2. Use the Serial Monitor to take a decimal number as input from the user.

3. Accept decimal numbers from 0 to 15.

4. Convert the entered decimal number into its 4-bit binary representation using your Arduino program.

5. Do not use a ready-made decimal-to-binary conversion function. Perform the binary conversion yourself in the program.

6. Display the binary representation using the four LEDs:
LED ON → 1
LED OFF → 0
7. The LEDs must represent the bits from MSB to LSB.

Example

If the user enters:
10

The Arduino should convert it to:
1010

The LEDs should be:
LED 1 LED 2 LED 3 LED 4
ON OFF ON OFF
Make sure the circuit works correctly for different inputs from 0 to 15.
*/

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
