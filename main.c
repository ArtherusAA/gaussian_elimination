#include <stdio.h>
#include <stdlib.h>
#include "gauss.h"
#include "matrix_io.h"

int
main(void)
{
    double **a, **b;
    int n, m;
    scanf("%d%d", &n, &m);


    a = malloc(sizeof(double *) * n);
    if (!a) {
        fprintf(stderr, "Memory allocation error\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        a[i] = malloc(sizeof(double) * (m));
        if (!a[i]) {
            fprintf(stderr, "Memory allocation error\n");
            return 1;
        }
    }

    b = malloc(sizeof(double *) * n);
    if (!b) {
        fprintf(stderr, "Memory allocation error\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        b[i] = malloc(sizeof(double) * (m));
        if (!b[i]) {
            fprintf(stderr, "Memory allocation error\n");
            return 1;
        }
    }



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    
    if (reverse(n, a, b) > 0) {
        print_matrix(n, n, b);
    }

    /*
    double ret = gauss_elim_wo_m_el(n, m, a);

    printf("%lf\n", ret);

    print_matrix(n, m, a);
*/
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}
