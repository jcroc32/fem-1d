import scipy.sparse.linalg
import local_matrix
import global_matrix

def solve(N, c, f, BC, x):
	h = 1./(N-1)
	elements, A0, A1, A2 = local_matrix.create(h)
	A = global_matrix.createA(N, A0, A1, A2, c)
	A0 = global_matrix.createA0(N, A0)
	f = [f(i//2/N)[i%2] for i in range(2*N+2)]
	
	# x = scipy.sparse.linalg.spsolve(A, b)
	
	###
	import numpy as np
	np.set_printoptions(suppress=True)
	np.set_printoptions(precision=4)
	print(A.toarray())
	u = x
	###
	
	return u