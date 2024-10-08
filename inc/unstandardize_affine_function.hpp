#pragma once

#include "CarData.hpp"
#include <utility>

/**
 * @brief Unstandardize an affine function
 *
 * @param a coefficient of affine function to unstandardize
 * @param b bias of affine function to unstandardize
 * @param mean means of the original target values
 * @param standard_deviation standard deviation of the original target values
 * @return std::pair<double, double> a pair containing the unstandardized affine function as:
 * <coefficient, bias>
 */
std::pair<double, double> unstandardize_affine_function(const double a, const double b,
                                                        const CarData& mean,
                                                        const CarData& standard_deviation);
