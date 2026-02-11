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
        long long size = pow(2, n); 
        vector<long long> a(size);
        long long k=0;
        long long ans=0;
        while(k<n){
            ans+=pow(2,k);
            k++;
        }
        a[0]=ans;
        long long j = 1;
        for (long long i = 1; i < ans && j < size; i += 2)a[j++] = i;
        if (j < size)a[j++] = 0;
        for (long long i = 2; i < ans && j < size; i += 2)a[j++] = i;
        for (long long i = 0; i < size; i++)cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}
