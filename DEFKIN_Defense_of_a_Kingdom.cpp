#include<bits/stdc++.h>
using namespace std;

int findMaxUnguardedCells(int w, int h, vector<pair<int, int>>& pts) {
	int n = pts.size(), maxx = 0, maxy = 0;
	vector<int> x, y;

	x.push_back(0);
	y.push_back(0);
	for (int i = 0; i < n; ++i) {
		x.push_back(pts[i].first);
		y.push_back(pts[i].second);
	}
	x.push_back(w + 1);
	y.push_back(h + 1);
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	for (int i = 1; i < n + 2; ++i) {
		maxx = max(maxx, x[i] - x[i - 1] - 1);
		maxy = max(maxy, y[i] - y[i - 1] - 1);
	}

	return maxx * maxy;

}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int w, h, n;
		cin >> w >> h >> n;
		vector<pair<int, int>> pts(n);
		for (int i = 0; i < n; ++i) {
			cin >> pts[i].first >> pts[i].second;
		}

		cout << findMaxUnguardedCells(w, h, pts) << endl;
	}

	return 0;
}