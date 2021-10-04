#include<bits/stdc++.h>
using namespace std;

bool subArrayExists(int a[], int n) {
	map<int, bool> m;
	vector<int> pref(n);
	pref[0] = a[0];
	m[pref[0]] = true;

	for (int i = 1; i < n; ++i) {
		pref[i] = pref[i - 1] + a[i];
		if (m[pref[i]] || pref[i] == 0) return true;
		m[pref[i]] = true;
	}

	return false;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];
		
		cout << subArrayExists(a, n) << endl;
	}

	return 0;
}