#include<bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int a[], int n) {
	set<int> s;
	for (int i = 0; i < n; ++i) {
		s.insert(a[i]);
	}
	int ans = 1;

	for (int i = 0; i < n; ++i) {
		if (s.find(a[i] - 1) == s.end()) {
			int j = a[i];
			while (s.find(j) != s.end()) {
				++j;
			}
			ans = max(ans, j - a[i]);
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
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		cout << findLongestConseqSubseq(a, n) << endl;
	}

	return 0;
}