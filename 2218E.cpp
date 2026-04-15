#include <bits/stdc++.h>
using namespace std;
int f(int i,int k,int curr_xor,vector<int>& a){
    if (k==0)return curr_xor;
    if (i==a.size())return -1;
    int take=f(i+1,k-1,curr_xor^a[i],a);
    int not_take=f(i+1,k,curr_xor,a);
    return max(take,not_take);
}
int main(){
    long long t;
    cin >> t;
    while (t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)cin>>a[i];
        if(n==2){
            int val=a[0]^a[1];
            cout<<val<<"\n";
            continue;
        }
        int k=((n-1)/2)+1;
        int ans=0;
        ans=f(0,k,0,a);
        cout<<ans<<"\n";
    }
}
