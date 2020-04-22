import scipy.sparse

def createA(N, A0, A1, A2, c):
	A0 = N*[c(0)[0]*i for a in A0 for i in a]
	A1 = N*[c(0)[1]*i for a in A1 for i in a]
	A2 = N*[c(0)[2]*i for a in A2 for i in a]
	row = [i  for j in range(2, 2*N+2, 2)  for i in range(j-2, j+2)  for k in range(4)]
	column = [i  for j in range(2, 2*N+2, 2)  for k in range(4)  for i in range(j-2, j+2)]
	
	A = scipy.sparse.coo_matrix((data, (row, column)), shape=(2*N+2, 2*N+2))
	A = A.tobsr()
	return A

def createA0(N, A0):
	A0 = N*[i for a in A0 for i in a]
	row = [i  for j in range(2, 2*N+2, 2)  for i in range(j-2, j+2)  for k in range(4)]
	column = [i  for j in range(2, 2*N+2, 2)  for k in range(4)  for i in range(j-2, j+2)]
	
	A = scipy.sparse.coo_matrix((A0, (row, column)), shape=(2*N+2, 2*N+2))
	A = A.tobsr()
	return A