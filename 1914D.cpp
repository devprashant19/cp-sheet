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

vector<int> findMax3(vector<int> &arr) {
	vector<pair<int, int>> tmp(arr.size());
	for (int i = 0; i < tmp.size(); i++) {
		tmp[i].first = arr[i];
		tmp[i].second = i;
	}
	sort(tmp.rbegin(), tmp.rend());
	vector<int> ans(3);
	for (int i = 0; i < 3; i++)ans[i] = tmp[i].second;
	return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> b(n);
    for(int i=0;i<n;i++)cin>>b[i];
    vector<int> c(n);
    for(int i=0;i<n;i++)cin>>c[i];
    vector<int>maxa=findMax3(a);
    vector<int>maxb=findMax3(b);
    vector<int>maxc=findMax3(c);
    int ans=INT_MIN;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                int x = maxa[i], y = maxb[j], z = maxc[k];
                if ((x == y) or (y == z) or (z == x))continue;
                ans = max(ans, a[x] + b[y] + c[z]);
            }
        }
    }
    cout<<ans<<"\n";

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