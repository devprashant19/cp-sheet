#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t;
	cin >> t;
	while (t--)
	{
		long long n;
        char c;
        string s;
        cin>>n>>c;
        cin>>s;
        string s2=s+s;
        long long dist=0;
        long long i=-1;
        for(int k=0;k<2*n;k++){
            if(s2[k]==c && i==-1){
                i=k;
            }
            if(s2[k]=='g' && i!=-1){
                dist=max(dist,k-i);
                i=-1;
            }
        }
        cout<<dist<<endl;
	}
	return 0;
}