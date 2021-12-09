#include<bits/stdc++.h>
using namespace std;

int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
	int ans = 0;

	for (int i = homePos[0]; i != startPos[0]; i += (i > startPos[0] ? -1 : 1)) ans += rowCosts[i];
	for (int i = homePos[1]; i != startPos[1]; i += (i > startPos[1] ? -1 : 1)) ans += colCosts[i];

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n;
		cin >> m >> n;
		vector<int> startPos(2), homePos(2), rowCosts(m), colCosts(n);
		for (int i = 0; i < m; ++i) cin >> rowCosts[i];
		for (int i = 0; i < n; ++i) cin >> colCosts[i];
		cin >> startPos[0] >> startPos[1] >> homePos[0] >> homePos[1];

		cout << minCost(startPos, homePos, rowCosts, colCosts) << endl;
	}

	return 0;
}