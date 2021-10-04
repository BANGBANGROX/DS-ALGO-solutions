#include<bits/stdc++.h>
using namespace std;

int lower(int a[], int n, int key) {
	int low = 0, high = n - 1, ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid] <= key) {
			ans = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}

	return ans;
}

pair<int,int> findSumAndNumber(int strengths[], int pref[], int currStr, int n) {
	int index = lower(strengths, n, currStr);
	if (index == -1) return { 0,0 };
	return { index + 1,pref[index] };
}

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i) cin >> a[i];

	sort(a, a + n);
	int* pref = new int[n];
	pref[0] = a[0];
	for (int i = 1; i < n; ++i) {
		pref[i] = pref[i - 1] + a[i];
	}

	int q;
	cin >> q;

	while (q--) {
		int strength;
		cin >> strength;

		pair<int, int> res = findSumAndNumber(a, pref, strength, n);
		cout << res.first << " " << res.second << endl;
	}

	return 0;
}