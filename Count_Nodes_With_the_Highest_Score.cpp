#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void subtreeSize(int node, int par, vector<ll>& subSize, vector<vector<int>>& tree) {
	++subSize[node];

	for (int child : tree[node]) {
		if (child != par) {
			subtreeSize(child, node, subSize, tree);
			subSize[node] += subSize[child];
		}
	}
}

void calcScore(int node, int par, vector<ll>& subSize, vector<vector<int>>& tree, vector<ll>& scores, ll anc) {
	if (par != -1) {
		scores[node] = (anc - subSize[node]);
	}

	for (int child : tree[node]) {
		if (par != child) {
			scores[node] = max((ll)1, scores[node]);
			scores[node] *= subSize[child];
			calcScore(child, node, subSize, tree, scores, max(anc, subSize[node]));
		}
	}
}

int countHighestScoreNodes(vector<int>& parents) {
	int n = parents.size(), res = 0;
	ll maxScore = 0;

	vector<vector<int>> tree(n);
	vector<ll> subSize(n), scores(n);

	for (int i = 1; i < n; ++i) {
		tree[parents[i]].push_back(i);
	}

	subtreeSize(0, -1, subSize, tree);

	calcScore(0, -1, subSize, tree, scores, 0);

	for (int i = 0; i < n; ++i) maxScore = max(maxScore, scores[i]);

	for (int i = 0; i < n; ++i) {
		if (scores[i] == maxScore) ++res;
	}

	return res;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<int> par(n);
		for (int& x : par) cin >> x;

		cout << countHighestScoreNodes(par) << endl;
	}

	return 0;
}