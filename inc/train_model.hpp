#pragma once

#include "CarData.hpp"
#include "estimate_price.hpp"
#include <iostream>
#include <utility>
#include <vector>

void print_gnuplot_input(const double& a, const double& b);

/**
 * @brief Train the model to the find the affine function that fits
 *
 * @param dataset The dataset to train the model on
 * @param theta0 The initial bias that - be updated
 * @param theta1 The initial coefficient - will be updated
 * @param learning_rate The learning rate
 * @param iterations The amount of iterations to train the model
 */
void train_model(const std::vector<CarData>& dataset, double& theta0, double& theta1,
                 const double& learning_rate, const unsigned int& iterations);
