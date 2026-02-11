#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        int val=0;
        for(int i=0;i<n-1;i++){
            int y;
            cin>>y;
            val+=y;
        }
        cout<<-(val)<<endl;
    }
    return 0;
}
