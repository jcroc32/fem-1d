import numpy as np

def create(h):
	# create element such that fi(i) = 1, else fi(j != i) = 0, i = -1,-1',1,1'
	#				[ 	f(-1),			f'(-1),			f(1),		f'(1)	]
	A = np.array( [	[	(-1)**3,		3*(-1)**2,		(1)**3,		3*(1)**2],
					[	(-1)**2,		2*(-1)**1,		(1)**2,		2*(1)**1],
					[	(-1)**1,		1*(-1)**0,		(1)**1,		1*(1)**0],
					[	(-1)**0,		0,				(1)**0,		0		]	])
	elements = np.linalg.solve(A, np.eye(4))
	elements = elements*np.array([[1], [h/2], [1], [h/2]])
	(points, weights) = np.polynomial.legendre.leggauss(4)
	# mass matrix A0 = S X^T*X dx
	A0 = np.zeros((4,4))
	points_matrix = np.vander(points, 7)
	for i in range(4):
		X = elements[i]
		for j in range(4):
			Y = elements[j]
			A0[i,j] = np.dot(points_matrix @ np.polymul(X, Y), weights)
	# stiffness matrix A1 = S X'^T*X' dx
	A1 = np.zeros((4,4))
	points_matrix = np.vander(points, 5)
	for i in range(4):
		X = np.polyder(elements[i], 1)
		for j in range(4):
			Y = np.polyder(elements[j], 1)
			A1[i,j] = np.dot(points_matrix @ np.polymul(X, Y), weights)
	# bending matrix A2 = S X"^T*X" dx
	A2 = np.zeros((4, 4))
	points_matrix = np.vander(points, 3)
	for i in range(4):
		X = np.polyder(elements[i], 2)
		for j in range(4):
			Y = np.polyder(elements[j], 2)
			A2[i,j] = np.dot(points_matrix @ np.polymul(X, Y), weights)
	# multiply by jacobian
	A0 = h/2*A0
	A1 = 2/h*A1
	A2 = 8/h**3*A2
	return (elements, A0, A1, A2)