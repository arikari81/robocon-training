/* using nonparametric funtions, create four fucntions forward backward right left using switch statements and it should go countinously 
until exit*/
// 10sep5

#include <iostream>
using namespace std;



class Robot{

private:
    int speed;

public:
    
    void goforward(int inp){
        speed = inp;
        cout << "\nMOVING AHEAD AT SPEED LEVEL " << inp << " \n";
    }

    void goback(int inp){
        speed = inp;
        cout << "\nMOVING BACKWARD AT SPEED LEVEL " << inp << " \n";
    }

    void goright(int inp){
        speed = inp;
        cout << "\nGOING TO THE RIGHT AT SPEED LEVEL " << inp << " \n";
    }

    void goleft(int inp){
        speed = inp;
        cout << "\nGOING TO THE LEFT AT SPEED LEVEL " << inp << " \n";
    }

    void botstop(){
        cout << "\n\tHALTING\n";
        cout << "\tHALT REACHED\n";
    }

};

void SetSpeed(int &inp){
    cout << "\n";
    cout << "Enter the desired speed: ";
    cin >> inp;
}

int main()
{
    Robot r;
    int inp = 0;

    int instruction;
    cout << "1. to move ahead, 2. to move back, 3. to go the right, 4. to go the left, 5. to stop, 6 to exit\n";

    while (true)
    {
        cout << "\nEnter your desired instruction: ";
        cin >> instruction;
        
        switch (instruction)
        {
        case 1:
            SetSpeed(inp);
            r.goforward(inp);
            break;
        case 2:
            SetSpeed(inp);
            r.goback(inp);
            break;
        case 3:
            SetSpeed(inp);
            r.goright(inp);
            break;
        case 4:
            SetSpeed(inp);
            r.goleft(inp);
            break;
        case 5:
            r.botstop();
            break;
        case 6:
            char conf;
            cout << "Are you sure you want to exit?(y to exit): ";
            cin >> conf;
            if (conf == 'y' || conf == 'Y')
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
        default: 
            cout << "ENTER A VALID COMMAND\n";
            break;
        }
    }

}