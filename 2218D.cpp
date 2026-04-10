#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    while (t--){
        int n;
        cin>>n;
        for (long long i = 1; i <= n; i++) {
            long long val = (2 * i - 1) * (2 * i + 1);
            cout << val << " ";
        }
        cout << "\n";
    }
}
