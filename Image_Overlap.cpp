#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
		int n = img1.size();
		int ans = 0;
		vector<int> a;
		vector<int> b;
		unordered_map<int, int> count;

		for (int i = 0; i < n * n; ++i) {
			int x = i / n;
			int y = i % n;
			int val = x * 100 + y;
			if (img1[x][y] == 1) a.push_back(val);
			if (img2[x][y] == 1) b.push_back(val);
		}

		for (int x : a) {
			for (int y : b) {
				++count[x - y];
			}
		}

		for (pair<int, int> x : count) {
			ans = max(ans, x.second);
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> img1(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> img1[i][j];
			}
		}
		vector<vector<int>> img2(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> img2[i][j];
			}
		}

		Solution solution;
		cout << solution.largestOverlap(img1, img2) << endl;
	}

	return 0;
}