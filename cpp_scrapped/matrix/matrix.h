#ifndef matrix_h 
#define matrix_h 

#include <iostream>
#include <thread> 

class matrix { 
	public:
	 int n; // rows
	 int m; // columns
	 double* values;
	 matrix(int n, int m, double* values);
	 double operator () (int i, int j);
	 void set(int i, int j, double value);
};

std::ostream& operator << (std::ostream& out, matrix& A);
matrix operator + (matrix& A, matrix& B);
matrix operator * (matrix& A, matrix& B);

#endif 