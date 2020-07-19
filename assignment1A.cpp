#include <iostream>
using namespace std;

class FuelPump{

public:
void pump(){
    //sample Code
    cout<< "Fule Pumped";
}
bool isRunning() {
    return true;
}
int getFuelPressure() {
    return  fuelPressure;
}

void setFuelPressure(int newFuelPressure) {

    this->fuelPressure = fuelPressure;
}

private :
    int fuelPressure;
};

class Ignition{

public:
void powerUp(){
cout<<"Ignition Turned On";
}
bool isPoweredUp() {
    return true;
}
};

class Starter{
public:
void revolve(){
cout<<"Engine revolved";
}
bool isRotating() {
    return true;
}
};

class Engine {
public:
// ...

    void start() {
        if (!fuelPump.isRunning()) {
            fuelPump.pump();
            if (fuelPump.getFuelPressure() < NORMAL_FUEL_PRESSURE) {
                fuelPump.setFuelPressure(NORMAL_FUEL_PRESSURE);
            }
        }
        if (!ignition.isPoweredUp()) {
            ignition.powerUp();
        }
        if (!starter.isRotating()) {
            starter.revolve();
        }
       
    }

// ...
private:
FuelPump fuelPump;
Ignition ignition;
Starter starter;
static const  int NORMAL_FUEL_PRESSURE{ 120 };
};

class Car{

    public:
        void start() {
            engine.start();
        }
    private:
    Engine engine;
};

class Driver {
public:
// ...
void drive(Car car) const {
    car.start();
}
// ...
};


int main()
{
    Car car;
    Driver driver;
    driver.drive(car);
}
