#include <stdio.h>

// compute (b ^ p) mod m
unsigned long pmod(unsigned long b, unsigned long p, unsigned long m)
{
    unsigned long x = 1;
    while (p--)
        x = (x * b) % m;
    return x;
}

int main()
{
    const unsigned long m = 10000000000;

    unsigned long sum = 0;
    for (unsigned long i = 1; i <= 1000; ++i) {
        sum = (sum + pmod(i, i, m)) % m;
    }
    printf("sum: %lu\n", sum);
    return 0;
}
