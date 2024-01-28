#include <iostream>

class Battery {

private:
    int num;

public:
    void set(int charge)
    {
        num = charge;
    }
    int get()
    {
        return num;
    }
};


class Mobile {

public:
    Battery battery1;
    
    void show()
    {
        std::cout<< "Battery is "<< battery1.get() <<"% charged"<< std::endl;
    }
};


int main()
{
    // create object of class Mobile
    Mobile nokia;
    nokia.battery1.set(100);
    nokia.show();
}