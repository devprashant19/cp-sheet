#include <bits/stdc++.h>
using namespace std;
const int MOD = 676767677;
int count_divisors(int n) {
    if (n == 0) return 1;
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i * i != n)cnt++;
        }
    }
    return cnt;
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            int x, y;
            cin >> x >> y;
            long long min_f;
            if (x == y) {
                min_f = 1;
            } else {
                min_f = count_divisors(abs(x - y));
            }
            cout << min_f % MOD << "\n";
            for (int i = 0; i < x; i++) {
                cout << 1 << " ";
            }
            for (int i = 0; i < y; i++) {
                cout << -1 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}