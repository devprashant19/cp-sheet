#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<string> a(10);
        for (int i = 0; i < 10; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (a[i][j] == 'X') {
                    int score = min({i + 1, j + 1, 10 - i, 10 - j});
                    ans += score;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
