#include<bits/stdc++.h>
using namespace std;

int FindMaxSum(int a[], int n) {
	vector<int> dp(n); // dp[i] is the max answer till (i-1)th item
	dp[0] = a[0];

	for (int i = 1; i < n; ++i) {
		dp[i] = max(dp[i - 1], a[i]);
		if (i > 1) dp[i] = max(dp[i], a[i] + dp[i - 2]);
	}

	return dp[n - 1];
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		cout << FindMaxSum(a, n) << endl;
	}

	return 0;
}
