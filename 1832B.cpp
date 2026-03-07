#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        vector<long long> a(n);
        for(long long i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        
        long long sum = 0;
        for (int i = 0; i <= k; i++) {
            int left = 2 * i;
            int right= k - i;
            long long csum = pref[n - right] - pref[left];
            sum = max(sum, csum);
        }
        
        cout << sum << endl;
    }
}