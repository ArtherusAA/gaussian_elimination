#include "gauss.h"


const double EPS = 1e-9;

double determinant(int n, double **mat) 
{
    return gauss_elim_wo_m_el(n, n, mat);
}

int reverse(int n, double **mat, double **reverse) 
{
    double **new_mat = malloc(sizeof(double *) * n);
    if (new_mat == NULL) {
        return -1;
    }
    for (int i = 0; i < n; i++) {
        new_mat[i] = malloc(sizeof(double) * 2 * n);
        if (new_mat[i] == NULL) {
            return -1;
        }
        memcpy(new_mat[i], mat[i], n * sizeof(double));
        for (int j = n; j < 2 * n; j++) {
            new_mat[i][j] = (j == i + n ? 1 : 0);
        }
    }
    double det = gauss_elim_wo_m_el(n, 2 * n, new_mat);
    if (fabs(det) < EPS) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        memcpy(reverse[i], new_mat[i] + n, sizeof(double) * n);
        free(new_mat[i]);
    }
    free(new_mat);
    return 1;
}

double gauss_elim(int n, int m, double **mat)
{
    if (n > m) {
        return 0;
    }
    return 0;
}

double gauss_elim_wo_m_el(int n, int m, double **mat)
{
    if (n > m) {
        return 0;
    }
    double res = 1;
    // forward elimination
    for (int i = 0; i < n; i++) {
        // find first non-zero element
        int j = i, it = i;
        double mx = fabs(mat[i][i]);
        for (; j < n; j++) {
            if (fabs(mat[j][i]) >= mx) {
                it = j;
                mx = fabs(mat[j][i]);
            }
        }
        if (mx < EPS) {
            return 0;
        }
        j--;
        if (i != it) {
            double *tmp = *(mat + it);
            *(mat + it) = *(mat + i);
            *(mat + i) = tmp;
            res *= -1;
        }
        double c = mat[i][i];
        res *= c;
        for (j = i; j < m; j++) {
            mat[i][j] /= c;
        }
        for (j = i + 1; j < n; j++) {
            c = mat[j][i];
            for (int k = i; k < m; k++) {
                mat[j][k] -= c * mat[i][k];
            }
        }
    }

    // backward elimination
    for (int i = n - 1; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            double c = mat[j][i];
            for (int k = 0; k < m; k++) {
                mat[j][k] -= c * mat[i][k];
            }
        }
    }
    return res;
}
