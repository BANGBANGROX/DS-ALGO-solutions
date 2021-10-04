#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3005;
ll dp[N][N], a[N]; // dp[i][j] is the answer for the interval i to j in the array
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int L = n - 1; L > -1; --L)
	{
		for (int R = L; R < n; ++R)
		{
			if (L == R) dp[L][R] = a[L];
			else dp[L][R] = max(a[L] - dp[L + 1][R], a[R] - dp[L][R - 1]); // take left so opponent will take L+1 to R interval and if R then he will take L to R-1
		}
	}
	cout << dp[0][n - 1] << "\n"; // answer for the whole array 0 to n-1
	return 0;
}