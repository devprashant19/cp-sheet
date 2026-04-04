#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int main(){
    long long t;
    cin >> t;
    while (t--){
        long long n;
        cin>>n;
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(i==n)ans+=i*i;
            else ans+=i*(i+i+1);
        }
        ans=(ans*2022)%mod;
        cout<<ans<<endl;
    }
}
