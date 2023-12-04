#include <bits/stdc++.h>
#include "../regex_helpers.cpp"

using namespace std;

string fix1 = "...1234.....#543.#223$......";
string fix2 = "...TWONE...";

void test_addValueToMatch() {
    string test1 = fix1;
    auto test1_out = addValueToMatch(test1, "[0-9]+", 'a' - '0');
    if (test1_out != "...bcde.....#fed.#ccd$......") {
        cout << "FAIL addValueToMatch" << endl;
    } else {
        cout << "PASS addValueToMatch" << endl;
    }
}

void test_getMatches() {
    string test2 = fix1;
    auto test2_out = getMatches(test2, "[0-9]+", false);
    if (stoi(test2_out[0]) != 1234) {
        cout << "FAIL getMatches1" << endl;
    } else if (stoi(test2_out[1]) != 543) {
        cout << "FAIL getMatches2" << endl;
    } else if (stoi(test2_out[2]) != 223) {
        cout << "FAIL getMatches3" << endl;
    } else {
        cout << "PASS getMatches_t1" << endl;
    }
}

void test_getMatchesOverlap() {
    string test3 = fix2;
    auto test3_out = getMatches(test3, "(TWO|ONE)", true);
    if (test3_out.size() != 2) {
        cout << "FAIL getMatch_t2 size" << endl;
    } else if (test3_out[0] != "TWO") {
        cout << "FAIL getMatch_t2 1" << endl;
    } else if (test3_out[1] != "ONE") {
        cout << "FAIL getMatch_t2 2" << endl;
    } else {
        cout << "PASS getMatch_t2" << endl;
    }
}

void test_regexReplace() {
    string test = fix1;
    auto out = regReplace(test, "[0-9]", "A");
    if (out != "...AAAA.....#AAA.#AAA$......") {
        cout << "FAIL test_regexReplace" << endl;
    } else {
        cout << "PASS test_regexReplace" << endl;
    }
}

void test_regexReplace_2() {
    string test = fix1;
    auto out = regReplace(test, "[0-9]+", "A");
    if (out != "...A.....#A.#A$......") {
        cout << "FAIL test_regexReplace_2" << endl;
    } else {
        cout << "PASS test_regexReplace_2" << endl;
    }
}

int main() {
    test_addValueToMatch();
    test_getMatches();
    test_getMatchesOverlap();
    test_regexReplace();
    test_regexReplace_2();
}