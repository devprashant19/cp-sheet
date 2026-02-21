#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, h, l;
        cin >> n >> h >> l;
        int cx = 0;
        int cy = 0;
        int cb = 0;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val; 
            if (val <= h && val <= l) {
                cb++;
            } else if (val <= h) {
                cx++;
            } else if (val <= l) {
                cy++;
            }
        }
        int ans = min({cx + cb, cy + cb, (cx + cy + cb) / 2});
        cout << ans << endl;
    }
    return 0;
}