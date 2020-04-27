% (c2*u")" + (c1*u')' + c0*u = f
% number of nodes in the mesh
N = 5;
% PDE coeffecients c0, c1, c2
c2 = 1; c1 = 1; c0 = 1;
c = [c0, c1, c2];
% RHS [f, f']
f = @(x) [cos(x), -sin(x)]; 
% boundary conditions (u0, u'0, u1, u'1)
BC = [0, 3, 1, -3];
% solve pde
x = linspace(0, 1, 100);
u = fe_4th_order_1d_solver(N, c, f, BC, x);
% plot solution
figure(1)
plot(x,u,'.-')
ylabel('u(x)')
xlabel('x')