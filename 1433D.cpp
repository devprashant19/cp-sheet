#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    int n;
    cin >> n;
    vector<int> gang(n + 1);
    for (int i = 1; i <= n; i++)cin >> gang[i];
    vector<array<int, 2>> edges;
    int val1 = 1, val2 = -1;
    for (int i = 2; i <= n; i++)
    {
        if (gang[i] != gang[1])
        {
            edges.push_back({1, i});
            val2 = i;
            break;
        }
    }
    if (val2 == -1)
    {
        cout << "NO\n";
        continue;
    }
    for (int i = 2; i <= n; i++)
    {
        if (i == val2)continue; 
        if (gang[i] != gang[val1])
        {
            edges.push_back({val1, i});
        }
        else
        {
            edges.push_back({val2, i});
        }
    }
    cout << "YES\n";
    for (auto &edge : edges)cout << edge[0] << " " << edge[1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}