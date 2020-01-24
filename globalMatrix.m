function A = globalMatrix(A_local,N)
N_entries = 2*N+2;

v = zeros(1,N_entries); % just temporary vector
v(1:2:end-1) = A_local(1,1)+A_local(3,3);   % f overlap
v(2:2:end) = A_local(2,2)+A_local(4,4); % f' overlap
A = diag(v); % main diagonal 

v = zeros(1,N_entries-1);
v(1:2:end) = A_local(2,1)+A_local(4,3); % f*f' overlap (symmetry used
v(2:2:end-1) = A_local(3,2);            % for supper and sub)
A = A + diag(v,1);  % 1st supper diagonal
A = A + diag(v,-1); % 1st sub diagonal

v = zeros(1,N_entries-2);
v(1:2:end-1) = A_local(3,1);
v(2:2:end) = A_local(4,2);
A = A + diag(v,2);  % upper diagonal
A = A + diag(v,-2); % lower diagonal

v = zeros(1,N_entries-3);
v(1:2:end) = A_local(4,1);
A = A + diag(v,-3);
A = A + diag(v,3);

A(1,1) = A_local(1,1); % 1st f entry no overlap
A(2,2) = A_local(2,2); % 1st f' entry no overlap
A(end,end) = A_local(end,end); % last f entry no overlap
A(end-1,end-1) = A_local(end-1,end-1); % last f' entry no overlap

A(2,1) = A_local(2,1); % supper diag 1st entry no overlap
A(1,2) = A_local(1,2); % sub diag 1st entry no overlap
A(end,end-1) = A_local(end,end-1); % supper diag last entry no overlap
A(end-1,end) = A_local(end-1,end); % sub diag last entry no overlap
end