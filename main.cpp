#include <iostream>
#include "linear_algebra_functions.h"
#include "local_matrix.h"

double f(double x) {
	return x*x*x;
}

// temp testing area
int main() {
	matrix A(3,3);
	matrix B(3,2);
	for(int i = 0; i < 3; i++) {
		A.set(i,0,2);
		A.set(i,1,4);
		A.set(i,2,6);
		B.set(i,0,1);
		B.set(i,1,3);
	}
	A.print();
	B.print();
	matrix* C = multiply(A,B);
	C->print();
	
	
	double L_[3*3] = {	1,0,0,
						4,1,0,
						7,8,1 };
	double U_[3*3] = {	1,2,3,
						0,5,8,
						0,0,11 };
	double b_[3] = {1,2,3};
	
	matrix L(3,3,L_);
	matrix U(3,3,U_);
	vector b(3,b_);
	
	L.print();
	U.print();
	b.print();
	
	vector* x = solve_lower_triangular_system(L,b);
	vector* y = solve_upper_triangular_system(U,b);
	
	x->print();
	y->print();
	
	
	function2d element[4];
	element[0] = element_1;
	element[1] = element_2;
	element[2] = element_3;
	element[3] = element_4;
	double v = -.5371944;
	double h = .1;
	std::cout<<element[0](h,v)<<std::endl;
	std::cout<<element[1](h,v)<<std::endl;
	std::cout<<element[2](h,v)<<std::endl;
	std::cout<<element[3](h,v)<<std::endl;
	double value = gauss_4_point_quadrature(f);
	std::cout<<value<<std::endl;
	
	return 0;
}