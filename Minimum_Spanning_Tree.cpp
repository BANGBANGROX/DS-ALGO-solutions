#include<bits/stdc++.h>
using namespace std;

int spanningTree(int n, vector<vector<int>>* graph) {
	vector<int> key(n, INT_MAX);
	vector<bool> inMST(n);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	key[0] = 0;
	pq.push({ 0,0 });

	while (!pq.empty()) {
		 pair<int,int> top = pq.top();
		 pq.pop();
		 int val = top.first, node = top.second;
		 if (inMST[node]) continue;
		 inMST[node] = 1;
		 for (vector<int> x : graph[node]) {
			 int child = x[0], weight = x[1];
			 if (inMST[child]) continue;
			 if (key[child] > weight) {
				 key[child] = weight;
				 pq.push({ key[child],child });
			 }
		 }
	}

	int sum = 0;

	for (int i = 0; i < n; ++i) sum += key[i];

	return sum;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>>* graph = new vector<vector<int>>[n];

		for (int i = 0; i < m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			graph[u].push_back({ v,w });
			graph[v].push_back({ u,w });
		}

		cout << spanningTree(n, graph) << endl;
	}

	return 0;
}