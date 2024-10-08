#pragma once

#include "CarData.hpp"
#include "get_mean.hpp"
#include "get_standard_deviation.hpp"
#include "get_variance.hpp"
#include <vector>

std::vector<CarData> standardize_dataset(const std::vector<CarData>& dataset);
