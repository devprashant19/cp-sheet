#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n, q;
		cin >> n >> q; 
		vector<long long> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
        vector<long long> psum(n+1,0);
        for(long long i=1;i<n+1;i++){
            psum[i]=psum[i-1]+a[i-1];
        }
        for(long long i=0;i<q;i++){
            long long l,r,k;
            cin>>l>>r>>k;
            long long sum=psum[n];
            sum=sum-psum[r]+psum[l-1];
            sum+=(r-l+1)*k;
            if(sum%2==1)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
	}
	return 0;
}