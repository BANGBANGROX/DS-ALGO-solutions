#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
	int n = height.size(), l = 0, r = n - 1, ans = 0;

	while (l < r) {
		ans = max(min(height[l], height[r]) * (r - l), ans);
		if (height[l] < height[r]) ++l;
		else --r;
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> height(n);
		for (int i = 0; i < n; ++i) cin >> height[i];

		cout << maxArea(height) << endl;
	}

	return 0;
}