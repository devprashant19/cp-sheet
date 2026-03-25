#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            long long c, k;
            cin >> n >> c >> k;
            vector<long long> a(n);
            for (int i = 0; i < n; ++i)cin >> a[i];
            sort(a.begin(), a.end());
            for (int i = 0; i < n; ++i) {
                if (c < a[i])break;
                long long use = min(k, c - a[i]);
                k -= use;
                c += a[i] + use; 
            }
            cout << c << endl;
        }
    }
    return 0;
}