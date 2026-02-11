#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int i=0,j=s.size()-1;
        while(s[i]!=s[j]){
            i++;
            j--;
            if(i>=j)break;
        }
        if(i>j)cout<<0<<endl;
        else if(i==j)cout<<1<<endl;
        else cout<<j-i+1<<endl;
    }
    return 0;
}