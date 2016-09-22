#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

// Check if X * YYYY = ZZZZ
// Check if XX * YYY = ZZZZ
// Check if XXX * YY = ZZZZ
// Check if XXXX * Y = ZZZZ
void find_product_equations(const char* digits, set<unsigned>* products)
{
    for (unsigned x_length = 1; x_length <= 4; ++x_length) {
        const unsigned y_length = 5 - x_length;

        unsigned x = 0;
        for (unsigned i = 0; i < x_length; ++i)
            x = x * 10 + (digits[i] - '0');

        unsigned y = 0;
        for (unsigned i = 0; i < y_length; ++i)
            y = y * 10 + (digits[x_length + i] - '0');

        unsigned z = 0;
        for (unsigned i = 0; i < 4; ++i)
            z = z * 10 + (digits[x_length + y_length + i] - '0');

        if (x * y == z) {
            printf("%s: %u * %u %s %u\n", digits, x, y, (x * y == z) ? "==" : "!=", z);
            products->insert(z);
        }
    }
}

int main()
{
    char digits[] = "123456789";
    set<unsigned> products;
    do {
	find_product_equations(digits, &products);
    } while (next_permutation(digits, digits+9));
    printf("Sum: %lu\n", std::accumulate(products.begin(), products.end(), 0UL));
    return 0;
}
