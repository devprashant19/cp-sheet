#include <bits/stdc++.h>
using namespace std;
int current_and;
vector<int> ans;
void solve(vector<int>& p, int bit, int n) {
    if (p.empty()) return;
    if (bit == n || !(current_and & (1 << bit))) {
        sort(p.begin(), p.end());
        for (int x : p) {
            ans.push_back(x);
            current_and &= x; 
        }
        return;
    }
    vector<int> with, without;
    for (int x : p) {
        if ((x >> bit) & 1) {
            with.push_back(x);
        } else {
            without.push_back(x);
        }
    }
    solve(with, bit + 1, n);
    solve(without, bit + 1, n);
}

void run_test_case() {
    int n;
    cin >> n;
    ans.clear();
    current_and = (1 << n) - 1; 
    vector<int> p(1 << n);
    iota(p.begin(), p.end(), 0);
    solve(p, 0, n);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            run_test_case();
        }
    }
    return 0;
}