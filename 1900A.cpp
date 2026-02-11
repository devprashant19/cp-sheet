#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        int c = 0;
        for (int i = 0; i <= n; i++) {
            if (i < n && s[i] == '.') {
                c++;
            } else {
                if (c > 0) {
                    ans += min(c, 2);
                }
                c = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
