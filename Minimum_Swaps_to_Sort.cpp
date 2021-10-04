#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>& nums) {
	int n = nums.size();
	vector<pair<int, int>> arrPos(n);

	for (int i = 0; i < n; ++i) {
		arrPos[i].first = nums[i];
		arrPos[i].second = i;
	}
	sort(arrPos.begin(), arrPos.end());
	vector<bool> vis(n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (vis[i] || arrPos[i].second == i) continue;
		int j = i, cycle_size = 0;
		while (!vis[j]) {
			vis[j] = 1;
			++cycle_size;
			j = arrPos[j].second;
		}
		if (cycle_size != 0) ans += (cycle_size - 1);
	}

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		cout << minSwaps(a) << endl;
	}

	return 0;
}