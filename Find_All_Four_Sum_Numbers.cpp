#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& arr, int k) {
	int n = arr.size();
	sort(arr.begin(), arr.end());
	vector<vector<int>> res;
	map<vector<int>, int> m;

	for (int i = 0; i < n - 3; ++i) {
		if (i > 0 and arr[i] == arr[i - 1]) continue;
		for (int j = i + 1; j < n - 2; ++j) {
			if (j > i + 1 and arr[j] == arr[j - 1]) continue;
			int sum = arr[i] + arr[j];
			int l = j + 1, r = n - 1;
			while (l < r) {
				int currSum = arr[l] + arr[r];
				if (currSum == (k - sum)) {
					vector<int> currentFour;
					currentFour.push_back(arr[i]);
					currentFour.push_back(arr[j]);
					currentFour.push_back(arr[l]);
					currentFour.push_back(arr[r]);
					if (m.find(currentFour) == m.end()) {
						res.push_back(currentFour);
						m[currentFour] = 1;
					}
					++l;
					--r;
				}
				else if (currSum < (k - sum)) ++l;
				else --r;
			}
		}
	}

	return res;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int& x : a) cin >> x;

		vector<vector<int>> ans = fourSum(a, k);

		for (int i = 0; i < ans.size(); ++i) {
			for (int x : ans[i]) cout << x << " ";
			cout << endl;
		}
	}

	return 0;
}
