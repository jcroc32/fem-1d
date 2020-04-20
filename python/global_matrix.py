import scipy.sparse

def create(N, A0, A1, A2, c):
	data = N*[i for a in A0 for i in a]
	row = [i  for j in range(2, 2*N+2, 2)  for i in range(j-2, j+2)  for k in range(4)]
	column = [i  for j in range(2, 2*N+2, 2)  for k in range(4)  for i in range(j-2, j+2)]
	
	A = scipy.sparse.coo_matrix((data, (row, column)), shape=(2*N+2, 2*N+2))
	A = A.tobsr()
	return A