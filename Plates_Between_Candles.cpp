#include<bits/stdc++.h>
using namespace std;

int find(vector<int>& pos, int key) {
	int l = 0, r = pos.size() - 1, ans = -1;

	while (l <= r) {
		int mid = l + ((r - l) >> 2);
		if (pos[mid] > key) r = mid - 1;
		else {
			ans = mid;
			l = mid + 1;
		}
	}

	return ans;
}

vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
	int len = s.size();
	vector<int> ans, pref(len), pos;

	for (int i = 0; i < len; ++i) {
		pref[i] = s[i] == '*' ? 1 : 0;
		if (i > 0) pref[i] += pref[i - 1];
		if (s[i] == '|') pos.push_back(i);
	}

	for (vector<int> x : queries) {
		int l = x[0], r = x[1];
		auto it1 = lower_bound(pos.begin(), pos.end(), l);
		int ind = find(pos, r);
		if (it1 == pos.end() || ind == -1 || pos[ind] < l) {
			ans.push_back(0);
			continue;
		}
		int ind1 = it1 - pos.begin();
		l = pos[ind1];
		r = pos[ind];
		int res = l == 0 ? pref[r] : pref[r] - pref[l - 1];
		ans.push_back(res);
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		int n;
		cin >> s >> n;

		vector<vector<int>> queries;

		for (int i = 0; i < n; ++i) {
			int a, b;
			cin >> a >> b;
			queries.push_back({ a,b });
		}

		vector<int> ans = platesBetweenCandles(s, queries);

		for (int x : ans) cout << x << endl;
	}

	return 0;
}
