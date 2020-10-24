#include "gauss.h"


const double EPS = 1e-9;

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
