#include <iostream>

class test {
	private:
	 int _n; // rows
	 int _m; // columns
	protected:
	 double* _values;
	public:
	 int n();
	 int m();
	 test(int n, int m);
	 double operator () (int i, int j);
};

test::test(int n, int m) {
	this->_n = n;
	this->_m = m;
	this->_values = new double[n*m]{0};
}

int test::n() {
	return this->_n;
}

int test::m() {
	return this->_m;
}
double test::operator () (int i, int j) {
	return this->_values[i*this->_n+j];	
}

std::ostream& operator << (std::ostream& out, test A) {
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

int main() {
	test A(5,3);
	std::cout << A;
	return 0;
}