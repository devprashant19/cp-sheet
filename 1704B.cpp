#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n,x;
        cin>>n>>x;
        vector<long long> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        vector<pair<long long,long long>> s(n);
        for(int i=0;i<n;i++){
            s[i]={a[i]-x,a[i]+x};   
        }
        long long l=a[0]-x;
        long long r=a[0]+x;
        long long ans=0;
        for(int i=0;i<n;i++){
            l=max(l,s[i].first);
            r=min(r,s[i].second);
            if(l>r){
                ans++;
                l=s[i].first;
                r=s[i].second;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}