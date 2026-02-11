#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin>>n;
        vector<long long> a(n);
        for(long long i=0;i<n;i++) cin>>a[i];
        vector<long long> b=a;
        sort(b.begin(),b.end(),[](long long x,long long y){
            return x>y;
        });
        long long val=-1;
        for(long long i=0;i<n;i++){
            if(a[i]!=b[i]){
                val=i;
                break;
            }
        }
        if(val==-1){
            for(long long i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
            continue;
        }
        long long val2=-1;
        for(long long i=0;i<n;i++){
            if(b[val]==a[i]){
                val2=i;
                break;
            }
        }
        reverse(a.begin()+val,a.begin()+val2+1);
        for(long long i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
