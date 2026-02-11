#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t; 
	while (t--)
	{
		long long w,h;
		cin >> w >> h; 
		long long n1;
        cin>>n1;
        vector<long long> x1(n1);
        for(int i=0;i<n1;i++)cin>>x1[i];
		long long n2;
        cin>>n2;
        vector<long long> x2(n2);
        for(int i=0;i<n2;i++)cin>>x2[i];
		long long n3;
        cin>>n3;
        vector<long long> y1(n3);
        for(int i=0;i<n3;i++)cin>>y1[i];
		long long n4;
        cin>>n4;
        vector<long long> y2(n4);
        for(int i=0;i<n4;i++)cin>>y2[i];
        long long max_a=0;
        max_a=max((x1[n1-1]-x1[0])*h,max_a);
        max_a=max((x2[n2-1]-x2[0])*h,max_a);
        max_a=max((y1[n3-1]-y1[0])*w,max_a);
        max_a=max((y2[n4-1]-y2[0])*w,max_a);
        cout<<max_a<<endl;
	}
}
