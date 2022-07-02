#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
		int largetRowGap = 0;
		int largestColGap = 0;
		const int mod = 1e9 + 7;

		horizontalCuts.push_back(0);
		verticalCuts.push_back(0);
		horizontalCuts.push_back(h);
		verticalCuts.push_back(w);

		sort(horizontalCuts.begin(), horizontalCuts.end());
		sort(verticalCuts.begin(), verticalCuts.end());

		for (int i = 1; i < (int)horizontalCuts.size(); ++i) {
			largetRowGap = max(largetRowGap, horizontalCuts[i] - horizontalCuts[i - 1]);
		}

		for (int i = 1; i < (int)verticalCuts.size(); ++i) {
			largestColGap = max(largestColGap, verticalCuts[i] - verticalCuts[i - 1]);
		}

		return ((long)largetRowGap * largestColGap) % mod;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int h, w;
		cin >> h >> w;
		int m;
		cin >> m;
		vector<int> horizontalCuts(m);
		for (int& x : horizontalCuts) {
			cin >> x;
		}
		int n;
		cin >> n;
		vector<int> verticalCuts(n);
		for (int& x : verticalCuts) {
			cin >> x;
		}

		Solution solution;
		cout << solution.maxArea(h, w, horizontalCuts, verticalCuts) << endl;
	}

	return 0;
}