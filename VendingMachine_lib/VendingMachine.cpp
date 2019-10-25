#include "VendingMachine.h"

std::string VendingMachine::GetMessage() {
    std::stringstream stream;
    std::string message = "INSERT COIN";
    if(resetVendingMachine) {
        message = "THANK YOU";
        ResetVendingMachine();
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
        returnedCoinCount++;
    }
}

int VendingMachine::GetTotalValueInCents() {
    return totalValueInCents;
}

int VendingMachine::GetReturnedCoinCount() {
    return returnedCoinCount;
}

bool VendingMachine::SelectProduct(int productCostInCents) {

    if(totalValueInCents >= productCostInCents){
        productAvailability = true;
        resetVendingMachine = true;
        totalValueInCents -= productCostInCents;
        returnedCoinCount += totalValueInCents;
    }
    totalCostInCents = productCostInCents;
    return productAvailability;
}

void VendingMachine::ResetVendingMachine() {
    resetVendingMachine = false;
    productAvailability = false;
    totalCostInCents = 0;
    totalValueInCents = 0;

}



