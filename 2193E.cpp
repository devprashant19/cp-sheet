#include <bits/stdc++.h>
using namespace std;
static const int INF = 1e9;
vector<int> spf;
void build_spf(int maxN) {
    spf.resize(maxN + 1);
    for (int i = 1; i <= maxN; i++) spf[i] = i;
    for (int i = 2; i * i <= maxN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= maxN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}
vector<int> get_divisors(int x) {
    vector<pair<int,int>> fac;
    while (x > 1) {
        int p = spf[x], cnt = 0;
        while (x % p == 0) {
            x /= p;
            cnt++;
        }
        fac.push_back({p, cnt});
    }
    vector<int> divisors = {1};
    for (auto &pr : fac) {
        int p = pr.first, cnt = pr.second;
        int sz = divisors.size();
        int mul = 1;
        for (int e = 1; e <= cnt; e++) {
            mul *= p;
            for (int i = 0; i < sz; i++) {
                divisors.push_back(divisors[i] * mul);
            }
        }
    }
    return divisors;
}
int main() {
    int t;
    cin >> t;
    vector<int> tests_n(t);
    vector<vector<int>> tests_a(t);
    int maxN = 0;
    for (int i = 0; i < t; i++) {
        cin >> tests_n[i];
        tests_a[i].resize(tests_n[i]);
        for (int j = 0; j < tests_n[i]; j++) {
            cin >> tests_a[i][j];
            maxN = max(maxN, tests_n[i]);
        }
    }
    build_spf(maxN);
    for (int tc = 0; tc < t; tc++) {
        int n = tests_n[tc];
        auto &a = tests_a[tc];
        vector<bool> present(n + 1, false);
        for (int x : a) present[x] = true;
        vector<int> dp(n + 1, INF);
        dp[1] = 0;
        for (int x = 2; x <= n; x++) {
            auto divs = get_divisors(x);
            int best = INF;
            for (int d : divs) {
                if (d >= 2 && present[d]) {
                    int prev = x / d;
                    if (dp[prev] != INF) {
                        best = min(best, dp[prev] + 1);
                    }
                }
            }
            dp[x] = best;
        }
        for (int i = 1; i <= n; i++) {
            if (i == 1) {
                cout << (present[1] ? 1 : -1);
            } else {
                cout << (dp[i] == INF ? -1 : dp[i]);
            }
            cout << (i == n ? '\n' : ' ');
        }
    }
    return 0;
}
