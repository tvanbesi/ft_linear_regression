#pragma once

#include "CarData.hpp"
#include "estimate_price.hpp"
#include <iostream>
#include <vector>

void print_gnuplot_input(const double& a, const double& b);

void train_model(const std::vector<CarData>& dataset, double& theta0, double& theta1,
                 const double learning_rate, const unsigned int iterations);