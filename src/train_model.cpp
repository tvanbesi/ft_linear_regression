#include "train_model.hpp"

void train_model(const std::vector<CarData>& dataset, double& theta0, double& theta1,
                 const double learning_rate, const unsigned int iterations)
{
    unsigned int m = dataset.size();

    for(unsigned int i = 0; i < iterations; ++i) {
        double sum0 = 0.0, sum1 = 0.0;
        for(unsigned int j = 0; j < m; ++j) {
            double error =
                static_cast<double>(estimate_price(dataset.at(j).mileage, theta0, theta1)) -
                static_cast<double>(dataset.at(j).price);
            sum0 += error;
            sum1 += error * static_cast<double>(dataset.at(j).mileage);
        }
        theta0 -= learning_rate * sum0 / static_cast<double>(m);
        theta1 -= learning_rate * sum1 / static_cast<double>(m);
    }
}