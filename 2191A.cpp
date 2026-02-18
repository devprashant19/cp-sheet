#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n),b;
        map<int,string> color;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i%2==0) color[a[i]]="red";
            else color[a[i]]="blue";
        }
        b=a;
        sort(b.begin(),b.end());
        bool flag=true;
        for(int i=1;i<n;i++){
            if(color[b[i]]==color[b[i-1]]){
                flag=false;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
