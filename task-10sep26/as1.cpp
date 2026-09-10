/*
Q1. Write a C++ program for an autonomous line-following robot with 8 IR sensors arranged from left to right.

Each sensor gives:
0 → White surface
1 → Black line

Example sensor input:
0 0 1 1 1 0 0 0

Requirements:
1. Store the 8 sensor readings in an array.
2. Take all 8 sensor readings as input from the user.
3. Calculate the position of the detected line using the sensor indices.
4. If the line is detected more toward the left, print "Turn Left".
5. If the line is detected more toward the right, print "Turn Right".
6. If the line is centered, print "Move Forward".
7. If no sensor detects the line, print "Line Lost".
8. Create separate functions for:
   - Reading the sensor values
   - Calculating the line position
   - Deciding the robot's movement
9. Do not use a separate if-else condition for every possible sensor combination.

Example:

Input:
0 0 1 1 1 0 0 0

Output:
Line Position: Center
Action: Move Forward
*/

#include <iostream>
using namespace std;

//functions:
void sensread(int sens[]){ //taking the readings
    cout << "Enter 8 binary sensor readings, where 1 is for black space and 0 for white: \n";
    for (int i = 0; i < 8; i++)
    {
        cin >> sens[i];
    }
}

int position(int sens[]){ //checkng position
    float index = 0;
    int linecount = 0;

    for (int i = 0; i < 8; i++)
    {
        if (sens[i] == 1){
            index += i;
            linecount++;
        }
    }

    if (linecount == 0){
        return 4;
    }

    float avgpos = index / linecount;
    if (avgpos >= 3.0 && avgpos <= 4.0){
        return 3;
    }
    else if (avgpos < 3.0){
        return 1;
    }
    else {
        return 2;
    }
}

void botmove(int move)
{
    switch (move)
    {
        case 1:
            cout << "Line position: Right\n";
            cout << "Action: Turn left\n";
            break;
        case 2:
            cout << "Line position: Left\n";
            cout << "Action: Turn right\n";
            break;
        case 3:
            cout << "Line position: Centre\n";
            cout << "Action: Move forward\n";
            break;
        case 4:
            cout << "\t!!LINE LOST!!\n";
            break;
        default:
            cout << "Kindly a valid input.\n";
            break;
    }
}

int main()
{
    int sens[8];

    sensread(sens);

    int move = position(sens);

    botmove(move);

    return 0;
}