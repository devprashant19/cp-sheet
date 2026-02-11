#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--){
        int n;
        cin>>n;
        int x=0;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            x^=temp;
        }
        if(n%2==1){
            cout<<x<<endl;
        }else{
            if(x==0)cout<<3<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
}