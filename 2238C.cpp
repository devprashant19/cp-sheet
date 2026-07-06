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

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

vector<int> g[MAX_N];
int up[MAX_N][20];
int dep[MAX_N];
vector<int> nodes[MAX_N];

void dfs(int v, int p) {
    nodes[dep[v]].push_back(v);
    up[v][0]=p;
    for(int i=1;i<20;i++){
        up[v][i]=up[up[v][i-1]][i-1];
    }
    for(int u:g[v]){
        if(u!=p){
            dep[u]=dep[v]+1;
            dfs(u,v);
        }
    }
}

int get_lca(int u, int v) {
    if(dep[u]<dep[v])swap(u,v);
    int diff=dep[u]-dep[v];
    for(int i=0;i<20;i++){
        if((diff>>i)&1)u=up[u][i];
    }
    if(u==v)return u;
    for(int i=19;i>=0;i--){
        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}

void solve() {
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        g[i].clear();
        nodes[i].clear();
        dep[i]=0;
    }
    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        g[p].push_back(i);
    }
    dep[1]=0;
    dfs(1,1);
    ll ans=0;
    for(int d=0;d<n;d++){
        if(nodes[d].empty())break;
        int k=sza(nodes[d]);
        ans+=k;
        vector<int>lcas;
        for(int i=0;i<k-1;i++){
            lcas.push_back(get_lca(nodes[d][i],nodes[d][i+1]));
        }
        sort(all(lcas));
        lcas.erase(unique(all(lcas)),lcas.end());
        ans+=sza(lcas);
    }
    cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}