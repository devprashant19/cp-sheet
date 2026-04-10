#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while (t--) {
        long long n;
        cin>>n;
        int max_idx = 0;
        vector<long long> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            if (p[i] == n) {
                max_idx = i;
            }
        }
        swap(p[0], p[max_idx]);
        for (int i = 0; i < n; ++i) {
            cout << p[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}