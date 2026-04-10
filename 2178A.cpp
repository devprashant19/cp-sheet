#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int y_count = count(s.begin(), s.end(), 'Y');
        if (y_count >= 2)cout << "NO";
        else cout << "YES";
        cout << endl;
    }
}