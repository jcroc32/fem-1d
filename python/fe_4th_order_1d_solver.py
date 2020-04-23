import numpy as np
import scipy.sparse.linalg
import local_matrix
import global_matrix

def solve(N, c, f, BC, x):
	h = 1./(N-1)
	elements, A0, A1, A2 = local_matrix.create(h)
	A, F = global_matrix.create(N, c, f, BC, A0, A1, A2)
	u = scipy.sparse.linalg.spsolve(A, F)
	
	return u