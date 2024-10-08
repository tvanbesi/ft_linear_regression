#include "standardize.hpp"

std::vector<CarData> standardize_dataset(const std::vector<CarData>& dataset)
{
    CarData mean{.mileage{0}, .price{0}};
    for(const auto& data : dataset) {
        mean.mileage += data.mileage;
        mean.price += data.price;
    }
    mean.mileage /= dataset.size();
    mean.price /= dataset.size();

    CarData variance{.mileage{0}, .price{0}};
    for(const auto& data : dataset) {
        variance.mileage += std::pow(data.mileage - mean.mileage, 2);
        variance.price += std::pow(data.price - mean.price, 2);
    }
    variance.mileage /= dataset.size();
    variance.price /= dataset.size();

    CarData standard_deviation{.mileage{std::sqrt(variance.mileage)},
                               .price{std::sqrt(variance.price)}};

    std::vector<CarData> standardized_dataset;
    for(const auto& data : dataset)
        standardized_dataset.push_back(
            CarData{.mileage{(data.mileage - mean.mileage) / standard_deviation.mileage},
                    .price{(data.price - mean.price) / standard_deviation.price}});

    return standardized_dataset;
}
