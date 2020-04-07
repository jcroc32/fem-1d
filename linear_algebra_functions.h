#ifndef linear_algebra_functions_h
#define linear_algebra_functions_h

class matrix {
	private:
	 int _n;
	 int _m;
	protected:
	 double* _values;
	public:
	 matrix(int n, int m, double* values);
	 matrix(int n, int m);
	 int n();
	 int m();
	 double* values();
	 void set(double* values);
	 void set(int i, int j, double value);
	 double cell(int i, int j);
	 void print();
};

class vector { // implement vector as subclass
	private:
	 int _n;
	protected:
	 double* _values;
	public:
	 vector(int n, double* values);
	 vector(int n);
	 int n();
	 double* values();
	 void set(double* values);
	 void set(int i, double value);
	 double cell(int i);
	 void print();
};

matrix* matrix_multiply(matrix& A, matrix& B);
vector* solve_upper_triangular_system(matrix U, vector x);
vector* solve_lower_triangular_system(matrix L, vector x);

#endif