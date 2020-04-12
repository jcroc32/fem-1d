#include "matrix.h"

/* matrix class functions */
matrix::matrix(int n, int m) {
	this->_n = n;
	this->_m = m;
	this->_values = new double[n*m]{0};
}

matrix::matrix(int n, int m, double* values, bool i_understand_my_responsibility) {
	if(i_understand_my_responsibility != true) {
		throw be_responsible();
	}
	this->_n = n;
	this->_m = m;
	this->_values = values;
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

void matrix::unsafe_assign(double* values, bool i_understand_my_responsibility) {
	if(i_understand_my_responsibility != true) {
		throw be_responsible();
	}
	double* temp = this->_values;
	this->_values = values;
	delete temp;
}

void matrix::operator = (matrix& A) { 
	this->_n = A.n();
	this->_m = A.m();
	double* temp = this->_values;
	this->_values = A.values();
	delete temp;
}

void matrix::set(int i, int j, double value) {
	if(i >= this->_n || j >= this->_m) {
		throw rangeoutofbounds();
	}
	this->_values[i*this->_m+j] = value;
}

double matrix::operator () (int i, int j) { 
	return this->_values[i*this->_m+j];
}

/* matrix operations */
std::ostream& operator << (std::ostream& out, matrix& A) {
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

matrix operator + (matrix& A, matrix& B) { 
	if(A.n() != B.n() || A.m() != B.m()) {
		throw dimension_mismatch();
	}
	matrix C(A.n(),A.m());
	for(int i = 0; i < A.n(); i++) {
		for(int j = 0; j < A.m(); j++) {
			C.set(i, j, A(i,j)+B(i,j));
		}
	}
	return C; 
}

matrix operator * (matrix& A, matrix& B) {
	if(A.m() != B.n()) {
		throw dimension_mismatch();
	}
	matrix C(A.n(),B.m());
	for(int i = 0; i < A.n(); i++) {
		for(int j = 0; j < B.m(); j++) {
			for(int k = 0; k < B.n(); k++) {
				C.set(i, j, (C(i,j) + A(i,k)*B(k,j)));
			}
		}
	}
	return C;
}