#if !defined(__cplusplus)
# include <stdbool.h>
#endif

bool is_prime(unsigned n) {
    if (n <= 0)
	return false;
    if (n <= 2)
	return true;
    if (!(n & 1))
	return false;
    for (unsigned f = 3;; f += 2) {
	if (f * f >= n) {
	    if (f * f == n) {
		return false;
	    }
	    return true;
	}
	if (n % f == 0)
	    return false;
    }
}
