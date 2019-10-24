#include <Product.h>
#include "gtest/gtest.h"

TEST(ProductSuite, whenProductIsDispensed_thenQuantityIsUpdated){
    Product product = Product();
    product.Id = 1;
    product.Quantity = 2;

    product.Dispense();

    EXPECT_EQ(1, product.Quantity);
}
