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
constexpr int N = 32;
//constexpr int N = 150;
string grid[N];
umap<ll, ll> real2comp{};
umap<ll, ll> comp2real{};

void gen_compression() {
    vi nums{};
    vi seeds{};
    vector<string> toParse = getMatches(grid[0], "[0-9]+", false);
    for(int i = 0; i < toParse.size(); i += 2) {
        nums.PB(stoll(toParse[i]) + stoll(toParse[i+1]));
    }
    int ind = 3;
    REP(i, 0, 7) {
        printf("begin %d\n", i);
        while(ind < N && grid[ind].length() > 4) {
            auto m = getMatches(grid[ind], "[0-9]+", false);
            nums.PB(stoll(m[0]));
            nums.PB(stoll(m[1]));
            nums.PB(stoll(m))
            cmap[real2comp[stoll(m[1])]] = pii(real2comp[stoll(m[0])], real2comp[stoll(m[2])]);
            printf("Raw in %lld -> {%lld %lld}\n",stoll(m[1]), stoll(m[0]), stoll(m[2]));
            printf("Add in %lld -> {%lld %lld}\n",real2comp[stoll(m[1])], real2comp[stoll(m[0])], real2comp[stoll(m[2])]);
            ind++;
        }
        ind += 2;
    }

    sort(begin(nums), end(nums));
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    int n = nums.size();
    REP(i, 0, n) {
        printf("%d -> %lld\n", i, nums[i]);
        real2comp[nums[i]] = i;
        comp2real[i] = nums[i];
    }
    printf("Max compressed is %d\n", n);
}

int main() {
    if(!debug) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }

    printf("alive0\n");
    for (auto & i : grid) getline(cin, i);
    gen_compression();
    printf("alive1\n");
    vi seeds{};
    vector<string> toParse = getMatches(grid[0], "[0-9]+", false);
    for(int i = 0; i < toParse.size(); i += 2) {
        ll val = real2comp[stoll(toParse[i])];
        ll clen = real2comp[stoll(toParse[i+1])];
        REP(j, 0, clen) {
            seeds.PB(val + i);
        }
    }
    sort(seeds.begin(), seeds.end());
    seeds.erase(unique(seeds.begin(), seeds.end()), seeds.end());
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
            cmap[real2comp[stoll(m[1])]] = pii(real2comp[stoll(m[0])], real2comp[stoll(m[2])]);
            printf("Raw in %lld -> {%lld %lld}\n",stoll(m[1]), stoll(m[0]), stoll(m[2]));
            printf("Add in %lld -> {%lld %lld}\n",real2comp[stoll(m[1])], real2comp[stoll(m[0])], real2comp[stoll(m[2])]);
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
            if(it != groups[i].begin() && (it->first != cval || it == groups[i].end) {
                it--;
            }
            if(it == groups[i].end()) {
                printf("Beyond the max, skipping\n");
                continue;
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

    cout << comp2real[lowestLocation] << endl;
    return EXIT_SUCCESS;
}
