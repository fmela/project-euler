#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(unsigned input, unsigned base)
{
    char buf[128];
    char *e = buf - 1;
    do {
        *++e = input % base;
    } while (input /= base);
    char *s = buf;
    while (s < e)
        if (*s++ != *e--)
            return false;
    return true;
}

int main()
{
    unsigned sum = 0;
    for (unsigned i = 1; i < 1000000; ++i)
        if (is_palindrome(i, 10) && is_palindrome(i, 2))
            sum += i;
    printf("sum: %u\n", sum);
    return 0;
}
