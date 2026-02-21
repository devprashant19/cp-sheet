#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,s,x;
        cin>>n>>s>>x;
        vector<long long> a(n);
        for(long long i=0;i<n;i++) cin>>a[i];
        long long sum=0;
        for(long long i=0;i<n;i++)sum+=a[i];
        if(sum>s) cout<<"NO"<<endl;
        else{
            long long r=s-sum;
            if(r%x==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
