#include<bits/stdc++.h>
using namespace std;

pair<int,int> sumMaxMin(int a[], int n, int k) {
	deque<int> maxEl, minEl;
	int maxSum = 0, minSum = 0;

	for (int i = 0; i < k; ++i) {
		while (!maxEl.empty() && a[i] >= a[maxEl.back()]) {
			maxEl.pop_back();
		}
		maxEl.push_back(i);
		while (!minEl.empty() && a[i] <= a[minEl.back()]) {
			minEl.pop_back();
		}
		minEl.push_back(i);
	}
	for (int i = k; i < n; ++i) {
		maxSum += a[maxEl.front()];
		minSum += a[minEl.front()];
		while (!maxEl.empty() && maxEl.front() <= i - k) {
			maxEl.pop_front();
		}
		while (!maxEl.empty() && a[i] >= a[maxEl.back()]) {
			maxEl.pop_back();
		}
		while (!minEl.empty() && minEl.front() <= i - k) {
			minEl.pop_front();
		}
		while (!minEl.empty() && a[i] <= a[minEl.back()]) {
			minEl.pop_back();
		}
		maxEl.push_back(i);
		minEl.push_back(i);
	}
	maxSum += a[maxEl.front()];
	minSum += a[minEl.front()];

	return { maxSum,minSum };
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		pair<int, int> ans = sumMaxMin(a, n, k);
		cout << ans.first << " " << ans.second << endl;
	}

	return 0;
}