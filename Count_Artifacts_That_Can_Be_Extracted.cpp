// https://leetcode.com/problems/count-artifacts-that-can-be-extracted/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
		vector<vector<bool>> visited(n, vector<bool>(n));
		int ans = 0;

		for (const vector<int>& cell : dig) {
			visited[cell[0]][cell[1]] = true;
		}

		for (const vector<int>& artifact : artifacts) {
			int x1 = artifact[0];
			int y1 = artifact[1];
			int x2 = artifact[2];
			int y2 = artifact[3];
			bool found = true;
			for (int x = x1; x <= x2; ++x) {
				for (int y = y1; y <= y2; ++y) {
					if (!visited[x][y]) {
						found = false;
						break;
					}
				}
			}
			if (found) ++ans;
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		int m;
		cin >> m;
		vector<vector<int>> artifacts(m, vector<int>(m));
		for (int i = 0; i < m; ++i) {
			for (int& x : artifacts[i]) cin >> x;
		}
		int o;
		cin >> o;
		vector<vector<int>> dig(o, vector<int>(2));
		for (int i = 0; i < o; ++i) {
			cin >> dig[i][0] >> dig[i][1];
		}

		Solution solution;
		cout << solution.digArtifacts(n, artifacts, dig) << endl;
	}

	return 0;
}