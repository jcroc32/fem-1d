class matrix {
	private:
	 int n;
	 int m;
	protected:
	 double* values;
	public:
	 matrix(int n, int m);
	 int get_n();
	 int get_m();
	 void set(double* values);
};

double* matrix_multiply(int n, int p, int m, double* A, double* B);
matrix matrix_multiply(matrix& A, matrix& B);

void print_matrix(int n, int m, double* A);
void print_matrix(matrix& A);
