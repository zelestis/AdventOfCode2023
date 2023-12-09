#include <bits/stdc++.h>
#include "../regex_helpers.cpp"
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef pair<ll, ll> pii;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define REPe(i, a, b) for(int i = a; i <= b; i++)
#define REPr(i, a, b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define PB push_back
template <class T>          using uset = unordered_set<T>;
template <class T, class U> using umap = unordered_map<T, U>;
constexpr int INF = 1e9;
constexpr int MOD = 1000000007;
constexpr ll INF2 = (ll)1 << 47;

bool debug = false;

ll N = 730;
vi graph[1 << 15];
ll positions[1 << 15];

ll pos(const string & str) {
    printf("pos of %s = ", str.c_str());
    ll val =  ((str[0]-'A') * 26 * 26) + ((str[1]-'A') * 26) + ((str[2]-'A'));
    printf("%lld\n", val);
    return val;
}

string trev(ll val) {
    ll a = val % 26;
    val /= 26;
    ll b = val % 26;
    val /= 26;
    ll c = val;
    string g;
    printf(" = %lld, %lld, %lld\n", a, b, c);
    g += a + 'A';
    g += b + 'A';
    g += c + 'A';
    return g;
}


int main() {
    string inst; cin >> inst;
    string from, tkn, left, right;
    int n = 0;
    REP(i, 0, N) {
        cin >> from >> tkn >> left >> right;
        printf("from=%s, tkn=%s, left=%s, right=%s\n",
            from.c_str(),
            tkn.c_str(),
            left.c_str(),
            right.c_str()
        );
        ll sauce = pos(from);
        graph[sauce].PB(pos(left.substr(1, 3)));
        graph[sauce].PB(pos(right.substr(0, 3)));

        if(sauce % 26 == 0) positions[n++] = pos(from);
    }

    ll cnt = 1;
    REP(i, 0, n) {
        ll cpos = positions[i], cinst = 0;
        while(cpos % 26 != 25) {
            cpos = graph[cpos][inst[cinst%inst.size()] == 'L' ? 0 : 1];
            cinst++;
        }
        printf("%lld -> cinst=%lld\n", positions[i], cinst);
        cnt = lcm(cnt, cinst);
    }
    printf("answer = %lld\n", cnt);
    cout << cnt << endl;

    return EXIT_SUCCESS;
}
