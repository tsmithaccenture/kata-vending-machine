#include "VendingMachine.h"
#include <iomanip>
#include <sstream>
#include <vector>

std::string VendingMachine::GetMessage() {
    std::stringstream stream;
    string message = "INSERT COIN";
    if (totalValueInCents > 0){
        stream << std::fixed << std::setprecision(2) << totalValueInCents / 100.00;
        message = stream.str();
    }
    return message;
}

void VendingMachine::InsertCoin(double diameter) {
    if (diameter == dimeDiameter){
        totalValueInCents += dimeValueInCents;
    }
    else if(diameter == nickelDiameter){
        totalValueInCents += nickelValueInCents;
    }
    else if(diameter == quarterDiameter){
        totalValueInCents += quarterValueInCents;
    }
    else{
        invalidCoinCount++;
    }
}

int VendingMachine::GetTotalValueInCents() {
    return totalValueInCents;
}

VendingMachine::VendingMachine() {
    totalValueInCents = 0;
    invalidCoinCount = 0;
}

int VendingMachine::GetInvalidCoinCount() {
    return invalidCoinCount;
}

VendingMachine::VendingMachine(vector<Product> products) {

}

void VendingMachine::SelectProduct(int productId) {

}

int VendingMachine::GetProductQuantity(int productId) {
    return 0;
}
