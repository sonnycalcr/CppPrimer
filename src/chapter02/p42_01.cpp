#include "chapter01/Sales_item.h"
#include <iostream>

void test()
{
    int uninitialized_var;
    std::cout << uninitialized_var << std::endl;
}

int main()
{
    int sum = 0, value, // sum, value, and units_sold have type int
        units_sold = 0; // sum and units_sold have initial value 0
    Sales_item item;    // item has type Sales_item (see § 1.5.1 (p. 20))
    // string is a library type, representing a variable-length sequence of characters
    std::string book("0-201-78345-X"); // book initialized from string literal

    std::cout << "sum: " << sum << std::endl;
    std::cout << "value: " << value << std::endl;
    std::cout << "units_sold: " << units_sold << std::endl;
    std::cout << "item: " << item << std::endl;

    // test();
    return 0;
}
