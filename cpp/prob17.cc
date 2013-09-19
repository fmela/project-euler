#include <string>
#include <cstdio>
#include <cassert>

using std::string;

const char *ones_to_word[] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
};

#define NUM_ONES    (sizeof(ones_to_word) / sizeof(ones_to_word[0]))

const char *tens_to_word[] = {
    "zero",
    "ten",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety",
};
#define NUM_TENS    (sizeof(tens_to_word) / sizeof(tens_to_word[0]))

string number_to_string(int number) {
    string result;
    if (number < 0) {
	result = "negative";
	number = -number;
    }
    if (number >= 1000) {
	result = number_to_string(number/1000) + " thousand";
	number = number % 1000;
    }
    if (number >= 100) {
	if (!result.empty())
	    result += " ";
	result += number_to_string(number/100) + " hundred";
	number = number % 100;
    }
    if (number >= (int)NUM_ONES) {
	if (!result.empty())
	    result += " and ";
	assert(number/10 < (int)NUM_TENS);
	result += tens_to_word[number/10];
	number = number % 10;
	if (number) {
	    result += '-';
	    result += ones_to_word[number];
	    number = 0;
	}
    }
    assert(number < (int)NUM_ONES);
    if (result.empty()) {
	result = ones_to_word[number];
    } else if (number) {
	result += " and ";
	result += ones_to_word[number];
    }
    return result;
}

int
main(void) {
    int sum = 0;
    for (int i = 1; i <= 1000; ++i) {
	string s = number_to_string(i);
	printf("%d: %s\n", i, s.c_str());
	for (unsigned j = 0; j < s.size(); ++j) {
	    if (s[j] != ' ' && s[j] != '-')
		++sum;
	}
    }
    printf("letters used: %d\n", sum);
    return 0;
}
