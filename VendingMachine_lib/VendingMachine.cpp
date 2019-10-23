#include "VendingMachine.h"

string VendingMachine::GetMessage() {
    return "INSERT COIN";
}

void VendingMachine::InsertCoin(double diameter) {
    if (diameter == dimeDiameter)
        totalAmount = dimeValue;
    if(diameter == nickelDiameter){
        totalAmount = nickelValue;
    }
    else
        totalAmount = quarterValue;
}

int VendingMachine::GetTotalAmount() {
    return totalAmount;
}
