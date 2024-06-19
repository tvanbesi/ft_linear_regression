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

        unsigned int mileage;
        unsigned int price;

        std::getline(iss, token, ',');
        mileage = std::stoul(token);
        std::getline(iss, token, ',');
        price = std::stoul(token);

        data.push_back({.mileage = mileage, .price = price});
    }

    return data;
}