#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cntNeg = 0, cntPos = 0;
        for (int i = 0; i < n; ++i) {
            int y; 
            cin >> y;
            if (y == -1) cntNeg++;
            else cntPos++; 
        }
        int sum = cntPos - cntNeg;
        int flips = 0;
        if (sum < 0) {
            flips = (-sum + 1) / 2;
            cntNeg -= flips;         
        }
        if (cntNeg % 2 != 0) {
            flips += 1;
        }
        cout << flips << '\n';
    }
    return 0;
}
