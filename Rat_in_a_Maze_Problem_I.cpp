#include<bits/stdc++.h>
using namespace std;

vector<string> ans;

bool isSafe(int i, int j, vector<vector<int>>& m, int n) {
	return i >= 0 && i < n && j >= 0 && j < n && m[i][j] == 1;
}

void path(int i, int j, string currPath, vector<vector<int>>& m, vector<vector<bool>>& vis, int n) {
	if (i == n - 1 && j == n - 1) {
		ans.push_back(currPath);
		return;
	}
	if (vis[i][j] || !m[i][j]) return;
	vis[i][j] = 1;
	if (isSafe(i, j + 1, m, n)) {
		currPath.push_back('R');
		path(i, j + 1, currPath, m, vis, n);
		currPath.pop_back();
	}
	if (isSafe(i, j - 1, m, n)) {
		currPath.push_back('L');
		path(i, j - 1, currPath, m, vis, n);
		currPath.pop_back();
	}
	if (isSafe(i + 1, j, m, n)) {
		currPath.push_back('D');
		path(i + 1, j, currPath, m, vis, n);
		currPath.pop_back();
	}
	if (isSafe(i - 1, j, m, n)) {
		currPath.push_back('U');
		path(i - 1, j, currPath, m, vis, n);
		currPath.pop_back();
	}
	vis[i][j] = 0;
}

vector<string> findPath(vector<vector<int>>& m, int n) {
	vector<vector<bool>> vis(n, vector<bool>(n));
	string currPath("");

	path(0, 0, currPath, m, vis, n);

	sort(ans.begin(), ans.end());

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> m(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> m[i][j];
			}
		}

		vector<string> res = findPath(m, n);
		for (string s : res) cout << s << " ";
	}

	return 0;
}