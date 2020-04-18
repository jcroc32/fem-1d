import os
import matplotlib.pyplot as plt

# number of nodes in mesh (DOF+2)
N = 11
# (k*u'')'' + (p*u')' + q*u = f, constant coeffecients
coeffecients = [1,0,0] # (k, p, q)
# LHS of PDE
f = ['1', '0'] # f(x), f'(x)
# boundary conditions
boundary = [[0, 0],  # u(0),  u(1)
			[0, 0]]	 # u'(0), u'(1)
# solve FE eqution
U = os.system("./linear_4th_order_1D_fem_solver '{}' '{}' '{}' '{}' ".format(N,coeffecients,f,boundary))
U = [i for i in range(100)]
# plot solution
h = 1./len(U)
x = [i*h for i in range(len(U))]
plt.figure()
plt.plot(x,U)

plt.ylabel("u(x)")
plt.xlabel("x")
plt.show()