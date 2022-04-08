#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<int>> tree;
	vector<int> count;
	vector<int> ans;
	int n = 0;

	void postorder(int node, int parent) {
		++count[node];

		for (int child : tree[node]) {
			if (child != parent) {
				postorder(child, node);
				count[node] += count[child];
				ans[node] += (ans[child] + count[child]);
			}
		}
	}

	void preorder(int node, int parent) {
		for (int child : tree[node]) {
			if (child != parent) {
				ans[child] = ans[node] - 2 * count[child] + n;
				preorder(child, node);
			}
		}
	}

public:
	vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
		tree = vector<vector<int>>(n);
		count = ans = vector<int>(n);
		this->n = n;

		for (const vector<int>& edge : edges) {
			tree[edge[0]].push_back(edge[1]);
		}

		postorder(0, -1);
		preorder(0, -1);

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n;
		vector<vector<int>> edges(n - 1, vector<int>(2));
		for (int i = 1; i < n; ++i) {
			cin >> edges[i][0] >> edges[i][1];
		}

		Solution solution;
		vector<int> ans = solution.sumOfDistancesInTree(n, edges);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}