#include<bits/stdc++.h>
using namespace std;

vector<int> findAmplifierOrder(int n, int a[]) {
	int noOfOnes = 0;
	vector<int> res;

	sort(a, a + n, greater<int>());
	for (int i = 0; i < n; ++i) {
		if (a[i] == 1) ++noOfOnes;
	}

	for (int i = 0; i < noOfOnes; ++i) {
		res.push_back(1);
	}
	if ((n - noOfOnes) == 2 && a[0] == 3 && a[1] == 2) {
		res.push_back(2);
		res.push_back(3);
	}
	else {
		for (int i = 0; i < (n - noOfOnes); ++i) {
			res.push_back(a[i]);
		}
	}

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		vector<int> ans = findAmplifierOrder(n, a);
		for (int x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}