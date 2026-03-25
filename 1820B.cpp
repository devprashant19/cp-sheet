#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        long long n = s.size();
        string s2 = s+s;
        long long cons_ones = 0;
        long long max_ones = 0;
        for(int i = 0; i < 2*n; i++) {
            if(s2[i] == '1') {
                cons_ones++;
                max_ones = max(max_ones, cons_ones);
            } else {
                cons_ones = 0;
            }
        }
        if (max_ones == 2 * n) {
            cout << n * n << endl;
            continue;
        }
        long long maxVal=0;
        for(int i=0; i<=max_ones/2; i++) {
            maxVal=max(maxVal,(i+1)*(max_ones-i));
        }
        cout << maxVal << endl;
    }
    return 0;
}