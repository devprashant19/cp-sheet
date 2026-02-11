#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int flag=0;
        int zeroes=0,ones=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')zeroes++;
            else ones++;
        }
        int tk=0,low=1,high=n;
        while(tk<k){
            if(zeroes>=ones)zeroes-=2;
            else ones-=2;
            tk++;
            low++;
            high--;
        }
        while(low<high){
            zeroes--;
            ones--;
            low++;
            high--;
        }
        if(low==high){
            if(zeroes>=0)zeroes--;
            else ones--;
        }
        if(zeroes<0 || ones<0){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}