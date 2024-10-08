#include "get_mean.hpp"

CarData get_mean(const std::vector<CarData>& dataset)
{
    CarData mean{.mileage{0}, .price{0}};
    for(const auto& data : dataset) {
        mean.mileage += data.mileage;
        mean.price += data.price;
    }
    mean.mileage /= dataset.size();
    mean.price /= dataset.size();

    return mean;
}
