set datafile separator ","
set title "Car Prices vs Kilometers Driven"
set xlabel "Kilometers (km)"
set ylabel "Price ($)"
set grid

file = "training_output.txt"
total_lines = real(system(sprintf("wc -l < %s", file)))

f(x) = a*x + b

# Loop through each line to extract a and b values and plot them
do for [i=1:int(total_lines/2)] {
    a = real(system(sprintf("sed -n '%dp' %s | cut -d'=' -f2", 2*i-1, file)))
    b = real(system(sprintf("sed -n '%dp' %s | cut -d'=' -f2", 2*i, file)))

    f(x) = a*x + b

    if (i == 1) {
        plot "res/standardized_data.csv" using 1:2 with points title "Data Points", \
             f(x) with lines title sprintf("y = %.2Ex + %.2E", a, b)
    } else {
        replot
    }
    
    print sprintf("Current function: y = %.2Ex + %.2E", a, b)
    pause -1 "Press Enter to continue to the next step, or Ctrl+C to stop..."
}
