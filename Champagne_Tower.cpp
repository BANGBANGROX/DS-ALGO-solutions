#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	double champagneTower(int poured, int queryRow, int queryGlass) {
		double dp[102][102] = { 0 };

		dp[0][0] = (double)poured;

		for (int i = 0; i <= queryRow; ++i) {
			for (int j = 0; j <= i; ++j) {
				double left = (dp[i][j] - 1.0) / 2.0;
				if (left > 0) {
					dp[i + 1][j] += left;
					dp[i + 1][j + 1] += left;
				}
			}
		}

		return min(1.0, dp[queryRow][queryGlass]);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int poured, queryGlass, queryRow;
		cin >> poured >> queryRow >> queryGlass;

		Solution solution;
		cout << solution.champagneTower(poured, queryRow, queryGlass) << endl;
	}

	return 0;
}