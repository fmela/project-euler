unsigned sum_of_proper_divisors(unsigned n) {
    unsigned sum = 1;
    for (unsigned factor = 2; factor * factor <= n; ++factor) {
	if (n % factor == 0) {
	    if (factor * factor == n)
		sum += factor;
	    else
		sum += factor + (n / factor);
	}
    }
    return sum;
}
