#include<bits/stdc++.h>
using namespace std;

int find(vector<int>& parent, int node) {
	if (parent[node] == -1) return node;

	return parent[node] = find(parent, parent[node]);
}

vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
	vector<int> parent(n, -1);
	vector<bool> ans;

	for (vector<int> req : requests) {
		int u = req[0], v = req[1];
		u = find(parent, u);
		v = find(parent, v);
		bool areFriends = (u == v);
		if (!areFriends) {
			areFriends = true;
			for (int i = 0; areFriends == true && i < restrictions.size(); ++i) {
				int a = restrictions[i][0], b = restrictions[i][1];
				a = find(parent, a);
				b = find(parent, b);
				areFriends = (a != u || b != v) && (a != v || b != u);
			}
			if (areFriends) parent[v] = u;
		}
		ans.push_back(areFriends);
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, m, q;
		cin >> n >> m;
		vector<vector<int>> restrictions, requests;
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			restrictions.push_back({ a,b });
		}
		cin >> q;
		for (int i = 0; i < q; ++i) {
			int a, b;
			cin >> a >> b;
			requests.push_back({ a,b });
		}

		vector<bool> ans = friendRequests(n, restrictions, requests);
		for (bool a : ans) cout << a << " ";
		cout << endl;
	}

	return 0;
}