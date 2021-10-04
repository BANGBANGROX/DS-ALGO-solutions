#include<bits/stdc++.h>
using namespace std;

int findClosestPowerof2(int n) {
	int cnt = 0;

	while (n) {
		n /= 2;
		if (n) ++cnt;
	}

	return cnt;
}

int countSetBitsUtil(int n) {
	if (n == 0) return 0;

	int x = findClosestPowerof2(n);

	return x * pow(2, x - 1) + (n - pow(2, x) + 1) + countSetBitsUtil(n - pow(2, x));
}

int countSetBits(int n) {
	return countSetBitsUtil(n);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << countSetBits(n) << endl;
	}

	return 0;
}