#include <bits/stdc++.h>
#include "../regex_helpers.cpp"
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef pair<ll, ll> pii;
#define REP(i, a, b) for(ll i = a; i < b; i++)
#define REPe(i, a, b) for(ll i = a; i <= b; i++)
#define REPr(i, a, b) for(ll i = a; i >= b; i--)
#define F first
#define S second
#define PB push_back
template <class T>          using uset = unordered_set<T>;
template <class T, class U> using umap = unordered_map<T, U>;
constexpr ll INF = 1e9;
constexpr ll MOD = 1000000007;
constexpr ll INF2 = (ll)1 << 47;

constexpr ll N = 197;
bool debug = false;

string grid[N];


int main() {
    if(!debug) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    REP(i, 0, N) getline(cin, grid[i]);

    ll total = 0;
    REP(i, 0, N) {
        auto cs = grid[i];
        auto output = splitChar(cs, '|');
        auto out1 = splitChar(output[0], ':')[1];
        auto out2 = output[1];
        cout << "Part 1 " << out1 << endl;
        cout << "Part 2 " << out2 << endl << endl;

        uset<ll> win_nums;
        for(auto & v : getMatches(out1, "[0-9]+", false)) {
            win_nums.insert(stoi(v));
        }
        ll cnt = 0;
        for(auto & v : getMatches(out2, "[0-9]+", false)) {
            cnt += win_nums.find(stoi(v)) != win_nums.end();
        }
        if(cnt > 0) total += pow(2, cnt-1);
        cout << "wins" << cnt << endl;
    }
    cout << "total = " << total << endl;

    return EXIT_SUCCESS;
}
