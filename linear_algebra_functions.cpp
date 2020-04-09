#include <iostream>
#include "linear_algebra_functions.h"
/* matrix class functions */
matrix::matrix(int n, int m, double* values) {
	this->_n = n;
	this->_m = m;
	this->_values = values;
}

matrix::matrix(int n, int m) {
	this->_n = n;
	this->_m = m;
	this->_values = new double[n*m]; // set to zero explicitly
}

int matrix::n() {
	return this->_n;
}

int matrix::m() {
	return this->_m;
}

double* matrix::values() {
	return this->_values;
}

void matrix::set(double* values) { // add error handling
	double* temp = this->_values;
	this->_values = values;
	delete temp;
}

void matrix::set(int i, int j, double value) {
	if(i >= this->_n || j >= this->_m) { // better error handling
		std::cerr<<"Indices not in range of matirx dimensions.";
	}
	this->_values[i*this->_m+j] = value;
}

double matrix::cell(int i, int j) {
	if(i >= this->_n || j >= this->_m) { //better error handling
		std::cerr<<"Indices not in range of matirx dimensions.";
	}
	return this->_values[i*this->_m+j];
}

/* matrix operations */
friend ostream& operator << (ostream& out, matrix A) {
    out << "[ ";
	for(int i = 0; i < A.n(); i++) {
		for(int j = 0; j < A.m(); j++) {
			if(j == 0 && i != 0) {
				out << "  ";
			}
			out << A(i,j);
			if(j != A.m()-1) {
				out << ", ";
			}
		}
		if(i != A.n()-1) {
			out << std::endl;
		}
	}
	out << " ]" << std::endl;
    return out;
}

matrix operator + (matrix &A, matrix &B) { 
	matrix C(A.n(),A.m());
	for(int i = 0; i < A.n(); i++) {
		for(int j = 0; j < A.m(); j++) {
			C.set(i, j, A.cell(i,j)+B.cell(i,j));
		}
	}
	return C; 
}

double matrix::operator () (int i) { 
	return this->_values[i];
}

double matrix::operator () (int i, int j) { 
	return this->_values[i*this->_n+j];
}

void multiply(matrix& A, matrix& B, matrix& C) { // check A.m = B.m()
	for(int i = 0; i < A.n(); i++) {
		for(int j = 0; j < B.m(); j++) {
			for(int k = 0; k < B.n(); k++) {
				C.set(i, j, (C.cell(i,j) + A.cell(i,k)*B.cell(k,j)));
			}
		}
	}
}
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

void LU_factorization(matrix& U, matrix& x) {
	
}