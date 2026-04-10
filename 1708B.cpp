#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int main(){
    long long t;
    cin >> t;
    while (t--){
        long long n,l,r;
        cin>>n>>l>>r;
        vector<long long>ans;
        bool flag=true;
        for(int i=1;i<=n;i++){
            long long temp=((l+i-1)/i)*i;
            ans.push_back(temp);
            if(temp>r){
                flag=false;
                break;
            }
        }
        if(!flag)cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            for(long long i:ans){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
}
