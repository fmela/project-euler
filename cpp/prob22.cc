#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    FILE *fp = fopen("../names.txt", "r");
    if (!fp) {
	fprintf(stderr, "Failed to open file.");
	exit(1);
    }

    vector<string> names;
    bool word = false;
    for (;;) {
	int c = fgetc(fp);
	if (c == EOF)
	    break;
	if (c == '"') {
	    if (word) {
		c = fgetc(fp);
		if (c == EOF || c == ',') {
		    word = false;
		    if (c == EOF)
			break;
		}
	    } else {
		names.push_back(string());
		word = true;
	    }
	    continue;
	}
	if (names.empty()) {
	    fprintf(stderr, "No string to append to!\n");
	    exit(1);
	}
	names.back() += (char)c;
    }
    fclose(fp);
    fp = NULL;
    if (word) {
	fprintf(stderr, "Stream stopped in the middle of a word!\n");
	exit(1);
    }
    printf("Loaded %zu words.\n", names.size());
    sort(names.begin(), names.end());
    long score_sum = 0;
    for (size_t i = 0; i < names.size(); ++i) {
	const string &name = names[i];
	long score = 0;
	for (size_t j = 0; j < name.size(); ++j)
	    score += name[j] - 'A' + 1;
	score_sum += score * (i + 1);
    }
    printf("Sum of scores: %ld\n", score_sum);

    return 0;
}
