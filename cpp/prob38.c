#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

int num_digits(uint64_t x)
{
    if (x <= 1)
        return 1;
    return (int) ceil(log10(x));
}

bool is_pandigital(uint64_t x)
{
    // printf("num_digits(%lu)=%d\n", x, num_digits(x));
    if (x < 123456789 || x > 987654321)
        return false;
    int t[10] = { 0 };
    while (x) {
        int b = x % 10;
        if (b == 0 || t[b]++)
            return false;
        x /= 10;
    }
    for (int i = 1; i <= 9; ++i)
        if (!t[i])
            return false;
    return true;
}

uint64_t largest_pandigital_product(uint64_t base)
{
    for (uint64_t product = 0, answer = 0, n = 1; ; ++n) {
        const int product_digits = num_digits(product);
        const uint64_t next_addend = base * n;
        const int addend_digits = num_digits(next_addend);
        if (product_digits + addend_digits > 9)
            return answer;
        for (int i = 0; i < addend_digits; i++)
            product *= 10;
        product += next_addend;
        if (is_pandigital(product))
            answer = product;
    }
}

int main()
{
    assert(is_pandigital(123456789));
    assert(is_pandigital(312645897));
    assert(!is_pandigital(1234567890));
    assert(!is_pandigital(1234567891));
    assert(!is_pandigital(31264589));
    assert(!is_pandigital(31264583));
    assert(!is_pandigital(1));
    assert(!is_pandigital(2));
    assert(!is_pandigital(12));
    assert(!is_pandigital(123));
    assert(!is_pandigital(1234));
    assert(!is_pandigital(12345));
    assert(!is_pandigital(123456));
    assert(!is_pandigital(1234567));
    assert(!is_pandigital(12345678));
    assert(is_pandigital(123456789));

    uint64_t max = 0;
    for (uint64_t x = 1; x < 10000000000; ++x) { // FIXME runs for too long
        uint64_t p = largest_pandigital_product(x);
        if (max < p) {
            max = p;
            printf("new max: %lu\n", max);
        }
    }
    return 0;
}
