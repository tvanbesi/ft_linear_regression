#include "read_dataset.hpp"

std::vector<CarData> read_dataset(const std::string& filename)
{
    std::ifstream ifs(filename);

    if(!ifs.is_open())
        throw std::runtime_error("Could not open " + filename);

    std::string line;
    std::getline(ifs, line); // Skip first line - csv labels

    std::vector<CarData> data;
    while(std::getline(ifs, line)) {
        std::istringstream iss(line);
        std::string token;

        double mileage;
        double price;

        std::getline(iss, token, ',');
        mileage = std::stod(token);
        std::getline(iss, token, ',');
        price = std::stod(token);

        data.push_back({.mileage = mileage, .price = price});
    }

    return data;
}