#include "../matrix/matrix.h"
// #include "../linear_algebra_functions/linear_algebra_functions.h"

int main() {
	int n = 12*500;
	double* a = new double[n*n] {0};
	double* x = new double[n*n] {0};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			a[i*n+j] = 4.54345245679*i*n+j;
			x[i*n+j] = 91.361*i*n+.22*j;
		}
	}
	matrix A(n,n,a);
	matrix X(n,n,x);
	//LU_factorize(A);
	matrix B = A*X;
	std::cout << B(5,5) << std::endl;
	std::cout << X(0,357) << std::endl;
	return 0;
}