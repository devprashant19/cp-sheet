#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		string s;
        cin >> s;
        vector<long long> hash(26,0);
        for(auto ch:s){
            hash[ch-'a']++;
        }
        long long maxVal=0;
        unordered_set<char> prefix(s.begin(),s.begin()+1);
        unordered_set<char> suffix(s.begin()+1,s.end());
        for(int i=0;i<n;i++){
            if(hash[s[i]-'a']<=1){
                suffix.erase(s[i]);
            }
            prefix.insert(s[i]);
            hash[s[i]-'a']--;
            long long val=prefix.size()+suffix.size();
            maxVal=max(val,maxVal);
        }
        cout<<maxVal<<endl;
    }
	return 0;
}