#include "VendingMachine.h"

std::string VendingMachine::GetMessage() {
    std::stringstream stream;
    std::string message = "INSERT COIN";
    if(DisplayThankYou) {
        message = "THANK YOU";
        totalValueInCents = 0;
        DisplayThankYou = false;
    }
    else if(!productAvailability && totalCostInCents > 0){
        stream << "PRICE " << std::fixed << std::setprecision(2) << totalCostInCents / 100.00;
        message = stream.str();
    }
    else if (totalValueInCents > 0){
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

int VendingMachine::GetInvalidCoinCount() {
    return invalidCoinCount;
}

bool VendingMachine::SelectProduct(int totalProductCostInCents) {
    productAvailability = totalProductCostInCents <= totalValueInCents;
    totalCostInCents = totalProductCostInCents;

    if(productAvailability) {
        DisplayThankYou = true;
        totalValueInCents -= totalProductCostInCents;
    }
    return productAvailability;
}



