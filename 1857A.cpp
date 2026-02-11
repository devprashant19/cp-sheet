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
        int c=0;
        for(int i=0;i<n;i++){
            int y;
            cin>>y;
            if(y%2!=0)c++;
        }
        if(c%2==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}