#include <iostream>
#include "linear_algebra_functions.h"


matrix::matrix(int n, int m) {
	this->n = n;
	this->m = m;
}

int matrix::get_n() {
	return this->n;
}

int matrix::get_m() {
	return this->m;
}

void matrix::set(double* values) {
	this->values = values;
}

double* matrix_multiply(int n, int p, int m, double* A, double* B) {
	double* C = new double[n*m];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			C[i*m+j] = 0;
			for(int k = 0; k < p; k++) {
				C[i*m+j] += A[i*p+k]*B[k*m+j];
			}
		}
	}
	return C;
}

matrix matrix_multiply(matrix& A, matrix& B) {
	int n = A.get_n();
	int p = A.get_m();
	int m = B.get_m();
	matrix C = new matrix(n,m);
	C.set(matrix_multiply(n, p, int m, A, B))
}

void print_matrix(int n, int m, double* A) {
	std::cout<<"[ ";
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(j == 0 && i != 0) {
				std::cout<<"  ";
			}
			std::cout<<A[i*m+j];
			if(j != m-1) {
				std::cout<<", ";
			}
		}
		if(i != n-1) {
			std::cout<<std::endl;
		}
	}
	std::cout<<" ]"<<std::endl;
}

int main() {
	
	double A[3*3];
	double B[3*2];
	for(int i = 0; i < 3; i++) {
		A[i*3+0] = 2;
		A[i*3+1] = 4;
		A[i*3+2] = 6;
		B[i*2+0] = 1;
		B[i*2+1] = 3;
	}
	print_matrix(3,3,A);
	print_matrix(3,2,B);
	double* C = matrix_multiply(3,3,2,A,B);
	print_matrix(3,2,C);
	return 0;
}
