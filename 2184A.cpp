#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;
        if(n>=4){
            if(n%2==0)cout<<0<<endl;
            else cout<<1<<endl;
        }
        if(n==1)cout<<0<<endl;
        if(n==2)cout<<2<<endl;
        if(n==3)cout<<3<<endl;
    }
    return 0;
}