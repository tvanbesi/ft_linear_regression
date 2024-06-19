#include "ft_linear_regression.hpp"
#include <iostream>

int main()
{
    unsigned int mileage;
    std::cout << "Enter car mileage in km: ";
    std::cin >> mileage;

    double theta0 = 0.0;
    double theta1 = 0.0;
    unsigned int estimated_price = estimate_price(mileage, theta0, theta1);
    std::cout << "The estimated car price is: $" << estimated_price << '\n';

    return 0;
}