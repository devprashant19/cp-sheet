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
		vector<long long> a(n);
		for (long long i = 0; i < n; i++) cin >> a[i];
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==0)cnt++;    
        }
        int left=0;
        int right=n-1;
        bool flag=false;
        while(a[left]==0)left++;
        while(a[right]==0)right--;
        for(int i=left;i<=right;i++){
            if(a[i]==0)flag=true;
        }
        if(cnt==n)cout<<0<<endl;
        else if(flag)cout<<2<<endl;
        else cout<<1<<endl;
        
	}
	return 0;
}

