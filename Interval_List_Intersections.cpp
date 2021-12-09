#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
	int n = firstList.size(), m = secondList.size(), i = 0, j = 0;
	vector<vector<int>> ans;

	while (i < n && j < m) {
		int l = max(firstList[i][0], secondList[j][0]);
		int r = min(firstList[i][1], secondList[j][1]);
		if (r - l >= 0) ans.push_back({ l,r });
		if (firstList[i][1] > secondList[j][1]) ++j;
		else ++i;
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n;
		vector<vector<int>> firstList;
		for (int i = 0; i < n; ++i) {
			int a, b;
			cin >> a >> b;
			firstList.push_back({ a,b });
		}
		cin >> m;
		vector<vector<int>> secondList;
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			secondList.push_back({ a,b });
		}

		vector<vector<int>> ans = intervalIntersection(firstList, secondList);
		for (vector<int> x : ans) cout << x[0] << " " << x[1] << endl;
		cout << endl;
	}

	return 0;
}