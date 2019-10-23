#include "VendingMachine.h"

#include <iomanip>
#include <sstream>

std::string VendingMachine::GetMessage() {
    std::stringstream stream;
    string message = "INSERT COIN";
    if (totalAmount > 0){
        stream << std::fixed << std::setprecision(2) << totalAmount / 100.00;
        message = stream.str();
    }
    return message;
}

void VendingMachine::InsertCoin(double diameter) {
    if (diameter == dimeDiameter){
        totalAmount = dimeValue;
    }
    else if(diameter == nickelDiameter){
        totalAmount = nickelValue;
    }
    else if(diameter == quarterDiameter){
        totalAmount = quarterValue;
    }
}

int VendingMachine::GetTotalAmount() {
    return totalAmount;
}
