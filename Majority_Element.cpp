#include<bits/stdc++.h>
using namespace std;

int findCandidate(int a[], int n) {
	int majIndex = 0, cnt = 1;

	for (int i = 1; i < n; ++i) {
		if (a[majIndex] == a[i]) {
			++cnt;
		}
		else {
			--cnt;
		}
		if (cnt == 0) {
			majIndex = i;
			cnt = 1;
		}
	}

	return a[majIndex];
}

int isMajority(int a[], int n, int val) {
	int cnt = 0;
	
	for (int i = 0; i < n; ++i) {
		if (a[i] == val) {
			++cnt;
		}
	}

	return cnt > n / 2;
}

int majorityElement(int a[], int n) {
	int candidate = findCandidate(a, n);
	if (isMajority(a, n, candidate)) return candidate;
	return -1;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		cout << majorityElement(a, n) << endl;
	}

	return 0;
}