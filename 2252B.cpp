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
    string s;
    cin>>s;
    int z=0,o=0;
    for(char c:s){
        if(c=='0')z++;
        else o++;
    }
    if(abs(z-o)>2){
        cout<<"-1\n";
        return;
    }
    int a=0,b=0;
    if(s[0]=='0'){
        a++;
    }else b++;
    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            if(s[i]=='0'){
                a++;
            
            }else b++;
        }
    }
    int val=a+b;
    for(int i=val;i>=1;i--){
        if(i%2==0){
            int k0=i/2,k1=i/2;
            if(k0<=a&&k1<=b && abs((z-k0)-(o-k1))<=1){
                cout<<n-i<<"\n";
                return;
            }
        }else{
            int ka=(i+1)/2,kb=(i-1)/2;
            if(ka<=a&&kb<=b && abs((z-ka)-(o-kb))<=1){
                cout<<n-i<<"\n";
                return;
            }
            int kc=(i-1)/2,kd=(i+1)/2;
            if(kc<=a&&kd<=b && abs((z-kc)-(o-kd))<=1){
                cout<<n-i<<"\n";
                return;
            }
        }
    }
    cout<<"-1\n";
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