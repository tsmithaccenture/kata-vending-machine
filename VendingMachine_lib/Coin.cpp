class Coin {
private:
    double _diameter;

public:

    Coin(double diameter, float weight) {
        _diameter = diameter;
    }

    double getValue() {
        if (_diameter == 17.91)
            return 0.1;
        return 0.25;
    }
};
