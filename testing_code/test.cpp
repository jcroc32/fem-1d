#include "fem-1d/matrix/matrix.h"
#include "fem-1d/linear_algebra_functions/linear_algebra_functions.h"

int main() {
	int n = 20000;
	double* a = new double[n*n] {0};
	double* x = new double[1*n] {0};
	for(int i = 0; i < n; i++) {
		x[i] = 4.544*i;
		for(int j = 0; j < n; j++) {
			a[i*n+j] = 4.54345245679*i*n+j;
		}
	}
	matrix A(n,n,a);
	matrix X(1,n,x);
	LU_factorize(A);
	std::cout << A(5,5) << std::endl;
	std::cout << X(0,357) << std::endl;
	return 0;
}