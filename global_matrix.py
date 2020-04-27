import numpy as np
import scipy.sparse

def create(N, c, f, BC, A0, A1, A2):
	# make global matrix A s.t. A*U = F
	# remove A[0:2,:],  A[:,0:2],  A[-2:,:], A[:,-2:] to add to RHS later
	A0_ = 	[ A0[2,2], A0[2,3], A0[3,2], A0[3,3] ] + (N-2)*[ i for a in A0 for i in a ] + [ A0[0,0], A0[0,1], A0[1,0], A0[1,1] ]
	
	A1_ = 	[ A1[2,2], A1[2,3], A1[3,2], A1[3,3] ] + (N-2)*[ i for a in A1 for i in a ] + [ A1[0,0], A1[0,1], A1[1,0], A1[1,1] ]
	
	A2_ = 	[ A2[2,2], A2[2,3], A2[3,2], A2[3,3] ] + (N-2)*[ i for a in A2 for i in a ] + [ A2[0,0], A2[0,1], A2[1,0], A2[1,1] ]
	
	A = 	[ c[0]*A0_[i] + c[1]*A1_[i] + c[2]*A2_[i] for i in range(len(A0_)) ]
	
	row = 	[0, 0, 1, 1] + [ i  for j in range(2, 2*N-2, 2) for i in range(j-2, j+2)  for k in range(4) ] + [2*N-4, 2*N-4, 2*N-3, 2*N-3]
	
	col = 	[0, 1, 0, 1] + [ i  for j in range(2, 2*N-2, 2) for k in range(4)  for i in range(j-2, j+2) ] + [2*N-4, 2*N-3, 2*N-4, 2*N-3]
	
	A = scipy.sparse.coo_matrix( (A, (row, col)), shape=(2*N-2, 2*N-2))
	A = A.tocsr()
	
	# make F for A*U = F
	# move A[0:2,:],  A[:,0:2],  A[-2:,:], A[:,-2:] to add to RHS
	A_ = c[0]*A0 + c[1]*A1 + c[2]*A2
	bc1 = BC[0]*A_[:,0] + BC[1]*A_[:,1]
	bc2 = BC[2]*A_[:,2] + BC[3]*A_[:,3]
	# create A0 to integrate f*v
	A0_ = 	N*[ i for a in A0 for i in a ]
	row = 	[ i  for j in range(2, 2*N+2, 2) for i in range(j-2, j+2)  for k in range(4) ]
	col = 	[ i  for j in range(2, 2*N+2, 2) for k in range(4)  for i in range(j-2, j+2) ]
	A0 = scipy.sparse.coo_matrix( (A0_, (row, col)), shape=(2*N+2, 2*N+2) )
	A0 = A0.tocsr()
	f = np.array( [ f(x//2/(N-1))[x%2] for x in range(2*N+2) ] )
	# S fv dx
	F = A0@f
	F[:4] = F[:4] - bc1
	F[-4:] = F[-4:] - bc2
	F = F[2:-2]
	return (A, F)