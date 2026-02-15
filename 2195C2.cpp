    #include <bits/stdc++.h>
    using namespace std;
    long long opp[7] = {0,6,5,4,3,2,1};
    int main(){
        int t;
        cin >> t;
        while(t--){
            long long n;
            cin >> n;
            vector<long long> a(n);
            for(long long i = 0; i < n; i++)cin >> a[i];
            vector<vector<long long>> dp(n+1, vector<long long>(7, 0));
            for(long long i = n-1; i >= 0; i--){
                for(long long prev = 0; prev <= 6; prev++){
                    long long ans = 1e9;
                    for(long long cur = 1; cur <= 6; cur++){
                        if(prev == 0 || (cur != prev && opp[prev] != cur)){
                            long long cost=1;
                            if(a[i]==cur)cost=0;
                            ans = min(ans, cost + dp[i+1][cur]);
                        }
                    }
                    dp[i][prev]=ans;
                }
            }
            cout << dp[0][0] <<endl;
        }
        return 0;
    }
