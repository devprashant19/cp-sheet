#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int p;
            cin >> p; 
        }   
        if (n == 1) {
            cout << 1 << "\n";
        } else {
            for (int i = 0; i < n; ++i) {
                cout << 2 << (i == n - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
    return 0;
}