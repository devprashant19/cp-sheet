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
    ll n,q;
    cin>>n>>q;
    vector<pair<ll,ll>>a(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        a[i]={x, 0};
        sum+=x;
    }
    ll curr_time=0;
    ll last2time=0;
    ll last2val=0;
    while(q--){
        curr_time++;
        ll t;
        cin>>t;
        if(t==1){
            ll i,val;
            cin>>i>>val;
            i--;
            ll old_val=a[i].first;
            if(a[i].second<last2time)old_val=last2val;
            sum+=val-old_val;
            a[i]={val, curr_time};
        }else if(t==2){
            ll val;
            cin>>val;
            sum=n*val;
            last2time=curr_time;
            last2val=val;
        }
        cout<<sum<<"\n";
    }   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}