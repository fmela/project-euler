#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    for (int i = 20; ; ++i) {
	for (int j = 2; j <= 20; ++j) {
	    if (i % j)
		break;
	    if (j == 20) {
		printf("%d\n", i);
		exit(0);
	    }
	}
    }
    return 0;
}
