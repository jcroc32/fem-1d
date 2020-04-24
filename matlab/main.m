N = 9; % DOF + 1
 % (k*u")" + (p*u')' + q*u = f, constant coeffecients
k = 1; 
p = 1; 
q = 0;
f = 12*linspace(0,1,10).^2 + 24;   % f(x)
fp = 24*linspace(0,1,10); % f'(x)
u0 = 1;  % u(0) 
up0 = 0; % u'(0)
u1 = 2;  % u(1)
up1 = 4; % u'(1)

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