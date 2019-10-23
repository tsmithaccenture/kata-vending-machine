#include "VendingMachine.h"

string VendingMachine::GetMessage() {
    return "INSERT COIN";
}

void VendingMachine::InsertCoin(double diameter) {
    if (diameter == 17.91)
        totalAmount = 10;
    else
        totalAmount = 25;
}

int VendingMachine::GetTotalAmount() {
    return totalAmount;
}
