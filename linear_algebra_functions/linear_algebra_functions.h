#ifndef linear_algebra_functions_h
#define linear_algebra_functions_h

#include "../matrix/matrix.h"

void LU_lower_triangular_solve(matrix& A, int n);
void LU_upper_triangular_solve(matrix& A, int n);
void LU_factorize(matrix& A);

#endif