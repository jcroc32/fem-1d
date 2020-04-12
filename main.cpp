//#include "linear_algebra_functions.h"
#include "matrix.h"
//#include "local_matrix.h"

// temp testing area
int main() { 
	try { 
		matrix A(3,3,new double[3*3] {1,2,3,4,5,6,7,8,9},true);
		matrix B(3,4);
		B.unsafe_assign(new double[3*4] {1,2,3,4,5,6,7,8,9,10,11,12},true);
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
		
	}
	catch (std::exception& e) { 
		std::cout << e.what() << std::endl;
	}
	return 0;
}
