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
    ll n, k;
    cin >> n >> k;
    string A, B;
    cin >> A >> B;
    ll onesA = 0, onesB = 0, onesC = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] == '1') onesA++;
        if (B[i] == '1') onesB++;
        if (A[i] != B[i]) onesC++;
    }
    ll valA = onesA * (n - onesA);
    ll valB = onesB * (n - onesB);
    ll valC = onesC * (n - onesC);
    ll N = (1LL << k) + 1; 
    ll countA, countB, countC;
    if (k % 2 == 1) {
        countA = N / 3;
        countB = N / 3;
        countC = N / 3;
    } else {
        countA = (N + 1) / 3;
        countB = (N + 1) / 3;
        countC = (N - 2) / 3;
    }
    ll ans = countA * valA + countB * valB + countC * valC;
    cout << ans << "\n";
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