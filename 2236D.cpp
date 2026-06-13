#include <bits/stdc++.h>
using namespace std;
template<typename A,typename B> ostream& operator<<(ostream& os,const pair<A,B>& p){return os<<'('<<p.first<<","<<p.second<<')';}
template<typename T_container,typename T=typename enable_if<!is_same<T_container,string>::value,typename T_container::value_type>::type> ostream& operator<<(ostream& os,const T_container& v){os<<'{';string sep;for(const T& x:v)os<<sep<<x,sep=", ";return os<<'}';}
void dbg_out(){cerr<<endl;}
template<typename Head,typename... Tail> void dbg_out(Head H,Tail... T){cerr<<' '<<H;dbg_out(T...);}
#ifdef LOCAL
#define dbg(...) cerr<<"("<<#__VA_ARGS__<<"):",dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(),(a).end()
const int MAX_N=1e5+5;
const ll MOD=1e9+7;
const ll INF=1e9;
const ld EPS=1e-9;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(all(a));
    vector<int> v,f;
    for(int x:a){
        if(v.empty()||v.back()!=x){
            v.push_back(x);
            f.push_back(1);
        }else f.back()++;
    }
    int m=v.size();
    vector<int> dp(m,0);
    int lost=0;
    int r=m-1;
    for(int i=m-1;i>=0;i--){
        while(r>i&&v[r]>v[i]+k){
            if(dp[r]==0)lost--;
            r--;
        }
        if(lost>0)dp[i]=1;
        else{
            if(f[i]%2==0)dp[i]=1;
            else dp[i]=0;
        }
        if(dp[i]==0)lost++;
    }
    bool ewin=false;
    for(int i=0;i<m;i++){
        if(dp[i]==1){
            ewin=true;
            break;
        }
    }
    if(ewin)cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tc=1;
    cin>>tc;
    for(int t=1;t<=tc;t++)solve();
    return 0;
}