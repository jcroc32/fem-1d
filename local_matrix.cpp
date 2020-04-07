#include "linear_algebra_functions.h"
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