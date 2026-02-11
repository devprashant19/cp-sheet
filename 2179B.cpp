#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long total = 0;
        for (int i = 0; i + 1 < n; i++) {
            total += abs(a[i] - a[i + 1]);
        }
        long long ans = total;
        ans = min(ans, total - abs(a[0] - a[1]));
        ans = min(ans, total - abs(a[n - 2] - a[n - 1]));
        for (int i = 1; i + 1 < n; i++) {
            long long cur = total;
            cur -= abs(a[i] - a[i - 1]);
            cur -= abs(a[i + 1] - a[i]);
            cur += abs(a[i + 1] - a[i - 1]);
            ans = min(ans, cur);
        }

        cout << ans << "\n";
    }
    return 0;
}
