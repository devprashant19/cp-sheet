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
    ll x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    auto check = [&](ll D) {
        ll cur_L = -1, cur_R = -1;
        ll invalid_count = 0;
        for (int i = 0; i < n; i++) {
            ll L = a[i] - D + 1;
            ll R = a[i] + D - 1;
            L = max(0LL, L);
            R = min(x, R);
            if (L <= R) {
                if (cur_R < L) {
                    if (cur_L != -1) invalid_count += cur_R - cur_L + 1;
                    cur_L = L;
                    cur_R = R;
                } else {
                    cur_R = max(cur_R, R);
                }
            }
        }
        if (cur_L != -1) invalid_count += cur_R - cur_L + 1;
        return (x + 1 - invalid_count) >= k;
    };
    
    ll low = 0, high = x;
    ll ans_D = 0;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(mid)) {
            ans_D = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    ll cur_L = -1, cur_R = -1;
    vector<pair<ll, ll>> merged;
    for (int i = 0; i < n; i++) {
        ll L = max(0LL, a[i] - ans_D + 1);
        ll R = min(x, a[i] + ans_D - 1);
        if (L <= R) {
            if (cur_R < L) {
                if (cur_L != -1) merged.push_back({cur_L, cur_R});
                cur_L = L;
                cur_R = R;
            } else {
                cur_R = max(cur_R, R);
            }
        }
    }
    if (cur_L != -1) merged.push_back({cur_L, cur_R});
    
    vector<pair<ll, ll>> valid;
    ll last = 0;
    for (auto p : merged) {
        if (p.first > last) {
            valid.push_back({last, p.first - 1});
        }
        last = p.second + 1;
    }
    if (last <= x) {
        valid.push_back({last, x});
    }
    
    vector<ll> ans;
    for (auto p : valid) {
        for (ll v = p.first; v <= p.second && ans.size() < (size_t)k; v++) {
            ans.push_back(v);
        }
        if (ans.size() == (size_t)k) break;
    }
    for (int i = 0; i < k; i++) {
        cout << ans[i] << (i == k - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}