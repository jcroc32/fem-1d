#include "matrix.h"
matrix::matrix(int n, int m, double* values) { 
	this->n = n;
	this->m = m;
	this->values = values;
}
double matrix::operator () (int i, int j) {  
	return this->values[i*this->m+j];
}
void matrix::set(int i, int j, double value) { 
	this->values[i*this->m+j] = value;
}
int index(int i, int j, int m) {
	return i*m+j;
}
std::ostream& operator << (std::ostream& out, matrix& A) { 
    out << "[ ";
	for(int i = 0; i < A.n; i++) { 
		for(int j = 0; j < A.m; j++) { 
			if(j == 0 && i != 0) { 
				out << "  ";
			}
			out << A(i,j);
			if(j != A.m-1) { 
				out << ", ";
			}
		}
		if(i != A.n-1) { 
			out << std::endl;
		}
	}
	out << " ]" << std::endl;
    return out;
}
matrix operator + (matrix& A, matrix& B) { 
	double* C = new double[A.n*A.m];
	for(int i = 0; i < A.n; i++) { 
		for(int j = 0; j < A.m; j++) { 
			C[index(i,j,A.m)] = A(i,j)+B(i,j);
		}
	}
	return matrix(A.n,A.m,C); 
}
matrix operator * (matrix& A, matrix& B) { 
	double* C = new double[A.n*B.m] {0};
	for(int i = 0; i < A.n; i++) { 
		for(int j = 0; j < B.m; j++) { 
			for(int k = 0; k < B.n; k++) { 
				C[index(i,j,B.m)] = C[index(i,j,B.m)] + A(i,k)*B(k,j);
			}
		}
	}
	return matrix(A.n,B.m,C);
}