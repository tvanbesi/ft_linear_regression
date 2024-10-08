#include "get_variance.hpp"

CarData get_variance(const std::vector<CarData>& dataset, const CarData& mean)
{
    CarData variance{.mileage{0}, .price{0}};
    for(const auto& data : dataset) {
        variance.mileage += std::pow(data.mileage - mean.mileage, 2);
        variance.price += std::pow(data.price - mean.price, 2);
    }
    variance.mileage /= dataset.size();
    variance.price /= dataset.size();

    return variance;
}
