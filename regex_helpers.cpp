#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

vs getMatches(
        const string &input, const string &reg_in, bool overlap = true
) { // maybe put a lvalue ref on reg_in
    vs found_matches{};
    regex re;
    if (overlap) {
        re = regex("(?=" + reg_in + ").");
    } else {
        re = regex(reg_in);
    }
    smatch m;

    sregex_iterator iter(input.begin(), input.end(), re);
    sregex_iterator end;

    while (iter != end) {
        if (overlap) {
            found_matches.push_back(iter->str(1));
        } else {
            found_matches.push_back(iter->str());
        }
        ++iter;
    }

    return found_matches;
}
// usage
// auto matches = getMatches(tkn, "(one|two|three|four|five|six|seven|eight|nine|[0-9])");
// might require you to remove the re line - that's to allow overlaps.
// just replace it with re(reg_in)

string regReplace(const string &input, const string &reg_in, const string &replace) {
    regex reg(reg_in);
    return regex_replace(input, reg, replace);
}

string addValueToMatch(const string &input, const string &regexPattern, const int valueToAdd) {
    regex re(regexPattern);
    sregex_iterator iter(input.begin(), input.end(), re);
    sregex_iterator end;
    string result = input;
    while (iter != end) {
        smatch match = *iter;
        size_t matchPos = match.position();
        for (size_t i = 0; i < match.length(); ++i) {
            result[matchPos + i] += valueToAdd; // NOLINT(cppcoreguidelines-narrowing-conversions)
        }
        ++iter;
    }
    return result;
}

vs splitChar(const string &input, char reg_in) {
    stringstream ss(input);
    vs ans{};
    string segment;

    while (getline(ss, segment, reg_in)) {
        if(segment.empty()) continue;
        ans.push_back(segment);
    }
    return ans;
}

vs resplit(const string & input, const string & reg_in) {
    vs ans{};
    regex rgx(reg_in);
    sregex_token_iterator iter(input.begin(), input.end(), rgx, -1);
    sregex_token_iterator end;
    for (; iter != end; ++iter) {
        if(iter->length() == 0) continue;
        if(*iter == reg_in) continue;
        ans.push_back(*iter);
    }
    return ans;
}