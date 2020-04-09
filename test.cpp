#include <iostream>

class test {
	private:
	 int _n; // rows
	 int _m; // columns
	protected:
	 double* _values;
	public:
	 test(int m, test m);
	 double operator () (int i, int j);
};

test::test(int n, int m) {
	this->_n = n;
	this->_m = m;
	this->values = 
}
int main() {
	
	return 0;
}