#include <bits/stdc++.h>
using namespace std;

vector<array<int, 2>> tr;

void insert(int x) {
    int u = 0;
    for (int i = 30; i >= 0; i--) {
        int b = (x >> i) & 1;
        if (tr[u][b] == -1) {
            tr[u][b] = tr.size();
            tr.push_back({-1, -1});
        }
        u = tr[u][b];
    }
}

int get_max(int x) {
    int u = 0, ans = 0;
    for (int i = 30; i >= 0; i--) {
        int b = (x >> i) & 1;
        if (tr[u][1 - b] != -1) {
            ans |= (1 << i);
            u = tr[u][1 - b];
        } else {
            u = tr[u][b];
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    tr.assign(1, {-1, -1});
    int ans = 0;
    insert(a[0]);

    for (int i = 1; i < n; i++) {
        ans = max(ans, get_max(a[i]));
        insert(a[i]);
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}   