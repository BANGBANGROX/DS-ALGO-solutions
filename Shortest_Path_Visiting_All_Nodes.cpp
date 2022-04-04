#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int shortestPathLength(vector<vector<int>>& graph) {
		int n = graph.size();
		int fullMask = (1 << n) - 1;
		int ans = 0;
		vector<vector<bool>> visited(n, vector<bool>(fullMask + 1));
		queue<pair<int, int>> q;

		for (int i = 0; i < n; ++i) {
			visited[i][1 << i] = true;
			q.push({ i,1 << i });
		}

		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				int node = q.front().first;
				int mask = q.front().second;
				q.pop();
				for (int child : graph[node]) {
					int newMask = mask | (1 << child);
					if (newMask == fullMask) return 1 + ans;
					if (!visited[child][newMask]) {
						q.push({ child,newMask });
						visited[child][newMask] = true;
					}
				}
			}
			++ans;
		}

		return 0;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> graph(n);
		for (int i = 0; i < n; ++i) {
			int m;
			cin >> m;
			for (int j = 0; j < m; ++j) {
				int x;
				cin >> x;
				graph[i].push_back(x);
			}
		}

		Solution solution;
		cout << solution.shortestPathLength(graph) << endl;
	}

	return 0;
}