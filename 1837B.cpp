#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
        string s;
        cin>>s;
        int count=1;
        int maxCount=1;
        for(int i=0;i<n-1;i++){
            if(s[i+1]==s[i]){
                count++;
            }else{
                count=1;
            }
            maxCount=max(maxCount,count);
        }
        cout<<maxCount+1<<endl;
	}
	return 0;
}
