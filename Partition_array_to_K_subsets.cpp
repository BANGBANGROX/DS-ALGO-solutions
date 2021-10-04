#include<bits/stdc++.h>
using namespace std;

bool isKPartitionPossibleUtil(vector<int>& a, vector<int>& subsetSum, vector<bool>taken, int subset, int k, int n,
	int currIdx, int limitIdx) {
	if (subsetSum[currIdx] == subset) {
		if (currIdx == k - 2) return true;
		return isKPartitionPossibleUtil(a, subsetSum, taken, subset, k, n, currIdx + 1, n - 1);
	}

	for (int i = limitIdx; i > -1; --i) {
		if (taken[i]) continue;
		int temp = subsetSum[currIdx] + a[i];
		if (temp <= subset) {
			subsetSum[currIdx] += a[i];
			taken[i] = true;
			bool nxt = isKPartitionPossibleUtil(a, subsetSum, taken, subset, k, n, currIdx, i - 1);
			subsetSum[currIdx] -= a[i];
			taken[i] = false;
			if (nxt) return true;
		}
	}

	return false;
}

bool isKPartitionPossible(int arr[], int n, int k) {
	if (k < 2) return true;
	if (n < k) return false;
	int sum = 0;
	for (int i = 0; i < n; ++i) sum += arr[i];
	if (sum % k != 0) return false;

	int subset = sum / k;
	vector<int> a(n), subsetSum(n);
	vector<bool> taken(n);
	for (int i = 0; i < n; ++i) a[i] = arr[i];
	subsetSum[0] = a[n - 1];
	taken[n - 1] = true;

	return isKPartitionPossibleUtil(a, subsetSum, taken, subset, k, n, 0, n - 1);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		int *a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		cout << isKPartitionPossible(a, n, k) << endl;
	}

	return 0;
}
