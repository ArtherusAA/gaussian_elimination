#include <stdio.h>
#include <math.h>

static const double eps = 1e-4;

int
main(void)
{
    double diff;
    scanf("%lf", &diff);
    if (fabs(diff) >= eps) {
        printf("-------------------------- Test Failed:\n");
        printf("Determinant is not correct, difference is %lf\n", diff);
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
