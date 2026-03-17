#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for(int i = 0; i < n; i++)cin>> a[i];
        vector<long long> b;
        for(long long i = 0; i <= n/2; i++) {
            b.push_back(abs(a[i]-a[n-1-i]));
        }
        long long ans = 0;
        for(int i = 0; i < b.size(); i++) {
            ans = __gcd(ans, b[i]);
        }
        cout << ans << endl;
    }
}