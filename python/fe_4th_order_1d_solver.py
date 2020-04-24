import numpy as np
import scipy.sparse.linalg
import local_matrix
import global_matrix

def solve(N, c, f, BC, x):
	h = 1/(N-1)
	elements, A0, A1, A2 = local_matrix.create(h)
	A, F = global_matrix.create(N, c, f, BC, A0, A1, A2)
	U = scipy.sparse.linalg.spsolve(A, F)
	U = np.concatenate( (BC[:2], U, BC[2:]) )
	# get values for given x
	# make x relative to mesh points
	x = x*N
	# initialize solution vector 
	u = np.zeros_like(x)
	# get index of U to use for x 
	elem = np.floor(x)
	if elem[-1] == N:
		# no N-1 index so must use previous node
		# (thus use 1 instead of -1 x value)
		elem[-1] = N-1
	# take x to [-1, 1] domain so we can use our elements
	x = 2*(x - elem)-1
	# elements in coeffecient form, so make polynmial values
	x = np.vander(x, 4)
	i = 0
	for n in elem:
		# uj(x) = sum Uij*elementi (or u(x) = sum Ui*vi(x))
		u[i] = np.dot(U[2*int(n):2*int(n)+4]@elements, x[i,:])
		i = i+1
	return u