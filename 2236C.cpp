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

void seqq(ll u, ll x, ll cur, map<ll, ll>& smap) {
    if (smap.count(u) && smap[u] <= cur)return;
    smap[u] = cur;
    if (u == 0) return;
    seqq(u / x, x, cur + 1, smap);
    if (u % x != 0) {
        ll rem = u % x;
        ll req = x - rem;
        seqq((u + req) / x, x, cur + req + 1, smap);
    }
}

void solve() {
    ll a, b, x;
    cin >> a >> b >> x;
    map<ll, ll> sa, sb;
    seqq(a, x, 0, sa);
    seqq(b, x, 0, sb);
    ll total = -1;
    for (auto it : sa) {
        ll va = it.first;
        ll ops_a = it.second;
        for (auto it2 : sb) {
            ll vb = it2.first;
            ll ops_b = it2.second;
            ll cur = ops_a + ops_b + abs(va - vb);
            if (total == -1 || cur < total) {
                total = cur;
            }
        }
    }
    cout << total << "\n";
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