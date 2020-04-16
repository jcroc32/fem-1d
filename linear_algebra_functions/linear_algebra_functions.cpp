#include "linear_algebra_functions.h"
void LU_lower_triangular_solve(matrix& A, int n) { 
	for(int i = 0; i < n; i++) { 
		double x = A(i,n);
		#pragma omp parallel for reduction(+:x)
		for(int j = 0; j < i; j++) { 
			x -= A(i,j)*A(j,n);
		}
		A.set(n,i,  x );
	}
}
void LU_upper_triangular_solve(matrix& A, int n) { 
	for(int i = n-1; i > -1; i--) { 
		double x =  A(n,i);
		#pragma omp parallel for reduction(+:x)
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