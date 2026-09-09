/*
Assignment 1 — Sensor Data Analysis

A robot takes 10 distance readings using an ultrasonic sensor. Write a C++ program to analyze the readings.

Requirements:

Take 10 readings and store them in an array.
Find the maximum and minimum readings using if.
Calculate the average.
Count readings below 20 cm and above 100 cm.
Use loops to process the array.
Do not use built-in functions for maximum/minimum.
*/

#include <iostream>
using namespace std;

int main()
{
    //defining the readings' array
    int n = 10;
    int readata[n];

    //taking readings using a loop
    cout << "enter " << n << " ultrasonic senor readings in cm: \n";

    //loop
    for (int p = 0; p < 10; p++)
    {
        cout << "Reading number " << (p+1) << ": \n";
        cin >> readata[p];
    }

    //defining other output variables
    float maxread = readata[0];
    float minread = readata[0];
    int under20 = 0;
    int over100 = 0;
    float sum = 0;
    //array processing

    for (int k = 0; k < n; k++)
    {
        float pres = readata[k];  //using pres as to keep track of the current variable being read.

        if (pres > maxread)
        {
            maxread = pres;
        }
        
        if (pres < minread)
        {
            minread = pres;
        }

        sum += pres;

        if (pres > 100.0)
        {
            over100++;
        }

        if (pres < 20)
        {
            under20++;
        }
    }

    float avg = sum/n;

    //printng final results

    cout << "\n\t|------------SENSOR DATA ANALYSIS RESULTS------------|\n";
    cout << "\tMAXIMUM READING: " << maxread << " cm\n";
    cout << "\tMINIMUM READING: " << minread << " cm\n";
    cout << "\tAVERAGE READING: " << avg << " cm\n";
    cout << "\tNUMBER OF READINGS BELOW 20 CM: " << under20 << " \n";
    cout << "\tNUMBER OF READINGS ABOVE 100 CM: " << over100 << " \n";

    return 0;
}