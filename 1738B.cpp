#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> s(k);
    for(int i = 0; i < k; ++i) {
        cin >> s[i];
    }
    
    if (k == 1) {
        cout << "YES\n";
        return;
    }
    
    vector<int> a(k - 1);
    for (int i = 1; i < k; ++i) {
        a[i - 1] = s[i] - s[i - 1];
    }
    
    for (int i = 1; i < k - 1; ++i) {
        if (a[i] < a[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    
    if (s[0] > a[0] * (n - k + 1)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}