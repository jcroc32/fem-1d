function [U_FE] = fourthOrderFEsolver(N,k,p,q,f,fp,u0,u1,up0,up1,localMatrix,globalMatrix)
h = 1/N;
[A0_local,A1_local,A2_local,cubicHermite] = localMatrix(h);

A0 = globalMatrix(A0_local,N);
A1 = globalMatrix(A1_local,N);
A2 = globalMatrix(A2_local,N);

A = k*A2 + p*A1 + q*A0;

f = reshape([f;fp],[],1);
f = A0*f; % integral(f*v)
 %B.C
f = f - u0*A(:,1);
f = f - up0*A(:,2);
f = f - u1*A(:,end-1);
f = f - up1*A(:,end);

A(1,:) = []; A(:,1) = [];
A(1,:) = []; A(:,1) = [];
A(end,:) = []; A(:,end) = [];
A(end,:) = []; A(:,end) = [];

U = zeros(2*N+2,1);
U(3:end-2) = A\f(3:end-2);
U(1) = u0;  U(2) = up0;
U(end-1) = u1;  U(end) = up1;

%____check method___________________________________
% dom_h_1 = @(s) -(2*s - (s(1)+s(end))) /(s(1)-s(end));
% cubicH1 = @(x) 1/4*(x.^3-3*x+2);
% cubicH2 = @(x) 1/4*(x.^3-x.^2-x+1)*h/2; %%
% cubicH3 = @(x) 1/4*(-x.^3+3*x+2);
% cubicH4 = @(x) 1/4*(x.^3+x.^2-x-1)*h/2; %%
% U_FE = [];
% for n = 1:length(U)/2-1
%	xc = x(n):.0001:x(n+1);
%	xp = dom_h_1(xc);
%	U_FE = [U_FE(1:end-1) U(2*n-1)*cubicH1(xp)+U(2*n)*cubicH2(xp)+U(2*n+1)*cubicH3(xp)+U(2*n+2)*cubicH4(xp)];
% end
%_________________________________________________
x = (0:.01:1)/h;
U_FE = zeros(size(x));
X = floor(x); if X(end) == N; X(end) = N-1; end
x = 2*(x-X)-1; % take to [-1,1] 
x = [x.^3; x.^2; x; ones(size(x))];
m = 1;
for n = X
	domain = (2*n+1):(2*n+4);
	U_FE(m)= U(domain)'*cubicHermite*x(:,m);
	disp(U(domain))
	disp(x(:,m))
	m = m+1;
end
end