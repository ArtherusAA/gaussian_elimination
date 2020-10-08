#include <stdio.h>
#include <stdlib.h>


int
main(void)
{
    double **a, **b;
    int n, m, answer_exists, target_answer_exists;
    scanf("%d%d", &n, &m);


    a = malloc(sizeof(double *) * n);
    if (!a) {
        fprintf(stderr, "Memory allocation error\n");
        return -1;
    }
    for (int i = 0; i < n; i++) {
        a[i] = malloc(sizeof(double) * (m));
        if (!a[i]) {
            fprintf(stderr, "Memory allocation error\n");
            return -1;
        }
    }

    b = malloc(sizeof(double *) * n);
    if (!b) {
        fprintf(stderr, "Memory allocation error\n");
        return -1;
    }
    for (int i = 0; i < n; i++) {
        b[i] = malloc(sizeof(double) * (m));
        if (!b[i]) {
            fprintf(stderr, "Memory allocation error\n");
            return -1;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    
    scanf("%d", &answer_exists);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%lf", &b[i][j]);
        }
    }

    
    scanf("%d", &target_answer_exists);

    printf("%d\n", target_answer_exists - answer_exists);

    for (int i = n; i < m; i++) {
        for (int j = 0; j < n; j++) {
            double res = 0;
            for (int k = 0; k < n; k++) {
                res += a[j][k] * b[k][i];
            }
            printf("%.9lf ", res - a[j][i]);
        }
        putchar('\n');
    }


    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    for (int i = 0; i < n; i++) {
        free(b[i]);
    }
    free(b);

    return 0;
}
