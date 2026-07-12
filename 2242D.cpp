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

int get_lcs(int i,int j,int n,int m,const vector<int>&pa,const vector<int>&pb,vector<vector<int>>&dp){
    if(i>=n-1||j>=m-1)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(pa[i]==pb[j])return dp[i][j]=1+get_lcs(i+1,j+1,n,m,pa,pb,dp);
    return dp[i][j]=max(get_lcs(i+1,j,n,m,pa,pb,dp),get_lcs(i,j+1,n,m,pa,pb,dp));
}

void solve() {
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    vector<int>pa(n),pb(m);
    pa[0]=(a[0]-'0')%10;
    pb[0]=(b[0]-'0')%10;
    for(int i=1;i<n;i++)pa[i]=(pa[i-1]+a[i]-'0')%10;
    for(int i=1;i<m;i++)pb[i]=(pb[i-1]+b[i]-'0')%10;
    if(pa[n-1]!=pb[m-1]){
        cout<<-1<<"\n";
        return;
    }
    vector<vector<int>>dp(n,vector<int>(m,-1));
    cout<<get_lcs(0,0,n,m,pa,pb,dp)+1<<"\n";
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