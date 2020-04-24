import numpy as np
import matplotlib.pyplot as plt
import fe_4th_order_1d_solver

# (c2*u")" + (c1*u')' + c0*u = f
# number of nodes in the mesh
N = 10
# PDE coeffecients (c0, c1, c2)
c = (1, 1, 1)
# RHS (f, f')
def f(x):
	return (x**4, 4*x**3)
# boundary conditions (u0, u'0, u1, u'1)
BC = (1, 1, 1, 1)
# solve pde
x = np.linspace(0, 1, num=40)
u = fe_4th_order_1d_solver.solve(N, c, f, BC, x)
# plot solution
plt.plot(x, u, '.-')
plt.ylabel('u(x)')
plt.xlabel('x')
plt.show()