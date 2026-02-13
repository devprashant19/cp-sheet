#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        long long n1 = s1.size();
        long long n2 = s2.size();
        long long c = 0;
        while (c < n1 && c < n2 && s1[c] == s2[c]) {
            c++;
        }
        long long ans = n1 + n2;
        if (c != 0) ans = ans - c + 1;
        cout << ans << endl;
    }
    return 0;
}
