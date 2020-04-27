function [A, F] = global_matrix(N, c, f, BC, A0, A1, A2)
	% make global matrix A s.t. A*U = F
	% remove A[0:2,:],  A[:,0:2],  A[-2:,:], A[:,-2:] to add to RHS later
	A0_ = 	[ [ A0(3,3), A0(3,4), A0(4,3), A0(4,4) ] ...
			repmat(A0'(:)',1,N-2) ...
			[ A0(1,1), A0(1,2), A0(2,1), A0(2,2) ] ];
	A1_ = 	[ [ A1(3,3), A1(3,4), A1(4,3), A1(4,4) ] ...
			repmat(A1'(:)',1,N-2) ...
			[ A1(1,1), A1(1,2), A1(2,1), A1(2,2) ] ];
	A2_ = 	[ [ A2(3,3), A2(3,4), A2(4,3), A2(4,4) ] ...
			repmat(A2'(:)',1,N-2) ...
			[ A2(1,1), A2(1,2), A2(2,1), A2(2,2) ] ];
	A = 	c(1)*A0_ + c(2)*A1_ + c(3)*A2_;
	
	row = zeros(size(A0_));
	n = 5;
	for j = 3:2:2*N-2
		for i = j-2:j+1
			row(n:n+3) = [i, i, i, i];
			n = n+4;
		end
	end
	row(1:4) = [1, 1, 2, 2];
	row(end-3:end) = [2*N-3, 2*N-3, 2*N-2, 2*N-2];
	
	col = zeros(size(A0_));
	n = 5;
	for j = 3:2:2*N-2
		for i = 1:4
			col(n:n+3) = j-2:j+1;
			n = n+4;
		end
	end
	col(1:4) = [1, 2, 1, 2];
	col(end-3:end) = [2*N-3, 2*N-2, 2*N-3, 2*N-2];
	
	A = sparse(row, col, A, 2*N-2, 2*N-2);
	
	% make F for A*U = F
	% move A[0:2,:],  A[:,0:2],  A[-2:,:], A[:,-2:] to add to RHS
	A_ = c(1)*A0 + c(2)*A1 + c(3)*A2;
	bc1 = BC(1)*A_(:,1) + BC(2)*A_(:,2);
	bc2 = BC(3)*A_(:,3) + BC(4)*A_(:,4);
	% create A0 to integrate f*v
	A0_ = 	repmat(A0'(:),1,N);
	
	row = zeros(size(A0_));
	n = 1;
	for j = 3:2:2*N+2
		for i = j-2:j+1
			row(n:n+3) = [i, i, i, i];
			n = n+4;
		end
	end
	
	col = zeros(size(A0_));
	n = 1;
	for j = 3:2:2*N+2
		for i = 1:4
			col(n:n+3) = j-2:j+1;
			n = n+4;
		end
	end
	A0 = sparse(row, col, A0_, 2*N+2, 2*N+2);
	F = zeros(2*N+2,1);
	i = 1;
	for x = 0:2*N+1
		F(i) = f(floor(x/2)/(N-1))(mod(x,2)+1);
		i = i+1;
	end
	% S fv dx
	F = A0*F;
	F(1:4) = F(1:4) - bc1;
	F(end-3:end) = F(end-3:end) - bc2;
	F = F(3:end-2);
end