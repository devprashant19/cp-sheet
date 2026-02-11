#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        bool flag = true;
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        if (a[n-1] != b[n-1]) flag = false;

        for (int i = 0; i < n-1; i++) {
            if (a[i] == b[i]) continue;
            else if ((a[i] ^ a[i+1]) == b[i] || (a[i] ^ b[i+1]) == b[i]) {
                continue;
            } else {
                flag = false;
                break;
            }
        }

        cout << (flag ? "yes" : "no") << endl;
    }
    return 0;
}
