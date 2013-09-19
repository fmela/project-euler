#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include "is_prime.h"

using namespace std;

int main() {
    unsigned max = 0;
    for (unsigned n = 2; n <= 9; ++n) {
	vector<char> characters;
	for (unsigned i = 1; i <= n; ++i)
	    characters.push_back('0' + i);
	do {
	    characters.push_back('\0');
	    unsigned value = strtoul(&characters[0], NULL, 10);
	    //	printf("%s: %u is %sprime.\n", &characters[0], value,
	    //		   is_prime(value) ? "" : "not ");
	    characters.pop_back();

	    if (is_prime(value) && max < value)
		max = value;
	} while (next_permutation(characters.begin(), characters.end()));
    }
    printf("%u\n", max);
    return 0;
}
