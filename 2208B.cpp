#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, p;
        long long m;
        cin >> n >> k >> p >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)cin >> a[i];
        long long wp_cost = a[p - 1];
        long long cost_first = wp_cost;
        if (p > k) {
            vector<long long> prefix(a.begin(), a.begin() + p - 1);
            sort(prefix.begin(), prefix.end());
            for (int i = 0; i < p - k; i++) {
                cost_first += prefix[i];
            }
        }
        long long cost_cycle = wp_cost;
        if (n > k) {
            vector<long long> others;
            for (int i = 0; i < n; i++) {
                if (i != p - 1) {178
                    others.push_back(a[i]);
                }
            }
            sort(others.begin(), others.end());
            for (int i = 0; i < n - k; i++) {
                cost_cycle += others[i];
            }
        }
        if (m < cost_first) {
            cout << 0 << "\n";
        } else {
            long long plays = 1 + (m - cost_first) / cost_cycle;
            cout << plays << "\n";
        }
    }
    return 0;
}