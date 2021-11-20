#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& heights) {
	int n = heights.size(), l = 0, r = n - 1, lMax = heights[l], rMax = heights[r], ans = 0;

	while (l < r) {
		lMax = max(lMax, heights[l]);
		rMax = max(rMax, heights[r]);
		if (lMax < rMax) {
			ans += (lMax - heights[l]);
			++l;
		}
		else {
			ans += (rMax - heights[r]);
			--r;
		}
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> heights(n);
		for (int& x : heights) cin >> x;

		cout << trap(heights) << endl;
	}

	return 0;
}
