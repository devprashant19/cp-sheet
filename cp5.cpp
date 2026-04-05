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

    const ll MOD = 1e9 + 7;
    const ll INF = 1e9;
    const ld EPS = 1e-9;

    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        int n;
        cin>>n;
        string s;
        cin>>s;
        int n1=n/2;
        int cnt=0,index=0;
        if(n%2==0)cout<<"NOT POSSIBLE\n";
        else{
            vector<int> freq(26,0);
            for(char c:s){
                freq[c-'A']++;
            }
            int val=0;
            char x;
            for(int i=0;i<26;i++){
                if(freq[i]==1){
                    cnt++;
                    x=(char)(i+'A');
                }
            }
            if(cnt>1){
                cout<<"NOT POSSIBLE\n";
                return 0;
            }
            cnt=0;
            int l=0;
            int r=n1;
            while(r<n){
                if(s[l]!=s[r]){
                    cnt++;
                    if(r+1<n && s[l]==s[r+1]){
                        r++;
                        index=r;
                    }else if(s[l+1]==s[r]){
                        l++;
                        index=l;
                    }else{
                        cnt=2;
                        break;
                    }
                }
                l++;
                r++;
            }
            if(cnt==1){
                if(index>n1){
                    for(int i=0;i<n1;i++){
                        cout<<s[i]<<"";
                    }
                }else{
                    for(int i=n1+1;i<n;i++){
                        cout<<s[i]<<"";
                    }
                }
                cout<<"\n";
            }else{
                cout<<"NOT UNIQUE\n"; 
            }
        }
        return 0;
    }