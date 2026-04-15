#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    while (t--){
        long long total_sum = 0;
        long long max_val = -100;  
        for (int i = 0; i < 7; ++i) {
            long long x;
            cin >> x;
            total_sum += x;
            max_val = max(max_val, x);
        }
        cout << (2 * max_val - total_sum) << "\n";
    }
}
