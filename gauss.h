#ifndef GAUSS_H
#define GAUSS_H

#include <math.h>
#include <stdlib.h>
#include <string.h>

/*
 * Given n x m matrix with elements of double type, it performs 
 * Gaussian elimination without main element, and returns 1 
 * in case of success. If n > m or the most left n x n submatrix's
 * determinant is less than 0, it returns 0.
 */ 
double gauss_elim_wo_m_el(int n, int m, double **mat);
double gauss_elim(int n, int m, double **mat);

double determinant(int n, double **mat);

// Calculates reverse of the matrix, returns positive integer
// if reverse matrix is calculated correctly, zero, if determinant
// is zero, and negative integer if malloc error occured.
int reverse(int n, double **mat, double **reverse);

#endif

