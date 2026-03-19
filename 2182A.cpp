#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        bool has_2025 = false;
        bool has_2026 = false;
        for (int i = 0; i <= n - 4; ++i) {
            if (s.substr(i, 4) == "2025") has_2025 = true;
            if (s.substr(i, 4) == "2026") has_2026 = true;
        }
        if (has_2026 || !has_2025) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    }
}
