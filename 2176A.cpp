#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)cin>> a[i];
        long long cnt = 0;
        long long max_elem = a[0]; 
        for(long long i = 1; i < n; i++) {
            if (a[i] < max_elem) {
                cnt++; 
            } else {
                max_elem = a[i]; 
            }
        }
        cout << cnt << endl;
    }
}