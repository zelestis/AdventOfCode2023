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

constexpr int N = 1;
bool debug = false;
struct Query {
    Query() : t{0}, d{0} {}
    Query(ll a, ll b) : t{a}, d{b} {}
    ll t, d;
};
Query qs[N];


// I used this for both part 1 & 2
int main() {
    if(!debug) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }

    string garbage;
    cin >> garbage;
    REP(i, 0, N) {
        cin >> qs[i].t;
    }
    cin >> garbage;
    REP(i, 0, N) {
        cin >> qs[i].d;
    }

    vi counts{};
    REP(i, 0, N) {
        ll cnt = 0;
        if(debug) cout << "Testing " << qs[i].t << " dist=" << qs[i].d << endl;
        REPe(j, 1, qs[i].t) {
            ll rem = qs[i].t - j;
            if(j * rem > qs[i].d) cnt++;
            if(debug) cout << "Remaining time = " << rem << " speed = " << j << " passes="
            << " Up to=" << rem * j << " "
            << (rem * j >= qs[i].d ? "true" : "false") << endl;
        }
        cout << "combinations = " << cnt << endl;
        if(cnt != 0) counts.PB(cnt);
    }

    ll ans = accumulate(begin(counts), end(counts), 1, multiplies<ll>{});
    if(counts.size() == 0) {
        cout << "0\n";
    } else {
        cout << ans << "\n";
    }

    return EXIT_SUCCESS;
}
