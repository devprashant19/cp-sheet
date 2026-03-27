#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            int greater_cnt = 0;
            int smaller_cnt = 0;
            for (int j = i + 1; j < n; j++) {
                if (a[j] > a[i]) greater_cnt++;
                else if (a[j] < a[i]) smaller_cnt++;
            }
            if (i == n - 1) cout << max(greater_cnt, smaller_cnt);
            else cout << max(greater_cnt, smaller_cnt) << " ";
        }
        cout << "\n";
    }
    return 0;
}