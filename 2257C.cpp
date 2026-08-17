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
    int n;
    cin>>n;
    vector<int>p(n+1);
    for(int i=2;i<=n;++i)cin>>p[i];
    int m;
    cin>>m;
    vector<bool>d(n+1,0),h(n+1,0);
    for(int i=0;i<m;++i){
        int x;
        cin>>x;
        d[x]=1;
        h[x]=1;
    }
    for(int i=n;i>=2;--i){
        if(h[i])h[p[i]]=1;
    }
    vector<vector<int>>c(n+1);
    for(int i=2;i<=n;++i){
        if(h[i])c[p[i]].push_back(i);
    }
    vector<int>ans;
    for(int i=1;i<=n;++i){
        int s=c[i].size();
        if(d[i]){
            for(int j=0;j<s;j++)ans.push_back(c[i][j]);
        }else if(s>0){
            for(int j=0;j<s-1;j++)ans.push_back(c[i][j]);
        }
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();++i)cout<<ans[i]<<" ";
    cout<<"\n";
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