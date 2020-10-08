#include <stdio.h>
#include <math.h>

static const double eps = 1e-4;

int
main(void)
{
    int diff;
    scanf("%d", &diff);
    if (diff) {
        printf("-------------------------- Test Failed:\n");
        printf("Whether the matrix can be proccessed using gaussian elimination was not determined correctly\n");
        return 0;
    }
    double d;
    while (scanf("%lf", &d) > 0) {
        if (fabs(d) > eps) {
            printf("-------------------------- Test Failed:\n");
            printf("Difference: %lf\n", d);
            return 0;
        }
    }
    printf("-------------------------- OK\n");
    return 0;
}
