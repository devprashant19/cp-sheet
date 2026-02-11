#include <bits/stdc++.h>
using namespace std;

bool f(long long p,long long q, vector<vector<bool>> &dp){
    if(p < 0 || q < 0) return false;
    if(p==0 && q==1) return false;
    if(dp[p][q]) return dp[p][q];
    if(q%3==0){
        return dp[p][q] = (p==2*(q/3)); 
    }
    return dp[p][q] = f(p-1,q,dp) || f(p,q-1,dp) || f(p-1,q-1,dp);
}

int main(){
    long long t;
    cin >> t;
    while (t--){
        long long p, q;
        cin >> p >> q;
        vector<vector<bool>> dp(p+1, vector<bool>(q+1, false));
        bool flag = f(p, q,dp);
        if (flag) cout << "Bob"<<endl;
        else cout << "Alice"<<endl;
    }
}
