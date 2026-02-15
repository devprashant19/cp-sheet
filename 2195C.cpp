#include <bits/stdc++.h>
using namespace std;
int opp[7] = {0,6,5,4,3,2,1};
int solve(int i, int prev, vector<vector<long long>>& dp, vector<long long>& a){
    if(i == a.size()) return 0;
    if(dp[i][prev] != -1)return dp[i][prev];
    int ans = 1e9;
    for(int cur = 1; cur <= 6; cur++){
        if(prev == 0 || (cur != prev && opp[prev] != cur)){
            int cost=1;
            if(a[i]==cur)cost=0;
            ans = min(ans, cost + solve(i+1, cur, dp, a));
        }
    }
    return dp[i][prev]=ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; i++)cin >> a[i];
        vector<vector<long long>> dp(n, vector<long long>(7, -1));
        long long ans=solve(0, 0,dp,a);
        cout << ans <<endl;
    }
    return 0;
}
