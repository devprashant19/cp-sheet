#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long &x : a) cin >> x;
        long long currSum = a[0];
        long long maxVal  = a[0];
        for (int i = 1; i < n; i++) {
            if ((abs(a[i]) % 2) != (abs(a[i - 1]) % 2)) {
                currSum = max(a[i], currSum + a[i]);
            }
            else {
                currSum = a[i];
            }
            maxVal = max(maxVal, currSum);
        }

        cout << maxVal << endl;
    }
    return 0;
}
