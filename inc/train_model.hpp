#pragma once

#include "CarData.hpp"
#include "estimate_price.hpp"
#include <vector>

void train_model(const std::vector<CarData>& dataset, double& theta0, double& theta1,
                 const double learning_rate, const unsigned int iterations);