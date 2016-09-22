#include <assert.h>
#include <stdio.h>
#include <math.h>

int num_right_triangle_solutions(int p)
{
    int n = 0;
    for (int a = 1; a < p; ++a) {
        for (int b = 1; b < p - a; ++b) {
            int c = p - a - b;
            assert(c > 0);
            if (a * a + b * b == c * c) {
                printf("%d: %d^2 + %d^2 = %d^2\n", p, a, b, c);
                n++;
            }
        }
    }
    return n;
}

int main()
{
    int max_solutions = 0, max_p = 0;
    for (int p = 3; p <= 1000; ++p) {
        int solutions = num_right_triangle_solutions(p);
        if (max_solutions < solutions)
            max_solutions = solutions, max_p = p;
    }
    printf("p=%d maximizes solutions (%d)\n", max_p, max_solutions);
    return 0;
}
