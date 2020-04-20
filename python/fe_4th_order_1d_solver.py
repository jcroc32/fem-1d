import scipy.sparse.linalg
import local_matrix
import global_matrix

def solve(N, c, f, BC, x):
	h = 1./(N-1)
	elements, A0, A1, A2 = local_matrix.create(h)
	A = global_matrix.create(N, A0, A1, A2, c)
	
	
	# x = scipy.sparse.linalg.spsolve(A, b)
	
	###
	import numpy as np
	np.set_printoptions(suppress=True)
	np.set_printoptions(precision=4)
	print(A.toarray())
	u = x
	###
	
	return u