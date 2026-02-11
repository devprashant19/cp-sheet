#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
    cin>>n;
    string s;
    cin>>s;
    long long ans=0;
    bool flag=false;
    for(long long i=0;i<n-1;i++){
        if(s[i]>s[i+1]){
            ans=i;
            flag=true;
            break;
        }
    }
    if(!flag){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        cout<<ans+1<<" "<<ans+2<<endl;
    }
    return 0;
}