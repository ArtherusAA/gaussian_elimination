#include "gauss.h"


const double EPS = 1e-9;

int gauss_elim_wo_m_el(int n, int m, double **mat)
{
    if (n > m) {
        return 0;
    }
    // forward elimination
    for (int i = 0; i < n; i++) {
        // find first non-zero element
        int j = i, flag = 0;
        for (; j < n && !flag; j++) {
            if (fabs(mat[j][i]) >= EPS) {
                flag = 1;
            }
        }
        if (!flag) {
            return 0;
        }
        j--;
        if (i != j) {
            double *tmp = *(mat + j);
            *(mat + j) = *(mat + i);
            *(mat + i) = tmp;
        }
        double c = mat[i][i];
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
    return 1;
}
