#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the number of elements youd like to keep in your array: ";
    cin >> n;
    int rmp[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the number you'd like to add" << i + 1 <<"\n";
        cin >> rmp[i];
    }

    cout << "your array is now: \n";
    for (int i = 0; i < n; i++)
    {
        cout << rmp[i] << " ";
    }
    cout << "\n";
    
    return 0;
}