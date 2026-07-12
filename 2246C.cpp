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
ll binpow(ll base, ll exp) {
    ll res=1;
    base%=MOD;
    while(exp>0) {
        if(exp%2==1)res=(res*base)%MOD;
        base=(base*base)%MOD;
        exp/=2;
    }
    return res;
}

void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    ll ones=0;
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x>=0)mpp[x]++;
        else ones++;
        a[i]=x;
    }
    ll vale=(ones==0)?1:binpow(2,ones-1);
    ll valo=(ones==0)?0:binpow(2,ones-1);
    ll val=1;
    for(auto x:mpp){
        val=(val*binpow(2,x.second-1))%MOD;
    }
    ll c=0;
    for(auto x:mpp){
        if(mpp.count(x.first+1))c++;
    }
    ll w1=(vale*val)%MOD;
    ll w2=((valo*c)%MOD*val)%MOD;
    ll cnt=(w1+w2)%MOD;
    cout<<cnt<<"\n";
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