function A = globalMatrix(A_local,N)
%%N = 2*N+2;
%%s = zeros(1,6*N-8);
%% % main diagonal
%%s(1) = A_local(1,1);
%%s(2) = A_local(2,2);
%%s(3:2:N-2) = A_local(1,1) + A_local(3,3);
%%s(4:2:N-2) = A_local(2,2) + A_local(4,4);
%%s(N-1) = A_local(3,3);
%%s(N) = A_local(4,4);
%% % 1st sub and super diagonal
%%s(N+1) = A_local(2,1);
%%s([N+2:2:2*N-1, 2*N+1:2:3*N-2]) = A_local(3,2);
%%s([N+3:2:2*N-1, 2*N+2:2:3*N-2]) = A_local(2,1) + A_local(4,3);
%%s(2*N) = A_local(1,2);
%%s(2*N-1) = A_local(4,3);
%%s(3*N-2) = A_local(4,3);
%% % 2nd sub and super diagonal
%%s(3*N-1:2:5*N-6) = A_local(3,1);
%%s(3*N:2:5*N-6) = A_local(4,2);
%% % 3rd sub and super diagonal
%%s(5*N-5:6*N-8) = A_local(4,1);
%% % indices: main, 1super, 1sub, 2super, 2sub, 3super,  3sub
%%i = [1:N, 1:N-1, 2:N, 1:N-2, 3:N, 1:2:N-3, 4:2:N];
%%j = [1:N, 2:N, 1:N-1, 3:N, 1:N-2, 4:2:N, 1:2:N-3];
%%
%%A = sparse(i,j,s,N,N);

A = sparse(1,1,0,N,N,6*N-8)
	index = 1:4;
	for k = 1:N/2 - 1
		A(index,index) = A(index,index) + A_local;
		index = index + 2;
	end
end