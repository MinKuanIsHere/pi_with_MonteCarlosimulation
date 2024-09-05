#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    long long int number_in_circle = 0; // count fall into the circle.
    long long int number_of_tosses = 10000000; // total tosses.

    // Set seeds to ensure the number generator remains consistent across experiments
    srand(0);

    // Generate for number of tosses
    for (long long int toss=0; toss<=number_of_tosses; toss++){

        // Random generator x between -1 and 1
        double x = (double)rand() / RAND_MAX * 2.0 - 1.0;

        // Random generator y between -1 and 1
        double y = (double)rand() / RAND_MAX * 2.0 - 1.0;
        
        // The distance from (x,y) to (0,0)
        double distance_squared = x * x + y * y;
        
        // If the point fall into the circle then count
        if (distance_squared <= 1){
            number_in_circle++;
        }
    }

    // find the pi
    double pi_estimate = 4 * number_in_circle /(( double ) number_of_tosses);

    printf("pi_estimate=%.4f\n", pi_estimate); 

    return 0;
}

