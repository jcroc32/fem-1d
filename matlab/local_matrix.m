function [elements, A0, A1, A2] = local_matrix(h)
	% create element such that fi(i) = 1, 
	% else fi(j != i) = 0, i = -1,-1',1,1'
	%	[f(-1),		f'(-1),			f(1),		f'(1)	]
	A = [(-1)^3		3*(-1)^2		(1)^3		3*(1)^2;
		 (-1)^2		2*(-1)^1		(1)^2		2*(1)^1;
		 (-1)^1		1*(-1)^0		(1)^1		1*(1)^0;
		 (-1)^0		0				(1)^0		0		];
	elements = A\eye(size(A));
	elements = elements.*[1; h/2; 1; h/2];
	% Gaussian quadrature, exact for deg 7 and below
	weights = [	0.3478548451374538; 0.6521451548625461;
				0.6521451548625461; 0.3478548451374538];
	points = [ -0.8611363115940526, -0.3399810435848563, ...
				0.3399810435848563,  0.8611363115940526];
	% mass matrix A0 = S X^T*X dx
	A0 = zeros(4);
	points_matrix = vander(points, 7)';
	for i = 1:4
		Xi = elements(i,:);
		for j = 1:4
			Xj = elements(j,:);
			A0(i,j) = conv(Xi,Xj)*points_matrix*weights;
		end
	end
	% stiffness matrix A1 = S X'^T*X' dx
	A1 = zeros(4);
	points_matrix = vander(points, 5)';
	for i = 1:4
		Xi = polyder(elements(i,:));
		for j = 1:4
			Xj = polyder(elements(j,:));
			A1(i,j) = conv(Xi,Xj)*points_matrix*weights; 
		end
	end
	% bending matrix A2 = S X''^T*X'' dx
	A2 = zeros(4);
	points_matrix = vander(points, 3)';
	for i = 1:4
		Xi = polyder(polyder(elements(i,:)));
		for j = 1:4
			Xj = polyder(polyder(elements(j,:)));
			A2(i,j) = conv(Xi,Xj)*points_matrix*weights;
		end
	end
	% multiply by jacobian
	A0 = h/2*A0;
	A1 = 2/h*A1;
	A2 = 8/h^3*A2;
end