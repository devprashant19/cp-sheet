#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n,k,b,s;
        cin >> n >> k >> b >> s;
        long long minn=k*b;
        long long maxx=k*b+(k-1)*n;
        if(s<minn ||s>maxx){
            cout<<-1<<endl;
        }else{
            vector<long long>ans(n,0);
            ans[0]=minn;
            s-=minn;
            for(long long i=0;i<n;i++){
                ans[i]+=min(k-1,s);
                s-=min(k-1,s);
            }
            for (long long i = 0; i < n; i++)
				cout << ans[i] << " ";
			cout << endl;
        }
    }
    return 0;
}