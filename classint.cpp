/*intro to classes*/

class Robot{   // encapsulation
    
private:  // creates a variable which cant be used outside the class
    int battery;

public:

    void setBattery(int value){

        if (value >= 0 && value <= 100)
        {
            battery = value;
        }
    }

    int getBattery(){
        return battery;
    }
// this is where the cope of the variable battery ends.
};

//now outside the class, battery cant be used.

int main(){
    Robot r; // memory location robot

    r.setBattery(80);

    cout << "Battery = "
        << r.getBattery() << "%\n";

    return 0;
}