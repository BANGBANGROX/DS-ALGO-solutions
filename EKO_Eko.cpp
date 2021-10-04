#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& heights, int n, int req, int ht) {
	int res = 0;

	for (int i = 0; i < n; ++i) {
		if (heights[i] < ht) break;
		res += (heights[i] - ht);
		if (res >= req) return true;
	}

	return false;
}

int findMaxHeight(vector<int>& heights, int n, int req) {
	sort(heights.begin(), heights.end(), greater<int>());
	int low = 0, high = heights[0], ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (check(heights, n, req, mid)) {
			low = mid + 1;
			ans = mid;
		}
		else high = mid - 1;
	}

	return ans;
}

int main() {
	int n, req;
	cin >> n >> req;
	vector<int> heights(n);
	for (int& x : heights) cin >> x;

	cout << findMaxHeight(heights, n, req) << endl;

	return 0;
}