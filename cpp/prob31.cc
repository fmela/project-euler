#include <cstdio>

const int currency_units[] = { 1, 2, 5, 10, 20, 50, 100, 200 };
const int num_currency_units = sizeof(currency_units) / sizeof(currency_units[0]);

int count_ways_recursive(int target, int unit_index, int value) {
    if (unit_index == num_currency_units)
	return target == value;
    int num_ways = 0;
    while (value <= target) {
	num_ways += count_ways_recursive(target, unit_index + 1, value);
	value += currency_units[unit_index];
    }
    return num_ways;
}

int main() {
    printf("Ways to make 200p: %d\n", count_ways_recursive(200, 0, 0));
    return 0;
}
