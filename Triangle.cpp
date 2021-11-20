#include<bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
	int n = triangle.size(), m = triangle[n - 1].size();
	vector<vector<int>> dp(n, vector<int>(m));

	for (int i = 0; i < m; ++i) dp[n - 1][i] = triangle[n - 1][i];

	for (int i = n - 2; i > -1; --i) {
		for (int j = 0; j < triangle[i].size(); ++j) {
			dp[i][j] = triangle[i][j];
			dp[i][j] += (j < triangle.size() - 1) ? min(dp[i + 1][j], dp[i + 1][j + 1]) : dp[i + 1][j];
		}
	}

	return dp[0][0];
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> triangle(n);
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < i; ++j) {
				int a;
				cin >> a;
				triangle[i - 1].push_back(a);
			}
		}
		
		cout << minimumTotal(triangle);
	}

	return 0;
}