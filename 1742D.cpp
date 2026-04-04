#include <bits/stdc++.h>
using namespace std;
vector<long long>pairs[1001];
int main()
{
    for (int i = 1; i <= 1000; ++i) {
		for (int j = 1; j <= 1000; ++j) {
			if (__gcd(i, j) == 1) {
				pairs[i].push_back(j);
			}
		}
	}
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
        long long ans=-1;
        for(int i=1;i<=1000;i++){
            if(idx[i]==0)continue;
            for(long long j:pairs[i]){
                if(idx[j]!=0)ans=max(ans,idx[i]+idx[j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}