#include "VendingMachine.h"

std::string VendingMachine::GetMessage() {
    std::stringstream stream;
    std::string message = "INSERT COIN";
    if(productAvailability) {
        message = "THANK YOU";
        ResetVendingMachine();
    }
    else if(!productAvailability && purchasePriceInCents > 0){
        stream << "PRICE " << std::fixed << std::setprecision(2) << purchasePriceInCents / 100.00;
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

void VendingMachine::SelectProduct(std::string selectedProduct) {
    if(selectedProduct.compare("cola") == 0){
        BuyProduct(100);
    }
    else if(selectedProduct.compare("chips")  == 0){
        BuyProduct(50);
    }
    else if(selectedProduct.compare("candy") == 0){
        BuyProduct(65);
    }
}

bool VendingMachine::BuyProduct(int productCostInCents) {

    if(totalValueInCents >= productCostInCents){
        productAvailability = true;
        totalValueInCents -= productCostInCents;
        returnedCoinCount += totalValueInCents;
    }
    purchasePriceInCents = productCostInCents;
    return productAvailability;
}

void VendingMachine::ResetVendingMachine() {
    productAvailability = false;
    purchasePriceInCents = 0;
    totalValueInCents = 0;
}



