#include<bits/stdc++.h>
using namespace std;

void combination(int ind, int sum, vector<int>& a, vector<int>& res, vector<vector<int>>& ans, int n) {
	if (sum == 0) {
		ans.push_back(res);
		return;
	}
	if (ind == n || sum < 0) {
		return;
	}
	// Choose element
	res.push_back(a[ind]);
	combination(ind, sum - a[ind], a, res, ans, n);
	res.pop_back();
	// Not choosing element
	combination(ind + 1, sum, a, res, ans, n);
}

vector<vector<int>> combinationSum(vector<int>& a, int k) {
	vector<vector<int>> ans;
	vector<int> res;
	vector<bool> occurence(100);
	vector<int> newa;
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		if (!occurence[a[i]]) {
			newa.push_back(a[i]);
			occurence[a[i]] = 1;
		}
	}
	sort(newa.begin(), newa.end());

	combination(0, k, newa, res, ans, newa.size());

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		vector<vector<int>> ans = combinationSum(a, k);
		for (int i = 0; i < ans.size(); ++i) {
			for (int x : ans[i]) cout << x << " ";
			cout << endl;
		}
	}

	return 0;
}