#include "matrix/matrix.h"
#include "linear_algebra_functions/linear_algebra_functions.h"
//#include "local_matrix.h"

// temp testing area
int main() { 
	matrix A(3,3,new double[3*3] {1,2,3,4,5,6,7,8,9});
	matrix B(3,4,new double[3*4] {1,2,3,4,5,6,7,8,9,10,11,12});
	std::cout << A;
	std::cout << B;
	matrix C = A*B;
	matrix D = B+B;
	std::cout << C;
	std::cout << D;
	A = D;
	std::cout << A;
	A.set(0,0,2.34);
	std::cout << A;
	std::cout << D;
	
	matrix E(4,4,new double[4*4]
	{1,3,5,7,
	11,13,17,19,
	23,29,31,37,
	41,43,47,53});
	LU_factorize(E);
	std::cout << E;
}