#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> freq(n * n + 1, 0);
        long long max_freq = 0;
        for (long long i = 0; i < n * n; ++i) {
            long long color;
            cin >> color;
            freq[color]++;
            max_freq = max(max_freq, freq[color]);
        }
        if (max_freq <= n * n - n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}