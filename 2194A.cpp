#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
       long long n, w;
        cin >> n >> w;
        long long max_removed = n - (n / w);
        cout << max_removed << "\n";
    }
    return 0;
}