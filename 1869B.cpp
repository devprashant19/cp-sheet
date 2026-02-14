#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--){
        long long n,k,a,b;
        cin>>n>>k>>a>>b;
        vector<pair<long long,long long>>v(n+1);
        for(long long i=1;i<=n;i++){
            cin>>v[i].first>>v[i].second;
        }
        long long minVal=abs(v[a].first-v[b].first)+abs(v[a].second-v[b].second);
        long long mina=1e18,minb=1e18;
        for(long long i=1;i<=k;i++){
            mina=min(mina,abs(v[a].first-v[i].first)+abs(v[a].second-v[i].second));
            minb=min(minb,abs(v[b].first-v[i].first)+abs(v[b].second-v[i].second));
        }
        minVal=min(minVal,mina+minb);
        cout<<minVal<<endl;
    }
    return 0;
}
