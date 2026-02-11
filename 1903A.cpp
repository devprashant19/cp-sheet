#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> b=a;
        sort(b.begin(),b.end());
        if(k==1 && a==b) cout<<"yes"<<endl;
        else if(k==1 && a!=b) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}
