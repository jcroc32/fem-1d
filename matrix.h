#ifndef matrix_h 
#define matrix_h 

#include <iostream>
#include <exception> 

class matrix {
	private:
	 int _n; // rows
	 int _m; // columns
	protected:
	 double* _values;
	public:
	 matrix(int n, int m);
	 matrix(int n, int m, double* values, bool i_understand_my_responsibility);
	 int n();
	 int m();
	 double* values();
	 void operator = (matrix& A);
	 void unsafe_assign(double* values, bool i_understand_my_responsibility);
	 void set(int i, int j, double value);
	 double operator () (int i, int j);
};

std::ostream& operator << (std::ostream& out, matrix& A);
matrix operator + (matrix& A, matrix& B);
matrix operator * (matrix& A, matrix& B);

class dimension_mismatch: public std::exception {
	virtual const char* what() const throw() {
		return "Matrix dimensions do not match.";
	}
};

class rangeoutofbounds: public std::exception {
	virtual const char* what() const throw() {
		return "Tried to acess matrix index that does not exist.";
	}
};

class be_responsible: public std::exception {
	virtual const char* what() const throw() {
		return "You are assigning the matrix in a dangerous way. Check that it is correct and the acknowldge it is your responsibility now.";
	}
};

#endif 