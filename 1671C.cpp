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

int bsearch(ll val, ll idx, ll x){
    ll l=0,r=1e9;
    ll ans=0;
    while(l<=r){
        ll mid=l+(r-l)/2;
        if(val+(1LL*(idx+1)*(mid-1))<=x){
            ans=mid;
            l=mid+1;
        }else r=mid-1;
    }
    return ans;
}

void solve() {
    ll n,x;
    cin>>n>>x;
    vector<ll>a(n);
    vector<ll>pref(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(), a.end());
    pref[0]=a[0];
    for(int i=1;i<n;i++)pref[i]=pref[i-1]+a[i];
    ll packs=0;
    for(ll i=0;i<n;i++){
        packs+=bsearch(pref[i],i,x);
    }
    cout<<packs<<"\n";
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