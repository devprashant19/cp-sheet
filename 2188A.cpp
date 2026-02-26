#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        int left = 1;
        int right = n;
        for (int i = n - 1; i >= 0; i--) {
            int step = (n - 1) - i;
            if (step % 2 == 0)p[i] = left++; 
            else p[i] = right--;
        }
        for (int i = 0; i < n; i++)cout << p[i] << (i == n - 1 ? "" : " ");
        cout << endl;
    }
}