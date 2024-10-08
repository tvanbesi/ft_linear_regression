#include "unstandardize_affine_function.hpp"

std::pair<double, double> unstandardize_affine_function(const double a, const double b,
                                                        const CarData& mean,
                                                        const CarData& standard_deviation)
{
    double coefficient{standard_deviation.price / standard_deviation.mileage * a};
    double bias{standard_deviation.price * b -
                (standard_deviation.price * a * mean.mileage / standard_deviation.mileage) +
                mean.price};

    return std::pair<double, double>(coefficient, bias);
}
