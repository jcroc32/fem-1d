import numpy as np
import matplotlib.pyplot as plt
import fe_4th_order_1d_solver

# (c0*u")" + (c1*u')' + c2*u = f
# number of nodes in the mesh
N = 3
# coeffecients
def c(x):
	return (1, 0, 0)
# LHS (f, f')
def f(x):
	return (1, 0)
# boundary conditions (u0, u'0, u1, u'1)
BC = (0, 0, 0, 0)
# solve pde
x = np.linspace(0, 1, num=100);
u = fe_4th_order_1d_solver.solve(N, c, f, BC, x)
# plot solution
plt.plot(x, u, '.-')
plt.ylabel('u(x)')
plt.xlabel('x')
plt.show()