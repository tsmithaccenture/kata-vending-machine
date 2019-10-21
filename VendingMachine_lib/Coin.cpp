#include <Quarter.cpp>
#include <Dime.cpp>
#include <Nickel.cpp>

class Coin {
private:
    double _diameter;
    double _weight;
    Quarter quarter;
    Dime dime;
    Nickel nickel;

public:
    explicit Coin(double diameter, double weight) {
        _diameter = diameter;
        _weight = weight;
    }

    double getValue() {
        double result = 0;

        if (_diameter == nickel.diameter)
            result = nickel.value;
        else if (_diameter == dime.diameter && _weight == dime.weight)
            result = dime.value;
        else if (_diameter == quarter.diameter && _weight == quarter.weight)
            result = quarter.value;

        return result;
    }
};
