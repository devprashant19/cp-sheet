#include <bits/stdc++.h>
using namespace std;

int findRoot(int x) {
    while (x % 2 == 0) {
        x /= 2;
    }
    return x;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<int> pos(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (findRoot(i) != findRoot(pos[i])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
