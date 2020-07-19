//What's Wrong with this code , Identify Smells and Refactor

#include <iostream>
using namespace std;

class FuelPump {

public:
    void pump() {
        //sample Code
        cout << "Fule Pumped";
    }
};

class Ignition {

public:
    void powerUp() {
        cout << "Ignition Turned On";
    }
};

class Starter {
public:
    void revolve() {
        cout << "Engine revolved";
    }
};

class Engine {
public:
    // ...

    FuelPump getFuelPump() {

        return fuelPump;
    }

    Ignition getIgnition() {

        return ignition;
    }

    Starter getStarter() {

        return starter;
    }

    // ...
private:
    FuelPump fuelPump;
    Ignition ignition;
    Starter starter;
};

class Car {




public:
    Engine getEngine() {
        return engine;
    }
private:
    Engine engine;
};

class Driver {
public:
    // ...
    void drive(Car car) const {
        Engine engine = car.getEngine();
        FuelPump fuelPump = engine.getFuelPump();
        fuelPump.pump();
        Ignition ignition = engine.getIgnition();
        ignition.powerUp();
        Starter starter = engine.getStarter();
        starter.revolve();
    }
    // ...
};


int main()
{
    
    Car car;
    Driver driver;
    driver.drive(car);
    return 0;
}

