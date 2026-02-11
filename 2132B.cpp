#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t,n,c,p,p1;
    cin>>t;
    while(t--){
        vector<long long> ans;
        cin>>n;
        c=0;
        p=1;
        p1=p*10+1;
        while(p1<=n){
            if(n%p1==0){
                ans.push_back(n/p1);
                c++;
            }
            p*=10;
            p1=p*10+1;
        }
        cout<<c<<endl;
        for(int i=c-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
        if(c>0)cout<<endl;
    }
    return 0;
}