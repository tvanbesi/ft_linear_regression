#include "ft_linear_regression.hpp"
#include "standardize.hpp"
#include "unstandardize_affine_function.hpp"
#include <iostream>

static void print_manual(const std::string& exec_name)
{
    std::cout << "Usage: " << exec_name << " learning_rate iterations\n";
}

int main(int argc, char* argv[])
{
    if(argc != 3) {
        print_manual(argv[0]);
        return -1;
    }
    double learning_rate = std::stod(argv[1]);
    unsigned int iterations = std::stoul(argv[2]);

    double a{0.0}, b{0.0};
    auto dataset{read_dataset("res/data.csv")};
    auto standardized_dataset{standardize_dataset(dataset)};

    train_model(standardized_dataset, a, b, learning_rate, iterations);
#ifdef GNUPLOT
    print_gnuplot_input(a, b);
#endif

    auto unstandardized_affine{unstandardize_affine_function(
        a, b, get_mean(dataset), get_standard_deviation(get_variance(dataset, get_mean(dataset))))};

#ifndef GNUPLOT
    std::cout << unstandardized_affine.first << ' ' << unstandardized_affine.second;
#endif

    return 0;
}
