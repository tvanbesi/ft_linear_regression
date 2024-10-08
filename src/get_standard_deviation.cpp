#include "get_standard_deviation.hpp"

CarData get_standard_deviation(const CarData& variance)
{
    return CarData{.mileage{std::sqrt(variance.mileage)}, .price{std::sqrt(variance.price)}};
}
