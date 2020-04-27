function u = fe_4th_order_1d_solver(N, c, f, BC, x)
	h = 1/(N-1);
	[elements, A0, A1, A2] = local_matrix(h);
	[A, F] = global_matrix(N, c, f, BC, A0, A1, A2);
	U = A\F;
	U = [BC(1:2)'; U; BC(end-1:end)'];
	% get values for given x
	% make x relative to mesh points
	x = x*N;
	% initialize solution vector 
	u = zeros(size(x));
	% get index of U to use for x 
	elem = floor(x);
	if elem(end) == N
		% no N index so must use previous node
		% (thus use 1 instead of -1 x value)	
		elem(end) = N-1; 
	end
	% take x to [-1, 1] domain so we can use our elements
	x = 2*(x - elem)-1;
	% elements in coeffecient form, so make polynmial values
	x = vander(x, 4)';
	i = 1;
	for n = elem
		u(i) = U((2*n+1):(2*n+4))'*elements*x(:,i);
		i = i+1;
	end
end