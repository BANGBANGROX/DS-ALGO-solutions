#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;

	return gcd(b, a % b);
}

int maxPoints(vector<vector<int>>& points) {
	map<pair<int, int>, int> mp;
	int n = points.size(), ans = 1;
	
	for (int i = 0; i < n; ++i) {
		int x1 = points[i][0], y1 = points[i][1];
		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			int x2 = points[j][0], y2 = points[j][1];
			int num = (y2 - y1), den = (x2 - x1);
			if (num == 0) ++mp[{0, 1}];
			else if (den == 0) ++mp[{1, 0}];
			else {
				int g = gcd(num, den);
				num /= g;
				den /= g;
				++mp[{num, den}];
			}
		}
		for (const pair<pair<int, int>, int> &x : mp) {
			ans = max(ans, x.second + 1);
		}
		mp.clear();
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> points(n);
		for (int i = 0; i < n; ++i) {
			int a, b;
			cin >> a >> b;
			points[i] = { a,b };
		}

		cout << maxPoints(points) << endl;
	}

	return 0;
}
