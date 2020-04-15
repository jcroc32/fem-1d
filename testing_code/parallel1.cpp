#include <math.h>
#include <iostream>

static const int size = 1024 * 1024 * 128;
int main(){
    double total = 0;

#pragma omp parallel for reduction(+:total)
    for (int i = 0; i < size; i++)
        total += sin(i) + sin(i*i) + sin(sqrt(i)) + cos(i*i);
    std::cout << total << "\n";
}