#include "ft_linear_regression.hpp"
#include <iostream>

int main()
{
    unsigned int mileage;
    std::cout << "Enter car mileage in km: ";
    std::cin >> mileage;

    double a{0.0};
    double b{0.0};
    double estimated_price{estimate_price(mileage, a, b)};
    std::cout << "The estimated car price is: $" << estimated_price << '\n';

    return 0;
}