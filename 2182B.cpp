#include<bits/stdc++.h>
using namespace std;
long long maxVal(long long a,long long b){
    long long c=0;
    long long n=1;
    bool flag=true;
    while(a>=n && b>=n){
            if(flag)a-=n;
            else b-=n;
            flag=!flag;
            n*=2;
            c++;
        }
    if(flag && a>=n)c++;
    else if(!flag && b>=n)c++;
    return c;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        long long c=maxVal(a,b);
        long long d=maxVal(b,a);
        if(c>d)cout<<c<<endl;
        else cout<<d<<endl;
    }
    return 0;
}
