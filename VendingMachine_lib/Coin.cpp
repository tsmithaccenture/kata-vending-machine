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
    explicit Coin(double diameter) {
        _diameter = diameter;
    }

    double getValue() {
        double result = 0;

        if (_diameter == nickel.diameter)
            result = nickel.value;
        else if (_diameter == dime.diameter)
            result = dime.value;
        else if (_diameter == quarter.diameter)
            result = quarter.value;

        return result;
    }
};
