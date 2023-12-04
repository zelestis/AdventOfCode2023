#include <bits/stdc++.h>
#include "../regex_helpers.cpp"

using namespace std;

string fix1 = "...1234.....#543.#223$......";
string fix2 = "...TWONE...";
string fix3 = "A | B";

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

void test_charSplit() {
    auto out = splitChar(fix1, '2');
    if (out[0] != "...1") {
        cout << "FAIL test_charSplit 0" << endl;
    } else if (out[1] != "34.....#543.#") {
        cout << "FAIL test_charSplit 1" << endl;
    } else if (out[2] != "3$......") {
        cout << "FAIL test_charSplit 2" << endl;
    } else {
        cout << "PASS test_charSplit" << endl;
    }
}

void test_resplit() {
    auto out = resplit(fix1, "[0-9]+");
    if (out[0] != "...") {
        cout << "FAIL test_resplit a0" << endl;
    } else if (out[1] != ".....#") {
        cout << "FAIL test_resplit a1" << endl;
    } else if (out[2] != ".#") {
        cout << "FAIL test_resplit a2" << endl;
    } else if (out[3] != "$......") {
        cout << "FAIL test_resplit a3" << endl;
    } else {
        cout << "PASS test_resplit a" << endl;
    }
}

void test_spltis() {
    // Make sure you escape special characters
    auto out1 = resplit(fix3, "\\|");
    auto out2 = splitChar(fix3, '|');
    if (out1.size() != out2.size()) {
        cout << "FAIL test_spltis length" << endl;
    } else if (out1[0] != out2[0]) {
        cout << "FAIL test_spltis 0" << endl;
    } else if (out1[1] != out2[1]) {
        cout << "FAIL test_spltis 1" << endl;
    } else {
        cout << "PASS test_spltis" << endl;
    }
}

void test_resplit2() {
    // Make sure you escape special characters
    auto out1 = resplit(fix2, "TWONE");
    if(out1[0] != "..." && out1[1] != "...") {
        cout << "FAIL test_resplit2" << endl;
    } else {
        cout << "PASS test_resplit2" << endl;
    }
}

int main() {
    test_addValueToMatch();
    test_getMatches();
    test_getMatchesOverlap();
    test_regexReplace();
    test_regexReplace_2();
    test_charSplit();
    test_resplit();
    test_spltis();
    test_resplit2();
}