import os
import matplotlib.pyplot as plt

# number of nodes in mesh (DOF+2)
N = 11
# (k*u'')'' + (p*u')' + q*u = f, constant coeffecients
coeffecients = [1,0,0] # (k, p, q)
# LHS of PDE
f = [[1 for i in range(N)], # f(x) at nodes
	 [0 for i in range(N)]] # f'(x) at nodes
# boundary conditions
boundary = [[0, 0],  # u(0),  u(1)
			[0, 0]]	 # u'(0), u'(1)

# U = fourthOrderFEsolver(N,coeffecients,f,boundary);

os.system("./local_matrix '{}' '{}' '{}' '{}' ".format(N,coeffecients,f,boundary))
U = [i for i in range(100)]

h = 1./len(U)
x = [i*h for i in range(len(U))]
plt.figure()
plt.plot(x,U)

plt.ylabel("u(x)")
plt.xlabel("x")
plt.show()