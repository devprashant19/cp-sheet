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
        vector<int> b = a;             
        sort(b.begin(), b.end());      

        int dist = INT_MAX;
        for (int i = 1; i < n; i++) {
            dist = min(dist, b[i] - b[i - 1]); 
        }

        if (a == b) cout << dist/2 + 1 << '\n';
        else        cout << 0 << '\n';
    }
    return 0;
}
