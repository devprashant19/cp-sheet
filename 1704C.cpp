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
    ll n,m;
    cin>>n>>m;
    vector<ll>a(m);
    for(int i=0;i<m;i++)cin>>a[i];
    sort(a.begin(),a.end());
    vector<ll>b;
    ll l=-1;
    for(int i=1;i<m;i++){
        ll gap=a[i]-a[i-1]-1;
        if(gap>0)b.push_back(gap);
    }
    ll gap_end=(n-a[m-1])+(a[0]-1);
    if(gap_end>0)b.push_back(gap_end);
    sort(b.rbegin(),b.rend());
    ll ans=0,days=0;
    for(int i=0;i<b.size();i++){
        ll cgap=b[i]-days*2;
        if(cgap>0){
            ans++;
            cgap-=2;
            if(cgap>0)ans+=cgap;
            days+=2;
        }
    }
    cout<<n-ans<<"\n";
    return;
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