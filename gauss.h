#ifndef GAUSS_H
#define GAUSS_H

#include <math.h>

/*
 * Given n x m matrix with elements of double type, it performs 
 * Gaussian elimination without main element, and returns 1 
 * in case of success. If n > m or the most left n x n submatrix's
 * determinant is less than 0, it returns 0.
 */ 
int gauss_elim_wo_m_el(int n, int m, double **mat);

#endif

