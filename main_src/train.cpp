#include "ft_linear_regression.hpp"
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

    double theta0 = 0.0, theta1 = 0.0;
    auto dataset = read_dataset("res/data.csv");
    train_model(dataset, theta0, theta1, learning_rate, iterations);

    std::cout << "The training has been completed for " << static_cast<double>(iterations)
              << " iterations with a learning rate of " << learning_rate << '\n'
              << "θ0: " << theta0 << '\n'
              << "θ1: " << theta1 << '\n';

    return 0;
}