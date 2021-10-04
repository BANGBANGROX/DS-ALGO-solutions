#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> graph[N];
int vis[N], recStack[N];

bool isCycle(int node) {
	vis[node] = 1;
	recStack[node] = 1;

	for (int child : graph[node]) {
		if (!vis[child] && isCycle(child)) {
			return true;
		}
		if (recStack[child]) return true;
	}

	recStack[node] = 0;

	return false;
}

bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	for (int i = 0; i < n; ++i) {
		graph[i].clear();
		vis[i] = 0;
		recStack[i] = 0;
	}
	for (pair<int, int>x : prerequisites) {
		graph[x.second].push_back(x.first);
	}

	for (int i = 0; i < n; ++i) {
		if (!vis[i] && isCycle(i)) return false;
	}

	return true;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, p;
		cin >> n >> p;
		vector<pair<int, int>> pre;
		for (int i = 0; i < n; ++i) {
			int a, b;
			cin >> a >> b;
			pre[i].first = a;
			pre[i].second = b;
		}

		cout << isPossible(n, pre) << endl;
	}

	return 0;
}