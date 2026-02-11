#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		unordered_map<long long,long long> mpp;
		vector<long long> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++)mpp[a[i]]++;
        long long max_freq=0;
        for(auto it:mpp){
            max_freq=max(max_freq,it.second);
        }
        long long op=0;
        while(max_freq<n){
            op++;
            if(max_freq*2<=n){
                op+=max_freq;
                max_freq*=2;
            }else{
                op+=n-max_freq;
                max_freq=n;
            }
        }
        cout<<op<<endl;
    }
	return 0;
}