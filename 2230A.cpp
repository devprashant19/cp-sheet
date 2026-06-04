#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        
        if (3 * a <= b) {
            cout << n * a << "\n";
        } else {
            long long cost = (n / 3) * b;
            long long rem = n % 3;
            cost += min(rem * a, b);
            cout << cost << "\n";
        }
    }
    
    return 0;
}