N = 10; % DOF + 1
 % (k*u")" + (p*u')' + q*u = f, constant coeffecients
k = 1; 
p = 0; 
q = 0;
f = ones(1,N+1);   % f(x)
fp = zeros(1,N+1); % f'(x)
u0 = 0;  % u(0) 
up0 = 0; % u'(0)
u1 = 0;  % u(1)
up1 = 0; % u'(1)

U = fourthOrderFEsolver(N,k,p,q,f,fp,u0,u1,up0,up1,@localMatrix,@globalMatrix);
 
figure()
t = linspace(0,1,length(U));
plot(t,U)

plot(t,U)
ylabel('u(x)')
xlabel('x')
% 
%  g = @(x) 1/24*(x.^4 - 2*x.^3 + x.^2);
%  hold on 
%  plot(t, g(t), 'r')