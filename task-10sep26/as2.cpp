/*
Q2. Create a C++ class called Robot to control a robot.

The robot has the following properties:
- Speed
- Battery

Requirements:
1. Make the data members private.
2. Create the following member functions:
   - setSpeed()
   - setBattery()
   - moveForward()
   - moveBackward()
   - turnLeft()
   - turnRight()
   - displayStatus()
3. Speed should only accept values between 0 and 100.
4. Battery should only accept values between 0 and 100.
5. The robot should not move if the battery is 0%.
6. Each movement should reduce the battery by 5%.
7. Create a Robot object in main().
8. Take the speed and battery values as input from the user.
9. Execute a sequence of movement commands.
10. Display the final speed and battery level.

Example:

Input:
Speed: 80
Battery: 100

Commands:
Forward
Left
Forward
Right

Output:
Robot Speed: 80
Battery: 80%
*/

#include <iostream>
using namespace std;

class Robot {
    
private:
    int speed;
    int battery;

    bool mov(){  //for battery drain
        if (battery <= 0){
            cout << "MOVMENT FAILD! BATTERY AT 0%\n";
            return false;
        }

        battery -= 5;

        if (battery < 0){
            battery = 0; 
        }
        return true;
    }

public:

    Robot(){ // initialising speed and battery
        speed = 0;
        battery = 0;
    }
    
    void speedcheck(int sp){    
        if (sp >= 0 && sp <= 100){
            speed = sp;
        }
        else{
            cout << "Invalid speed data entered\n";
            speed = 0;
        
        }
    }

    void batt(int charge){
        if (charge >= 0 && charge <= 100)
        {
            battery = charge;
        }
        else{
            cout << "invalid battery charge value\n";
            battery = 0;
        }
    }

    void gofor(){
        if (mov()){
            cout << "ROBOT MOVED FORWARD\n";
        }
    }

    void goback(){
        if (mov()){
            cout << "ROBOT MOVING BACKWARD\n";
        }
    }

    void goleft(){
        if (mov()){
            cout << "ROBOT TURNED LEFT\n";
        }
    }

    void goright(){
        if (mov()){
            cout << "ROBOT TURNED RIGHT\n";
        }
    }

    void botstop(){
        cout << "ROBOT STOPPED\n";
    }

    void tbprin(){
        cout << "\n--- Final Robot Status ---\n";
        cout << "Robot Speed: " << speed << "\n";
        cout << "Battery: " << battery << "%\n";

    }
};

//main function

int main(){
    Robot r;
    int adspeed, adbattery;

    cout << "enter speed(1-100): ";
    cin >> adspeed;
    cout << "enter battery (0-100): ";
    cin >> adbattery;

    int aduser = 0;
    
    // declaring and giving parameters to the Robot variables here
    r.speedcheck(adspeed);
    r.batt(adbattery);

while (aduser != 6) {
        cout << "\n--- Choose Robot Operation ---\n";
        cout << "1. Move Forward\n";
        cout << "2. Move Backward\n";
        cout << "3. Turn Left\n";
        cout << "4. Turn Right\n";
        cout << "5. Stop\n";
        cout << "6. Exit & Show Status\n";
        cout << "Enter your choice (1-6): ";
        cin >> aduser; // HERE is where we take the user input for operation

        switch (aduser) {
            case 1: 
                r.gofor(); 
                break;
            case 2: 
                r.goback(); 
                break;
            case 3: 
                r.goleft(); 
                break;
            case 4: 
                r.goright(); 
                break;
            case 5: 
                r.botstop(); 
                break;
            case 6: 
                cout << "Exiting menu...\n";
                break;
            default: 
                cout << "Invalid choice! Try again.\n"; 
                break;
        }
    }

    // 3. Display final values at the very end
    r.tbprin();

    return 0;
}