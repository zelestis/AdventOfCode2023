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

constexpr ll N = 1000;
//constexpr ll N = 5;
struct hand {
    string c;
    ll b, r, w;
};

int lu[256];
hand hv[N];

umap<char, ll> worth{
        {'A' , 1}, {'K', 2}, {'Q', 3}, {'J', 100}, {'T', 5}
};

ll solve(const string &w) {
    memset(lu, 0, sizeof(lu));
    ll js = 0;
    for (auto &c: w) if (c != 'J') lu[c]++;
    for (auto &c: w) if (c == 'J') js++;
    sort(begin(lu), end(lu), greater<int>{});
    if (lu[0] + js > 5) printf("%lld", lu[0] + js);
    if (lu[0] + js == 5) {
        return 10;
    }
    if (lu[0] + js == 4) {
        return 9;
    }
    // so now it's impossible for js >= 3
    // if js == 2, only [1, 1] is possible. with 2 we would've made 4
    // if js == 1, then [2, 2] -> [3, 2]
    //                  [2, 1] -> [3, 1]
    //                  [1, 1] -> [2, 1]
    if (js == 2) return 7;
    if (js == 1) {
        if (lu[0] == 2 && lu[1] == 2) return 8;
        if (lu[0] + 1 == 3) return 7;
        return 5;
    }

    if (lu[0] == 3 && lu[1] == 2) return 8;
    if (lu[0] == 3) return 7;
    if (lu[0] == 2 && lu[1] == 2) return 6;
    if (lu[0] == 2) return 5;
    return 4;
}

int main() {
    if(!debug) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    REPe(i, 2, 9) {
        printf("%d -> %d\n", i, 17-i);
        worth[i+'0'] = 17-i;
    }

    REP(i, 0, N) {
        cin >> hv[i].c >> hv[i].b;
        hv[i].w = solve(hv[i].c);
    }
    sort(begin(hv), end(hv), [](hand & a, hand & b){
        if(a.w == b.w) {
            REP(i, 0, 5) {
                if(a.c[i] == b.c[i]) continue;
                return worth[a.c[i]] > worth[b.c[i]];
            }
        }
        return a.w < b.w;
    });

    printf("Sorted\n");
    ll tot = 0;
    REP(i, 0,N) {
        cout << hv[i].w << " = " << hv[i].c << " -> " << (i+1) << " * " << hv[i].b << endl;
        tot += (i+1) * hv[i].b;
    }
    cout << "total = " << tot << endl;

    return EXIT_SUCCESS;
}
