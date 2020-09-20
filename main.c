#include <stdio.h>
#include <stdlib.h>

#include "gauss.h"
#include "matrix_io.h"

int
main(void)
{
    double **a;
    int n;
    scanf("%d", &n);


    a = malloc(sizeof(double *) * n);
    if (!a) {
        fprintf(stderr, "Memory allocation error\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        a[i] = malloc(sizeof(double) * (n + 1));
        if (!a[i]) {
            fprintf(stderr, "Memory allocation error\n");
            return 1;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    
    int ret = gauss_elim_wo_m_el(n, n + 1, a);

    printf("%d\n", ret);

    print_matrix(n, n + 1, a);

    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}
