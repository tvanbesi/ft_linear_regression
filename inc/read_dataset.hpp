#pragma once

#include "CarData.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<CarData> read_dataset(const std::string& filename);