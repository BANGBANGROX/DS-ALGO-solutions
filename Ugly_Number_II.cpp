#include<bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n) {
	vector<int> dp;
	int twoNums = 0, threeNums = 0, fiveNums = 0;

	dp.push_back(1);

	for (int i = 1; i < n; ++i) {
		int nextNum = min(min(2 * dp[twoNums], 3 * dp[threeNums]), 5 * dp[fiveNums]);
		dp.push_back(nextNum);
		if (nextNum == 2 * dp[twoNums]) ++twoNums;
	    if (nextNum == 3 * dp[threeNums]) ++threeNums;
		if (nextNum == 5 * dp[fiveNums]) ++fiveNums;
	}

	return dp.back();
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		cout << nthUglyNumber(n) << endl;
	}

	return 0;
}
