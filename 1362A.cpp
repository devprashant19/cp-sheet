// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         long long a, b;
//         cin >> a >> b;
//         long long ans = 0;
//         if (a % b == 0 || b % a == 0)
//         {
//             if (a == b)
//                 ans = 0;
//             else if ((a % 2 == 0 && b == 1) || (a == 1 && b % 2 == 0) || (a % 2 == 1 && b % 2 == 1))
//             {
//                 ans = -1;
//             }
//             else
//             {
//                 long long temp = max(a, b) / min(a, b);
//                 while (temp % 8 == 0 && temp != 0)
//                 {
//                     temp /= 8;
//                     ans++;
//                 }
//                 while (temp % 4 == 0 && temp != 0)
//                 {
//                     temp /= 4;
//                     ans++;
//                 }
//                 while (temp % 2 == 0 && temp != 0)
//                 {
//                     temp /= 2;
//                     ans++;
//                 }
//             }
//         }else{
//             ans = -1;
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t;
	cin >> t; 
	while (t--)
	{
		long long a, b;
		cin >> a >> b; 
		long long ra = a;
		long long rb = b;
		while (ra % 2 == 0)ra /= 2;
		while (rb % 2 == 0)rb /= 2;

		if (ra != rb)
			cout << -1 << endl;
		else{
			a /= ra;
			b /= rb;
			a = log2(a);
			b = log2(b);
			long long ans = ceil(abs(a - b) / 3.0);
			cout << ans << endl;
		}
	}
	return 0;
}