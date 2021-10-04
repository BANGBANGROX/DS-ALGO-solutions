#include<bits/stdc++.h>
using namespace std;

vector<int> outgoing, incoming, vis, wts;
int ans = 0;

int findEndpoint(int node) {
	vis[node] = 1;

	if (outgoing[node] == 0) return node;

	ans = min(ans, wts[node]);

	return findEndpoint(outgoing[node]);
}

vector<vector<int>> solve(int n, int p, vector<int>& a, vector<int>& b, vector<int>& d) {
	vector<vector<int>> arrangement;

	outgoing.resize(n + 1);
	incoming.resize(n + 1);
	wts.resize(n + 1);
	vis.resize(n + 1);

	for (int i = 0; i < p; ++i) {
		outgoing[a[i]] = b[i];
		incoming[b[i]] = a[i];
		wts[a[i]] = d[i];
	}

	for (int i = 1; i <= n; ++i) {
		if (!vis[i] && !incoming[i]) {
			ans = INT_MAX;
			int endPoint = findEndpoint(i);
			if (i == endPoint) continue;
			arrangement.push_back({ i,endPoint,ans });
		}
	}

	return arrangement;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, p;
		cin >> n >> p;
		vector<int> a(p), b(p), d(p);

		for (int& x : a) cin >> x;
		for (int& x : b) cin >> x;
		for (int& x : d) cin >> x;

		vector<vector<int>> finalArrangements = solve(n, p, a, b, d);
		cout << finalArrangements.size() << endl;
		for (vector<int> x : finalArrangements) {
			for (int y : x) cout << y << " ";
			cout << endl;
		}
	}

	return 0;
}