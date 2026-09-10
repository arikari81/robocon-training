/* using nonparametric funtions, create four fucntions forward backward right left using switch statements and it should go countinously 
until exit*/
// 10sep5

#include <iostream>
using namespace std;

void goforward(){
    cout << "MOVING AHEAD\n";
}

void goback(){
    cout << "MOVING BACKWARD\n";
}

void goright(){
    cout << "GOING TO THE RIGHT\n";
}

void goleft(){
    cout << "GOING TO THE LEFT\n";
}

void botstop(){
    cout << "HALTING\n";
}

class Robot{

    

};

int main()
{
    int instruction;
    cout << "1. to move ahead, 2. to move back, 3. to go the right, 4. to go the left, 5. to stop, 6 to exit\n";

    while (true)
    {
        cout << "Enter your desired instruction: ";
        cin >> instruction;

        switch (instruction)
        {
        case 1:
            goforward();
            break;
        case 2:
            goback();
            break;
        case 3:
            goright();
            break;
        case 4:
            goleft();
            break;
        case 5:
            botstop();
            break;
        case 6:
            char conf;
            cout << "Are you sure you want to exit?(y to exit): ";
            cin >> conf;
            if (conf == 'y')
            {
                cout << "\tEXITING..\n";
                cout << "\t\tPROGRAM EXITED.";
                cout << "\n";
                return 0;                
            }
            else
            {
                break;
            }
        }
    }

}