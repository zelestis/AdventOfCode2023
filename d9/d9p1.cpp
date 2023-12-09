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

constexpr ll N = 200;
ll val(vi & vals) {
    if(all_of(begin(vals), end(vals), [](int a){return a == 0;})) return 0;
    int n = vals.size();
    vi dif{};
    REP(i, 1, n) {
        dif.PB(vals[i] - vals[i-1]);
    }
    return vals[n-1] + val(dif);
}

int main() {
    if(!debug) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }

	ll t = 0;
    string tkn;
    REP(i, 0, N) {
        getline(cin, tkn);
        auto str = getMatches(tkn, "-?[0-9]+", false);
        vi c{}; for(auto & s : str) {
            printf("%s\n", s.c_str());
            c.PB(stol(s));
        }
        t += val(c);
    }
    cout << t << endl;



    return EXIT_SUCCESS;
}
