#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while (t--) {   
        long long n, k, x;
        cin >> n >> k >> x;
        if (x == 1) {
            if (n == 1 || k == 1 || (k == 2 && (n % 2 == 1))) {
                cout << "NO\n";
                continue;
            }
            cout << "YES\n";
            if (n % 2 == 0) {
                cout << n / 2 << "\n";
                for (long long i = 0; i < n / 2; ++i) cout << 2 << ' ';
                cout << "\n";
            } else {
                cout << n / 2 << "\n";
                cout << 3 << ' ';
                for (long long i = 1; i < n / 2; ++i) cout << 2 << ' ';
                cout << "\n";
            }
        } else {
            cout << "YES\n";
            cout << n << "\n";
            for (long long i = 0; i < n; ++i) cout << 1 << ' ';
            cout << "\n";
        }
    }
    return 0;
}
