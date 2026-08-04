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
int ans=0;
int dfs(int node,vector<vector<int>>& adj,string& s) {
    if(adj[node].size()==0){
        if(s[node-1]=='W')return 1;
        return -1;
    }
    int c=0;
    if(s[node-1]=='W')c++;
    else c--;
    for(int child:adj[node]){
        c+=dfs(child,adj,s);
    }
    if(c==0)ans++;
    return c;
}

void solve() {
    int n;
    cin >> n;
    ans=0;
    vector<vector<int>>adj(n+1,vector<int>());
    for(int i=0;i<n-1;i++){
        int temp;
        cin>>temp;
        adj[temp].push_back(i+2);
    }
	string s;
    cin>>s;
    dfs(1,adj,s);
    cout<<ans<<"\n";
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