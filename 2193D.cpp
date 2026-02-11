#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        // Prefix sums of b
        vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + b[i - 1];

        // Sort strengths descending
        sort(a.begin(), a.end(), greater<long long>());

        long long ans = 0;
        long long S = 0;   // usable swords
        int k = 0;         // completed levels

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && a[j] == a[i]) j++;

            // add all swords with this strength
            S += (j - i);

            // increase k while possible
            while (k + 1 <= n && pref[k + 1] <= S)
                k++;

            long long x = o;
            ans = max(ans, x * k);

            i = j;
        }

        cout << ans << "\n";
    }

    return 0;
}
