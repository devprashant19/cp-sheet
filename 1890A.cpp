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
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[a[i]]++; 
        }
        if(mpp.size()>=3)cout<<"No"<<endl;
        else if(mpp.size()==1){
            cout<<"Yes"<<endl; 
        }
        else{
            auto it = mpp.begin();
            int freq_1 = it->second;
            ++it;
            int freq_2 = it->second;
            
            if (freq_1 == freq_2)
                cout << "Yes" << endl; 
            else if (n % 2 == 1 && abs(freq_1 - freq_2) == 1) 
                cout << "Yes" << endl; 
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
