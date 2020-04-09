#ifndef linear_algebra_functions_h
#define linear_algebra_functions_h

class matrix {
	private:
	 int _n; // rows
	 int _m; // columns
	protected:
	 double* _values;
	public:
	 matrix(int n, int m, double* values);
	 matrix(int n, int m);
	 int n();
	 int m();
	 double* values();
	 void set(int i, int j, double value);
	 double operator () (int i, int j);
	 matrix operator = (double* values);
};
matrix operator + (matrix &A, matrix &B);
matrix operator * (matrix &A, matrix &B);

void solve_upper_triangular_system(matrix& U, matrix& x);
void solve_lower_triangular_system(matrix& L, matrix& x);

#endif