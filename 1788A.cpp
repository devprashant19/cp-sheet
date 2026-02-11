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
        int cnt = 0;
        vector<int>a(n);
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            if (a[i] == 2)cnt++;
        }
        int y=0,ind;
        if (cnt % 2 !=0)cout << -1<<endl;
        else if(cnt==0)cout<<1<<endl;
        else{
            for(int i=0;i<n;i++){
                if(y==cnt/2){
                    ind=i;
                    break;
                }
                if(a[i]==2)y++;
            }
            cout<<ind<<endl;
        }
    }
    return 0;
}