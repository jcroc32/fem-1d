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
			C[i*A.m+j] = A(i,j)+B(i,j);
		}
	}
	return matrix(A.n,A.m,C); 
}
//*
void multiply(matrix A, matrix B, double* C, int i) { 
	for(int j = 0; j < B.m; j++) { 
		for(int k = 0; k < B.n; k++) { 
			C[i*B.m+j] += A(i,k)*B(k,j);
		}
	}
}
matrix operator * (matrix& A, matrix& B) { 
	double* C = new double[A.n*B.m] {0};
	for(int i = 0; i < A.n; i+=12) { 
		std::thread t1(multiply,A,B,C,i);
		std::thread t2(multiply,A,B,C,i+1);
		std::thread t3(multiply,A,B,C,i+2);
		std::thread t4(multiply,A,B,C,i+3);
		std::thread t5(multiply,A,B,C,i+4);
		std::thread t6(multiply,A,B,C,i+5);
		std::thread t7(multiply,A,B,C,i+6);
		std::thread t8(multiply,A,B,C,i+7);
		std::thread t9(multiply,A,B,C,i+8);
		std::thread t10(multiply,A,B,C,i+9);
		std::thread t11(multiply,A,B,C,i+10);
		std::thread t12(multiply,A,B,C,i+11);
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		t5.join();
		t6.join();
		t7.join();
		t8.join();
		t9.join();
		t10.join();
		t11.join();
		t12.join();
	}
	return matrix(A.n,B.m,C);
}
//*/
/*
void multiply(int n) { 
	std::cout << n << std::endl;
}
matrix operator * (matrix& A, matrix& B) { 
	std::thread t1(multiply,3);
	t1.join();
	double* C = new double[A.n*B.m] {0};
	for(int i = 0; i < A.n; i++) { 
		for(int j = 0; j < B.m; j++) { 
			for(int k = 0; k < B.n; k++) { 
				C[i*B.m+j] += A(i,k)*B(k,j);
			}
		}
	}
	return matrix(A.n,B.m,C);
}
//*/