#include <bits/stdc++.h>
using namespace std;

vector<string> getMatches(const string &input, string reg_in) { // maybe put an lvalue ref on reg_in
  vector<string> found_matches{};
  regex re("(?=" + reg_in + ").");
  smatch m;

  sregex_iterator iter(input.begin(), input.end(), re);
  sregex_iterator end;

  while (iter != end) {
    found_matches.push_back(iter->str(1));
    ++iter;
  }

  return found_matches;
}
// usage
// auto matches = getMatches(tkn, "(one|two|three|four|five|six|seven|eight|nine|[0-9])");
// might require you to remove the re line - that's to allow overlaps.
// just replace it with re(reg_in)