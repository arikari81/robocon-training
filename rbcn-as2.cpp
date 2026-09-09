/*
Assignment 2 — Digit Frequency

Write a C++ program that takes a number and finds how many times each digit (0–9) appears.

Requirements:

Use an array of size 10 to store the digit counts.
Extract each digit and update its count.
Use a loop to check all digits.
Use if to print only the digits that appear.
Don't print digits with a count of 0.
Handle the input 0 separately.
*/

#include <iostream>
using namespace std;

int main()
{
    //initial definitions
    int num;
    int digcount[10] = {0}; 

    cout << "Enter an integer: ";
    cin >> num;

    //for handling 0 
    if (num == 0)
    {
        digcount[0] = 1;
    }
    else
    {
        if (num < 0)
        {
            num =  -num; // converting negatives to positive to make it easier
        }

        while (num > 0)
        {
            int dig = num % 10; 
            digcount[dig]++;
            num /= 10;
        }
    }

    cout << "\nDIGIT FREQUENCY RESULTS\n";

    for (int p = 0; p < 10; p++)
    {
        if (digcount[p] > 0)
        {
            cout << "DIGIT " << p << " APPEARS " << digcount[p] << " TIMES.\n";
        }
    }

    return 0;
}
