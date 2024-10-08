#pragma once

#include "CarData.hpp"
#include <cmath>
#include <vector>

CarData get_variance(const std::vector<CarData>& dataset, const CarData& mean);
