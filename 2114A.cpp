#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        long long n = stoll(s);
        long long low = 1;
        long long high = n;
        long long ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid * mid == n) {
                ans = mid;
                break;
            } 
            else if (mid * mid < n)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (ans != -1)
            cout << 0 << " " << ans << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
