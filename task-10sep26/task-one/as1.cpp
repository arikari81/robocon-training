
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
