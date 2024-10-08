#include "ft_linear_regression.hpp"
#include "standardize.hpp"
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
    auto dataset{standardize_dataset(read_dataset("res/data.csv"))};

    train_model(dataset, a, b, learning_rate, iterations);
    print_gnuplot_input(a, b);

    return 0;
}
