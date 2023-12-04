#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> spelledOutDigits = {
        {"one", 1}, {"two", 2},   {"three", 3}, {"four", 4}, {"five", 5},
        {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"1", 1},
        {"2", 2},   {"3", 3},     {"4", 4},     {"5", 5},    {"6", 6},
        {"7", 7},   {"8", 8},     {"9", 9},
};

int main() {
    string tkn;
    int tv = 0;
    regex re("(?=(one|two|three|four|five|six|seven|eight|nine|[0-9])).");
    smatch m;
    for(int i = 0; i < 1000; i++) {
        cin >> tkn;
        sregex_iterator iter(tkn.begin(), tkn.end(), re);
        sregex_iterator end;
        int firstOccurrence = -1, lastOccurrence = -1;
        printf("%s\n", tkn.c_str());

        while (iter != end) {
            smatch cmatch = *iter;
            if(firstOccurrence == -1) {
                firstOccurrence = spelledOutDigits[cmatch.str(1)];
            }
            lastOccurrence = spelledOutDigits[cmatch.str(1)];
            ++iter;
        }
        printf("\t%d, %d\n", firstOccurrence, lastOccurrence);
        tv += 10 * firstOccurrence + lastOccurrence;
    }
    printf("%d\n", tv);

    return EXIT_SUCCESS;
}
