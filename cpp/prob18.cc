#include <stdio.h>

int
main(void)
{
#if 1
#define N 15
    int triangle[N][N] = {
	{ 75,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, },
	{ 95, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, },
	{ 17, 47, 82,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, },
	{ 18, 35, 87, 10,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, },
	{ 20,  4, 82, 47, 65,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, },
	{ 19,  1, 23, 75,  3, 34,  0,  0,  0,  0,  0,  0,  0,  0,  0, },
	{ 88,  2, 77, 73,  7, 63, 67,  0,  0,  0,  0,  0,  0,  0,  0, },
	{ 99, 65,  4, 28,  6, 16, 70, 92,  0,  0,  0,  0,  0,  0,  0, },
	{ 41, 41, 26, 56, 83, 40, 80, 70, 33,  0,  0,  0,  0,  0,  0, },
	{ 41, 48, 72, 33, 47, 32, 37, 16, 94, 29,  0,  0,  0,  0,  0, },
	{ 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,  0,  0,  0,  0, },
	{ 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,  0,  0,  0, },
	{ 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,  0,  0, },
	{ 63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,  0, },
	{  4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23, },
    };
#else
#define N 4
    int triangle[N][N] = {
	{ 3, 0, 0, 0, },
	{ 7, 4, 0, 0, },
	{ 2, 4, 6, 0, },
	{ 8, 5, 9, 3, },
    };
#endif

#if 0
    int max_sum = 0;
    int position[N] = { 0 };
    for (;;) {
	/* Compute sum and update max if new sum exceeds it. */
	int sum = 0;
	for (int row = 0; row < N; ++row) {
	    sum += triangle[row][position[row]];
	}
	if (max_sum < sum) {
	    max_sum = sum;
	    /* Print the updated path. */
	    printf("sum[");
	    for (int row = 0; row < N; ++row)
		printf("%2d%c", triangle[row][row[position]],
		       row+1 == N ? ']' : ',');
	    printf(" = %d\n", sum);
	}
	/* Update to next position, starting at the bottom. */
	bool found = false;
	for (int row = N - 1; row > 0; --row) {
	    if (position[row]+1 < N && triangle[position[row]+1] != 0 &&
		position[row-1]+1 >= position[row]+1) {
		++position[row];
		for (int i = row + 1; i < N; ++i) {
		    position[i] = position[row];
		}
		found = true;
		break;
	    }
	}
	if (!found)
	    break;
    }
    printf("%d\n", max_sum);
#else
    for (int row = N - 2; row >= 0; --row) {
	for (int i = 0; i <= row; ++i) {
	    if (triangle[row+1][i] > triangle[row+1][i+1])
		triangle[row][i] += triangle[row+1][i];
	    else
		triangle[row][i] += triangle[row+1][i+1];
	}
    }
    printf("%d\n", triangle[0][0]);
#endif
    return 0;
}
