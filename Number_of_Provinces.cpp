#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& vis) {
	vis[node] = true;

	for (int i = 0; i < isConnected[node].size(); ++i) {
		if (!vis[i] && isConnected[node][i] == 1) dfs(i, isConnected, vis);
	}
}

int findCircleNum(vector<vector<int>>& isConnected) {
	int provinces = 0, n = isConnected.size();
	vector<bool> vis(n);

	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			++provinces;
			dfs(i, isConnected, vis);
		}
	}

	return provinces;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> isConnected(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> isConnected[i][j];
			}
		}

		cout << findCircleNum(isConnected) << endl;
	}

	return 0;
}
