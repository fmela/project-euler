#include <algorithm>
#include <cstdio>

int main() {
    char digits[] = "0123456789";

    int num = 0;
    do {
	if (++num == 1000000) {
	    printf("%s\n", digits);
	    break;
	}
    } while (std::next_permutation(digits, digits+10));
    return 0;
}
