unsigned int estimate_price(unsigned int mileage, double theta0, double theta1)
{
	return static_cast<unsigned int>(theta0 + theta1 * static_cast<double>(mileage));
}