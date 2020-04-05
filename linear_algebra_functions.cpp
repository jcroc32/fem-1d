#include <iostream>

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
