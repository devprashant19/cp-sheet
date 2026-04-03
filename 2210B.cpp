#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--){
        long long n;
        cin>>n;
        vector<long long> p(n);
        for(long long i=0;i<n;i++)cin>>p[i];
        long long cnt=0;
        for(int i=0;i<n;i++){
            if(p[i]<=i+1)cnt++;
        }
        cout<<cnt<<endl;
    }
}
