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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> last_pos(k + 1, -1);
    vector<int> max_gap(k + 1, 0);
    vector<int> second_max_gap(k + 1, 0);
    auto update_gaps = [&](int color, int gap) {
        if (gap >= max_gap[color]) {
            second_max_gap[color] = max_gap[color];
            max_gap[color] = gap;
        } else if (gap > second_max_gap[color]) {
            second_max_gap[color] = gap;
        }
    };
    for (int i = 0; i < n; i++) {
        int color = a[i];
        int gap = i - last_pos[color] - 1;
        update_gaps(color, gap);
        last_pos[color] = i;
    }
    for (int color = 1; color <= k; color++) {
        int gap = n - last_pos[color] - 1;
        update_gaps(color, gap);
    }
    int ans = INF;
    for (int color = 1; color <= k; color++) {
        int current_max_gap = max(second_max_gap[color], max_gap[color] / 2);
        ans = min(ans, current_max_gap);
    }
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