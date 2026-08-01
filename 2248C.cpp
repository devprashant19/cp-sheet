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

ll f(int i,vector<ll>&dp,vector<int>&pref,vector<int>&a){
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        ll res=f(i-1,dp,pref,a)+1;
        int j=pref[a[i]];
        if(j!=0&&j<i){
            ll len=i-j+1;
            res=max(res,f(j-1,dp,pref,a)+len*len);
        }
        return dp[i]=res;
    };
void solve() {
    int n;
    cin>>n;
    vector<int>a(2*n+1);
    vector<int>pref(n+1,0);
    vector<ll>dp(2*n+1,-1);
    for(int i=1;i<=2*n;i++){
        cin>>a[i];
        if(pref[a[i]]==0)pref[a[i]]=i;
    }
    cout<<f(2*n,dp,pref,a)<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc=1;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        solve();
    }
}