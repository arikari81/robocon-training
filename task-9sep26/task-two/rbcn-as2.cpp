
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
