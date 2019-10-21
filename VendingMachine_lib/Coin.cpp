#include <Quarter.cpp>
#include <Dime.cpp>
#include <Nickel.cpp>

class Coin {
private:
    double _diameter;
    Quarter quarter;
    Dime dime;
    Nickel nickel;

public:
    Coin(double diameter) {
        _diameter = diameter;
    }

    double getValue() {
        double result = quarter.value;

        if (_diameter == dime.diameter)
            result = dime.value;
        else if (_diameter == nickel.diameter)
            result = nickel.value;

        return result;
    }
};
