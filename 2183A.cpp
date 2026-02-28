#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--){
        long long n;
        cin>>n;
        vector<long long> a(n);
        for(long long i=0;i<n;i++)cin>>a[i];
        if (a[0] == 1 || a[n - 1] == 1) {
            cout << "Alice"<<endl;
        } else {
            cout << "Bob"<<endl;
        }
    }
}
