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
	this->_values = values; // must delete old values
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

void matrix::print() {
	std::cout<<"[ ";
	for(int i = 0; i < this->_n; i++) {
		for(int j = 0; j < this->_m; j++) {
			if(j == 0 && i != 0) {
				std::cout<<"  ";
			}
			std::cout<<this->cell(i,j);
			if(j != this->_m-1) {
				std::cout<<", ";
			}
		}
		if(i != this->_n-1) {
			std::cout<<std::endl;
		}
	}
	std::cout<<" ]"<<std::endl;
}
/* vector class functions */
vector::vector(int n, double* values) {
 	this->_n = n;
	this->_values = values;
}
vector::vector(int n) {
	this->_n = n;
	this->_values = new double[n]; // set to zero explicitly
}
int vector::n(){
	return this->_n;
}
double* vector::values() {
	return this->_values;
}
void vector::set(double* values) { // add error handling
	this->_values = values; // must delete old values
}
void vector::set(int i, double value) {
	if(i >= this->_n) { // better error handling
		std::cerr<<"Indices not in range of matirx dimensions.";
	}
	this->_values[i] = value;
}
double vector::cell(int i) {
	if(i >= this->_n) { //better error handling
		std::cerr<<"Indices not in range of matirx dimensions.";
	}
	return this->_values[i];
}
void vector::print() {
	std::cout<<"[ ";
	for(int i = 0; i < this->_n; i++) {
		if(i != 0) {
			std::cout<<"  ";
		}
		std::cout<<this->cell(i);
		if(i != this->_n-1) {
			std::cout<<std::endl;
		}
	}
	std::cout<<" ]"<<std::endl;
}
/* matrix operations */
matrix* multiply(matrix& A, matrix& B) { // check A.m = B.m()
	matrix* C = new matrix(A.n(),B.m());
	for(int i = 0; i < A.n(); i++) {
		for(int j = 0; j < B.m(); j++) {
			for(int k = 0; k < B.n(); k++) {
				C->set(i, j, (C->cell(i,j) + A.cell(i,k)*B.cell(k,j)));
			}
		}
	}
	return C;
}

vector* solve_lower_triangular_system(matrix L, vector b) {
	vector* x = new vector(L.n());
	for(int i = 0; i < L.n(); i++) {
		x->set(i, b.cell(i));
		for(int j = 0; j < i; j++) {
			x->set(i, x->cell(i) - L.cell(i,j)*x->cell(j));
		}
		x->set(i, x->cell(i)/L.cell(i,i));
	}
	return x;
}

vector* solve_upper_triangular_system(matrix U, vector b) {
	vector* x = new vector(U.n());
	for(int i = U.n()-1; i > -1; i--) {
		x->set(i, b.cell(i));
		for(int j = U.n()-1; j > i; j--) {
			x->set(i, x->cell(i) - U.cell(i,j)*x->cell(j));
		}
		x->set(i, x->cell(i)/U.cell(i,i));
	}
	return x;
}