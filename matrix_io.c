#include "matrix_io.h"

void print_matrix(int n, int m, double **a) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%lf ", a[i][j]);
        }
        putchar('\n');
    }
}
