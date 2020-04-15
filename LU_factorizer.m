A = [ 1,3,5,7,
	11,13,17,19,
	23,29,31,37,
	41,43,47,53]

%%%
L = eye(size(A));
U = zeros(size(A));
U(1,1) = A(1,1);
for i = 2:length(A)
	U(1:i-1,i) = L(1:i-1,1:i-1)\A(1:i-1,i);
	L(i,1:i-1) = U(1:i-1,1:i-1)'\A(i,1:i-1)';
	U(i,i) = A(i,i) - L(i,1:i-1)*U(1:i-1,i);
end
%%%
L
U
A - L*U