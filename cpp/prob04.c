#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(int p);

int main(void)
{
    int max = 0;
    for (int i = 999; i >= 1; --i) {
	for (int j = 999; j >= 1; --j) {
	    const int p = i * j;
	    if (p > max && is_palindrome(p))
		max = p;
	}
    }
    printf("max: %d\n", max);
    return 0;
}

bool is_palindrome(int p)
{
    char buf[32];
    snprintf(buf, sizeof(buf), "%d", p);
    char *s = buf;
    char *e = buf + strlen(buf) - 1;
    while (s < e) {
	if (*s != *e)
	    return false;
	++s; --e;
    }
    printf("%d is a palindrome\n", p);
    return true;
}
