#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool all_equal = true;
        for (long long i = 0; i + 1 < n; i++) {
            if (a[i] != a[i + 1]) {
                all_equal = false;
                break;
            }
        }
        if (all_equal) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        sort(a.begin(), a.end(), greater<long long>());

        if (n >= 2 && a[0] == a[1]) {
            swap(a[0], a.back());
        }
        for (long long x : a) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
