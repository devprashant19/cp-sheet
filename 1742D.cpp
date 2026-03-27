#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--){
        long long n;
        cin>>n;
        vector<long long>idx(1001,0);
        for (int i = 0; i < n; i++){
            int x;
            cin >>x;
            idx[x]=i+1;
        }
        int ans=-1;
        for(int i=1;i<=1000;i++){
            if(idx[i]==0)continue;
            for(int j)
                ans=max(ans,idx[i]);
            }
        }
    }
    return 0;
}