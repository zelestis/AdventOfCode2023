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
constexpr int N = 150;
string grid[N];

int main() {
    if(!debug) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }

    printf("alive0\n");
    for (auto & i : grid) getline(cin, i);

    printf("alive1\n");
    vi seeds{};
    for(const string & v : getMatches(grid[0], "[0-9]+", false)) {
        printf("stolld %s", v.c_str());
        seeds.PB(stoll(v));
    }
    printf("alive 1\n");
    int ind = 3;
    printf("alive 2\n");
    vector<map<ll, pii>> groups(7, map<ll, pii>{});
    printf("alive 3\n");
    REP(i, 0, 7) {
        printf("begin %d\n", i);
        auto & cmap = groups[i];
        while(ind < N && grid[ind].length() > 4) {
            printf("Parsing %s\n", grid[ind].c_str());
            auto m = getMatches(grid[ind], "[0-9]+", false);
            cmap[stoll(m[1])] = pii(stoll(m[0]), stoll(m[2]));
            ind++;
        }
        ind += 2;
    }
    printf("alive 2\n");

    ll lowestLocation = (ll)1 << 47;
    for(auto & s : seeds) {
        ll cval = s;
        printf("Starting %lld\n", cval);
        REP(i, 0, 7) {
            auto it = groups[i].lower_bound(cval);
            if(it == groups[i].end()) {
                printf("Beyond the max, skipping\n");
                continue;
            }
            if(it != groups[i].begin() && it->first != cval) {
                it--;
            }
            ll lower = it->F;
            ll upper = it->F + it->S.S;
            printf("On {%lld [%lld %lld]} went from %lld to ", it->F, lower, upper, cval);
            if(lower <= cval && cval < upper) {
                cval = cval + (it->S.F  - it->F);
            }
            printf("to %lld\n", cval);
        }
        printf("Location = %lld\n", cval);
        lowestLocation = min(cval, lowestLocation);
    }

    cout << lowestLocation << endl;
    return EXIT_SUCCESS;
}
