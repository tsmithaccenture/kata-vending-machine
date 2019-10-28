#include "VendingMachine.h"

std::string VendingMachine::GetMessage() {
    std::string result = "INSERT COIN";
    if (!displayMessage.empty()){
        result = displayMessage;
    }
    return result;
}

double VendingMachine::InsertCoin(double diameter, double weight) {
    double value = 0.00;
    if (diameter == quarterDiameterInMillimeters && weight == quarterWeightInGrams){
        value = 0.25;
    }
    else if (diameter == dimeDiameterInMillimeters && weight == dimeWeightInGrams){
        value = 0.10;
    }
    else if (diameter == nickelDiameterInMillimeters && weight == nickelWeightInGrams){
        value = 0.05;
    }
    else if (diameter == pennyDiameterInMillimeters && weight == pennyWeightInGrams){
        AddReturnedCoins(0.01);
    }
    return AddInsertedValue(value);
}

double VendingMachine::AddInsertedValue(double value) {
    totalInsertedValue += value;
    UpdateMessage(totalInsertedValue);
    return totalInsertedValue;
}

std::string VendingMachine::UpdateMessage(double value) {
    std::ostringstream streamObject;
    streamObject << std::fixed << std::setprecision(2) << value;
    std::string formattedValue = "$" + streamObject.str();
    displayMessage = formattedValue;
    return formattedValue;
}

std::vector<double> VendingMachine::GetReturnedCoins() {
    return returnedCoins;
}

int VendingMachine::AddReturnedCoins(double value) {
    returnedCoins.push_back(value);
    return returnedCoins.size();
}

bool VendingMachine::SelectProduct(int) {
    return false;
}

int VendingMachine::GetDispensedProductId() {
    return 0;
}

double VendingMachine::GetProductPrice(int productId) {
    double result = 1.00;
    if (productId == 2){
        result = 0.50;
    }
    else if (productId == 3){
        result = 0.65;
    }
    return result;
}

bool VendingMachine::IsInsertedGreaterThanOrEqualToPrice(int productId) {
    bool result = false;
    if (totalInsertedValue == GetProductPrice(productId)){
        result = true;
    }
    return result;
}

