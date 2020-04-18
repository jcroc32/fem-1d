import numpy as np
import matplotlib.pyplot as plt

# (c0*u")" + (c1*u')' + c2*u = f
# number of nodes in the mesh
N = 10
# coeffecients
def c():
	return (1, 0, 0)
# LHS (f,f')
def f():
	return (1, 0)
# boundary conditions (u0,u'0,u1,u'1)
BC = (0, 0, 0, 0)
# solve pde
u = fe_4th_ordere_1d_solver(N,c,f,BC)
# plot solution
x = np.linspace(0, 1, num=u.shape[0]);
plt.plot(x, u, '.-')
plt.ylabel('u(x)')
plt.xlabel('x')
plt.show()