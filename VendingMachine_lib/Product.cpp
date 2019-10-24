
#include "Product.h"

void Product::Dispense() {
    Quantity--;
}

Product::Product() {
    Id = 0;
    PriceInCents = 0;
    Quantity = 0;
}
