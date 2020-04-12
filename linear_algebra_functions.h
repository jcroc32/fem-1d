#ifndef linear_algebra_functions_h
#define linear_algebra_functions_h

#include "matrix.h"

void solve_upper_triangular_system(matrix& U, matrix& x);
void solve_lower_triangular_system(matrix& L, matrix& x);
void LU_factorization(matrix& U);

#endif