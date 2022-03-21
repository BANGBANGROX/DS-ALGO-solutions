// https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<int>> dp;
	vector<int> whiteTiles;

	int maxWhiteTilesCovered(string& floor, int idx, int numCarpets, int carpetLen) {
		int n = floor.size();

		if (idx >= n || numCarpets == 0) return 0;

		if (dp[idx][numCarpets] != -1) return dp[idx][numCarpets];

		// Black tile we can just leave it
		if (floor[idx] == '0')
			return dp[idx][numCarpets] = maxWhiteTilesCovered(floor, idx + 1, numCarpets, carpetLen);

		// White tile
		// Let's leave the current tile
		int ans = maxWhiteTilesCovered(floor, idx + 1, numCarpets, carpetLen);

		// Let's cover the current tile
		ans = max(ans, whiteTiles[min(n, idx + carpetLen) - 1] - ((idx > 0) ? whiteTiles[idx - 1] : 0) +
			maxWhiteTilesCovered(floor, min(n, idx + carpetLen), numCarpets - 1, carpetLen));

		return dp[idx][numCarpets] = ans;
	}

public:
	int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
		int n = floor.size();
		int whiteTilesCount = 0;

		dp = vector<vector<int>>(n, vector<int>(numCarpets + 1, -1));
		whiteTiles = vector<int>(n);

		for (int i = 0; i < n; ++i) {
			if (floor[i] == '1') ++whiteTilesCount;
			whiteTiles[i] = whiteTilesCount;
		}

		return whiteTilesCount - maxWhiteTilesCovered(floor, 0, numCarpets, carpetLen);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string floor;
		cin >> floor;
		int numCarpets, carpetLen;
		cin >> numCarpets >> carpetLen;

		Solution solution;
		cout << solution.minimumWhiteTiles(floor, numCarpets, carpetLen) << endl;
	}

	return 0;
}