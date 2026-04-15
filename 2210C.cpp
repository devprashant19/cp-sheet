#include <bits/stdc++.h>
using namespace std;

long long get_lcm(long long a, long long b) {
    return (a / __gcd(a, b)) * b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        if (n == 2) {
            int ans = 0;
            long long g = __gcd(a[0], a[1]);
            if (a[0] > g) ans++;
            if (a[1] > g) ans++;
            cout << ans << "\n";
            continue;
        }

        vector<long long> L(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            L[i] = __gcd(a[i], a[i+1]);
        }

        int ans = 0;
        
        if (a[0] > L[0]) ans++;
        if (a[n - 1] > L[n - 2]) ans++;

        for (int i = 1; i < n - 1; ++i) {
            long long req_lcm = get_lcm(L[i - 1], L[i]);
            if (a[i] > req_lcm) ans++;
        }

        cout << ans << "\n";
    }
    
    return 0;
}