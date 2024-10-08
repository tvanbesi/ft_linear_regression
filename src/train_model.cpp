#include "train_model.hpp"

// a and b as in a linear function like y = a*x + b
void print_gnuplot_input(const double& a, const double& b)
{
    std::cout << "a=" << a << '\n' << "b=" << b << '\n';
}

void train_model(const std::vector<CarData>& dataset, double& a, double& b,
                 const double learning_rate, const unsigned int iterations)
{
    const double m{static_cast<double>(dataset.size())};
    const double factor{learning_rate / m};

    print_gnuplot_input(a, b);

    std::vector<double> errors;
    errors.reserve(m);

    for(unsigned int i{0}; i < iterations; ++i) {
        double sum_a{0.0}, sum_b{0.0};

        errors.clear();

        for(unsigned int j{0}; j < m; ++j) {
            const double mileage{static_cast<double>(dataset.at(j).mileage)};
            const double estimated_price{estimate_price(dataset.at(j).mileage, a, b)};
            const double actual_price{static_cast<double>(dataset.at(j).price)};
            const double error{estimated_price - actual_price};

            errors.push_back(error);

            sum_a += error * mileage;
            sum_b += error;
        }

        const double tmp_a{factor * sum_a};
        const double tmp_b{factor * sum_b};
        a -= tmp_a;
        b -= tmp_b;

        // Print gnuplot input but not every iteration if there are more than 100
        if(iterations > 100) {
            if(i % (iterations / 100) == 0)
                print_gnuplot_input(a, b);
        }
        else
            print_gnuplot_input(a, b);
    }
}
