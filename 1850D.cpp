#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n,k;
		cin >> n>>k;
        vector<long long> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int maxVal=1;
        int count=1;
        sort(a.begin(),a.end());
        for(int i=0;i<n-1;i++){
            if(abs(a[i+1]-a[i])<=k){
                count++;
            }else{
                count=1;
            }
            maxVal=max(count,maxVal);
        }
        cout<<n-maxVal<<endl;
	}
	return 0;
}
