#include <iostream>

int main() {
	// number of nodes in mesh
	int N = 11;
	double h = 1/double(N);
	
	double k = 1; 
	double p = 0; 
	double q = 0;
	
	double f[N+1];
	for (int i = 0; i < N+1; i++){
		f[i] = 1;
	}
	double f_x[N+1];
	for (int i = 0; i < N+1; i++){
		f[i] = 0;
	}
	double u_boundary[2] = {0,0};
	double u_x_boundary[2] = {0,0};
	
	// U = fourthOrderFEsolver(N,k,p,q,f,fp,u0,u1,up0,up1,@localMatrix,@globalMatrix);
	
	//figure()
	//x = linspace(0,1,length(U));
	
	//plot(t,U)
	//ylabel('u(x)')
	//xlabel('x')
	
	std::cout<<"done"<<std::endl;
	return 0;
}
