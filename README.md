# ft_linear_regression

## Dependencies

+ gnuplot
+ g++
+ make

To install on Ubuntu 22.04: `sudo apt install gnuplot g++ make -y`

## Running the Project

Use the `estimate.bash` and `plot.bash` script to run the project.

`estimate.bash` will train the model and ask the user for input and predict the price of a car.

`plot.bash` will train the model and ouput the value of the coefficient and bias a 100 times at regular interval during the training. It will then use gnuplot to display the affine function converging towards fitting the data.
