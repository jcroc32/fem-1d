#include "linear_algebra_functions.h"
matrix LU_lower_triangular_solve(matrix& A, matrix b) { 
	double* x = new double[A.n];
	for(int i = 0; i < n; i++) { 
		x[i] = b(i,0);
		for(int j = 0; j < i; j++) { 
			x[i] -= A(i,j)*A(j,n);
		}
	}
	return matrix(
}
void LU_upper_triangular_solve(matrix& A, int n) { 
	for(int i = n-1; i > -1; i--) { 
		double x =  A(n,i);
		for(int j = n-1; j > i; j--) { 
			x -= A(i,j)*A(n,j);
		}
		A.set(n,i,  x/A(i,i) );
	}
}
void LU_factorize(matrix& A) { 
	for(int i = 1; i < A.n; i++) { 
		LU_lower_triangular_solve(A, i);
		LU_upper_triangular_solve(A, i);
		for(int j = 0; j < i; j++) { 
			A.set(i,i,   A(i,i) - A(i,j)*A(j,i) );
		}
	}
}