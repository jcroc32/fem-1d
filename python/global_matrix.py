import scipy.sparse

def create(N, c, f, BC, A0, A1, A2):
	A0 = 	[ A0[2,2], A0[2,3], A0[3,2], A0[3,3] ] + 
			(N-2)*[ i for a in A0 for i in a ] +
			[ A0[0,0], A0[0,1], A0[3,1], A0[1,1] ]
	
	A1 = 	[ A1[2,2], A1[2,3], A1[3,2], A1[3,3] ] + 
			(N-2)*[ i for a in A1 for i in a ] +
			[ A1[0,0], A1[0,1], A1[3,1], A1[1,1] ]
	
	A2 = 	[ A2[2,2], A2[2,3], A2[3,2], A2[3,3] ] + 
			(N-2)*[ i for a in A2 for i in a ] +
			[ A2[0,0], A2[0,1], A2[3,1], A2[1,1] ]
	
	A = [ c[0]*A0[i] + c[1]*A1[i] + c[2]*A2[i] for i in range(len(A0)) ]
	
	row = [ i  for j in range(2, 2*N+2, 2)  for i in range(j-2, j+2)  for k in range(4) ]
	column = [ i  for j in range(2, 2*N+2, 2)  for k in range(4)  for i in range(j-2, j+2) ]
	
	A = scipy.sparse.coo_matrix( (A, (row, column)), shape=(2*N-2, 2*N-2))
	A = A.tobsr()
	
	
	A0 = scipy.sparse.coo_matrix( (A0, (row, column)), shape=(2*N-2, 2*N-2) )
	A0 = A0.tobsr()
	f = np.array( [ f(x//2/N)[x%2] for x in range(2,2*N) ] )
	# S fv dx
	F = A0*f
	
	return (A, F)