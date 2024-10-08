#include "standardize.hpp"

std::vector<CarData> standardize_dataset(const std::vector<CarData>& dataset)
{
    CarData mean{get_mean(dataset)};
    CarData variance{get_variance(dataset, mean)};
    CarData standard_deviation{get_standard_deviation(variance)};

    std::vector<CarData> standardized_dataset;
    for(const auto& data : dataset)
        standardized_dataset.push_back(
            CarData{.mileage{(data.mileage - mean.mileage) / standard_deviation.mileage},
                    .price{(data.price - mean.price) / standard_deviation.price}});

    return standardized_dataset;
}
