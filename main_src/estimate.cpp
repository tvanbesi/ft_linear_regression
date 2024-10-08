#include "ft_linear_regression.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if(argc != 3) {
        std::cerr << "Missing arguments: [theta1] [theta0]\n";
        return 1;
    }

    double a{std::stod(argv[1])};
    double b{std::stod(argv[2])};

    unsigned int mileage;
    std::cout << "Enter car mileage in km: " << std::flush;
    std::cin >> mileage;

    double estimated_price{estimate_price(mileage, a, b)};
    std::cout << "The estimated car price is: $" << estimated_price << '\n';

    return 0;
}
