#include<bits/stdc++.h>
using namespace std;

vector <int> max_of_subarrays(int* a, int n, int k) {
	deque<int> q;
	vector<int> res;

	for (int i = 0; i < k; ++i) {
		while (!q.empty() && a[i] >= a[q.back()]) {
			q.pop_back();
		}
		q.push_back(i);
	}

	for (int i = k; i < n; ++i) {
		res.push_back(a[q.front()]);
		while (!q.empty() && q.front() <= i - k) {
			q.pop_front();
		}
		while (!q.empty() && a[i] >= a[q.back()]) {
			q.pop_back();
		}
		q.push_back(i);
	}
	res.push_back(a[q.front()]);

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		vector<int> ans = max_of_subarrays(a, n, k);
		for (int x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}