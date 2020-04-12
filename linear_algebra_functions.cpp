#include <iostream>
#include "linear_algebra_functions.h"

// ones on the diagonal
void solve_lower_triangular_system(matrix& L, matrix& x) {
	for(int i = 0; i < L.n(); i++) {
		if(L.cell(i,i) != 1) {
			std::cerr<<"Invalid lower triangular matrix.";
		}
		for(int j = 0; j < i; j++) {
			x.set(i, 1, x.cell(i,1) - L.cell(i,j)*x.cell(j,1));
		}
	}
}
// no zeros on diagonal
void solve_upper_triangular_system(matrix& U, matrix& x) {
	for(int i = U.n()-1; i > -1; i--) {
		if(U.cell(i,i) == 0) {
			std::cerr<<"Divide by zero error.";
		}
		for(int j = U.n()-1; j > i; j--) {
			x.set(i, 1, x.cell(i,1) - U.cell(i,j)*x.cell(j,1));
		}
		x.set(i, 1, x.cell(i,1)/U.cell(i,i));
	}
}
//
void LU_factorization(matrix& U) {
	
}