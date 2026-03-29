#include <bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin >> t;
    while (t--){
        long long n;
        cin >> n;
        vector<string> a(n);
        for (long long i = 0; i < n; i++)cin >> a[i];
        string s = a[0];
        for(int i=1; i<n; i++){
            if(a[i]+s<s+a[i])s=a[i]+s;
            else s=s+a[i];
        }
        cout << s << endl;
    }
}
