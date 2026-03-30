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
        int j=n-1;
        long long result = 1;
        for(int i=0;i<n;i++){
            while(j>=0 && a[j]>b[i])j--;
            j++;
            if(j>=0)result = (result*(n-j-i))%mod;
        }
        cout << result << endl;
    }
}