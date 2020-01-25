function [A0,A1,A2,X] = localMatrix(h)
	% f1(x), f2(x), f3(x), f4(x) is element we are using on mesh
	% fi(x) = ai*x^3 + bi*x^2 + ci*x + di, on [-1, 1]
	% fi'(x) = 3ai*x^2 + 2bi*x + ci, on [-1, 1]
	
	% f1(-1)  = 1,    f1'(-1) = f1 (1)  = f1'(1) = 0
	% f2'(-1) = h/2,  f2(-1)  = f2 (1)  = f2'(1) = 0
	% f3(1)   = 1,    f3(-1)  = f3'(-1) = f3'(1) = 0
	% f4'(1)  = h/2,  f4'(-1) = f4'(-1) = f4 (1) = 0
	
	% fi = [x^3 x^2 x 1]^T*[ai bi ci di] = polynomial^T*coefficients = A^T*X
	
	% X = [ a1 b1 c1 d1
	%		a2 b2 c2 d2
	%		a2 b2 c2 d2
	%		a4 b4 c4 d4];
	
	%	[ poly(-1)	poly'(-1)		poly(1)		poly'(1) ]
	A = [(-1)^3		 3*(-1)^2		(1)^3		3*(1)^2;
		 (-1)^2		-2*(-1)^1		(1)^2		2*(1)^1;
		 (-1)^1		 1*(-1)^0		(1)^1		1*(1)^0;
		 (-1)^0		 0				(1)^0		0];
	
	% A * X =  [f1(-1) f1'(-1) f1(1) f1'(1) = [ 1 0   0 0		= I.*[1; h/2; 1; h/2]	= B;
	%			f2(-1) f2'(-1) f2(1) f2'(1)		0 h/2 0 0
	%			f3(-1) f3'(-1) f3(1) f3'(1)		0 0   1 0
	%			f4(-1) f4'(-1) f4(1) f4'(1)];	0 0   0 h/2];
	
	B = eye(size(A)).*[1; h/2; 1; h/2];
	X = A\B;
	% first derivative
	Xx = polyDerivative(X);
	% second derivative
	Xxx = polyDerivative(Xx);

	% check what basis looks like
	% x = transpose(-1:.1:1);
	% X = [x.^3 x.^2 x ones(size(x))];
	% figure()
	% plot(x,X*cubicHermite0)


	A0 = zeros(4);
	A1 = zeros(4);
	A2 = zeros(4);

	for n = 1:4
		A0(n,:) = gaussQuad(conv2(X,X(n,:)));
	end

	for n = 1:4
		A1(n,:) = gaussQuad(conv2(Xx,Xx(n,:)));
	end

	for n = 1:4
		A2(n,:) = gaussQuad(conv2(Xxx,Xxx(n,:)));
	end

	jacobian0 = h/2;
	jacobian1 = 2/h;
	jacobian2 = 8/h^3;

	A0 = jacobian0*A0;
	A1 = jacobian1*A1;
	A2 = jacobian2*A2;
end

function dfdx = polyDerivative(f)
	% pn(x) = an*x^n + an-1*x^n-1 + ... a0
	% length(pn) = n + 1
	poly_derivative = length(f)-1:-1:0; % n, n-1, ... 0
	coeffs = f; % an an-1 ... a0
	dfdx = coeffs.*poly_derivative;
	dfdx(:,end) = []; % pn'(x) = an*n*x^n-1 + ... a1, (remove a0 column)
end

function v = gaussQuad(f) % from -1 to 1
	% Gaussian quad, exact for deg 7 and below
	weight = [0.3478548451374538;
			  0.6521451548625461;
			  0.6521451548625461;
			  0.3478548451374538];
	x = [-0.8611363115940526, -0.3399810435848563, 0.3399810435848563, 0.8611363115940526];

	X = zeros(length(f(1,:)),length(x));
	X(end,:) = ones(size(x));
	for n = 1:length(f(1,:))-1
		X(end-n,:) = x.^n;
	end
	v = f*X*weight;
end