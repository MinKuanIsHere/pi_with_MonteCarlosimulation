## Solution
- 目標是要計算圓的$\pi$，當中的想法是蒙地卡羅模擬來投擲有成功落在圓裡面的機率，並透過正方形和圓的面積比例來推倒$\pi$。

- 給定邊長是2英尺一個正方形，在當中繪製一個半徑是1英尺的圓。正方形的面積為$2 \times 2=4$，圓的面積為$1 \times 1 \times \pi=\pi$。因此，圓面積占正方形面積是$\frac{\pi}{4}$。

- 接下來用亂數投擲來計算有成功落在圓面積的機率，即$\frac{C}{N}$。在模擬中，我們會亂數產生隨機變數$X$和$Y$，他們對應到的是一個平面上的x軸和y軸座標。已知圓的半徑是1英尺，並假設圓的圓心的座標是(0,0)，則我們只要計算$X$和$Y$跟圓心的距離，就可以知道是否有落在圓當中。做法是，只要$^2+y^2 \in [-1,1]$，則表示有落在圓裡面，這樣就可以計算$C$和$N$。

- 最後，根據$\frac{C}{N} = \frac{\pi}{4}$的移項，即可以得$\pi=\frac{C}{N} \times 4$。

## Implement

To complete the task, we'll write a C program that uses the Monte Carlo method to estimate the value of π, create a Makefile to compile the program, and ensure everything works according to the requirements.

Below is the C code that uses the Monte Carlo method to estimate π:

#### `pi.c`
```c=
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


```
