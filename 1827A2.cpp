#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)cin>> a[i];
        sort(a.begin(), a.end());
        vector<int> b(n);
        for(int i=0;i<n;i++)cin>>b[i];
        sort(b.rbegin(), b.rend());
        long long result = 1;
        for(int i=0;i<n;i++){
            long long temp = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
            long long ans=n-temp;
            result = (result*max(ans-i,(long long)0))%mod;
        }
        cout << result << endl;
    }
}