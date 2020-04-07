#include "linear_algebra_functions.h"
typedef double (*function2d) (double h, double x);


double element_1(double h, double x) { return (x*x*x - 3*x + 2)/4; }
double element_2(double h, double x) { return h*(x*x*x - x*x - x + 1)/8; }
double element_3(double h, double x) { return (-x*x*x + 3*x + 2)/4; }
double element_4(double h, double x) { return h*(x*x*x + x*x - x - 1)/8; }

double gauss_4_point_quadrature(double f(double)) {
	double weight[4] = { 0.3478548451374538,
						 0.6521451548625461,
						 0.6521451548625461,
						 0.3478548451374538};
	
	double point[4] = {	-0.8611363115940526,
						-0.3399810435848563,
						 0.3399810435848563,
						 0.8611363115940526};
	
	double result = 0;
	for(int i = 0; i < 4; i++) {
		result+=weight[i]*f(point[i]);
	}
	return result;
}

double f(double x) {
	return x*x*x;
}

#include <iostream>
int main() {
	function2d element[4];
	element[0] = element_1;
	element[1] = element_2;
	element[2] = element_3;
	element[3] = element_4;
	double x = -.5371944;
	double h = .1;
	std::cout<<element[0](h,x)<<std::endl;
	std::cout<<element[1](h,x)<<std::endl;
	std::cout<<element[2](h,x)<<std::endl;
	std::cout<<element[3](h,x)<<std::endl;
	double value = gauss_4_point_quadrature(f);
	std::cout<<value<<std::endl;
	return 0;
}
