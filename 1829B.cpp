#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        int c=0;
        int maxElem=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(x==0)c++;
            else c=0;
            maxElem=max(maxElem,c);
        }
        cout<<maxElem<<endl;
    }
    return 0;
}
