#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i, a, b) for(int i = a; i < b; i++)

bool debug = false;

int N = 730;
int graph[1 << 15][2];
int positions[1 << 15];

inline int pos(const string & str) {
    return (str[0]-'A') + ((str[1]-'A') * 26) + ((str[2]-'A') * 26 * 26);
}

int main() {
    string inst; cin >> inst;
    string from, tkn, left, right;
    int n = 0;
    REP(i, 0, N) {
        cin >> from >> tkn >> left >> right;
        ll sauce = pos(from);
        graph[sauce][0] = pos(left.substr(1, 3));
        graph[sauce][1] = pos(right.substr(0, 3));
        if(sauce % 26 == 0) positions[n++] = pos(from);
    }

    ll cnt = 1;
    REP(i, 0, n) {
        ll cpos = positions[i], cinst = 0;
        while(cpos % 26 != 25) {
            cpos = graph[cpos][inst[cinst%inst.size()] == 'L' ? 0 : 1];
            cinst++;
        }
        cnt = lcm(cnt, cinst);
    }
    printf("answer = %lld\n", cnt);
    cout << cnt << endl;

    return EXIT_SUCCESS;
}
