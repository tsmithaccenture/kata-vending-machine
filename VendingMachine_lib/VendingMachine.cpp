#include "VendingMachine.h"

string VendingMachine::GetMessage() {
    return "INSERT COIN";
}

void VendingMachine::InsertCoin(double diameter) {
    if (diameter == dimeDiameter)
        totalAmount = dimeValue;
    else
        totalAmount = quarterValue;
}

int VendingMachine::GetTotalAmount() {
    return totalAmount;
}
