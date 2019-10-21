
class CoinRegister{
private:
    double _totalAmount;

public:
    void Add(double value) {
        _totalAmount += value;
    }

    double GetTotalAmount(){
        return _totalAmount;
    }
};
