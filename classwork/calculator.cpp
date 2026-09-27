#include <iostream>
using namespace std;
int main()
{
    int num1;
    int num2;

    cout << "enter the numbers you would like to:\n";
    
    cin >> num1;
    cin >> num2;
    int oper;

    cout << "Choose the operation that you'd like to do: \n";
    cout << "+, -, /, %, * \n";
    cout << "1. for addition, 2 for difference\n";
    cout << "3. for division, 4. for modulus\n";
    cout << "5. for  multiplication\n";

    cin >> oper;
    int res;

    switch(oper)
    {
    case 1:
        res = num1 + num2;
        break;
    case 2:
        if (num1 > num2)
        {
            res = num1 - num2;
        }
        else
        {
            res = num2 - num1;
        }
        break;
    case 3:
        res = num1 / num2;
        break;
    case 4:
        res = num1 % num2;
        break;
    case 5:
        res = num1 * num2;
        break;
    }
    
    cout << "The result is " << res << "\n";
    return 0;
}