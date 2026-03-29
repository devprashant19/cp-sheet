#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long l, a, b;
        cin >> l >> a >> b;
        long long g = __gcd(l, b);
        long long r = a % g;
        cout << l - g + r << endl;
    }
    return 0;
}