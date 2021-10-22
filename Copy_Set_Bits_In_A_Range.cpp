#include<bits/stdc++.h>
using namespace std;

int copyBits(int a, int b, int l, int r) {
	vector<int> bitsa(32), bitsb(32);
	int res = 0, msb = 31;
	--l;
	--r;

	for (int i = 0; i < 32; ++i) {
		if ((1 << i) & a) bitsa[i] = 1;
		if ((1 << i) & b) bitsb[i] = 1;
	}

	for (int i = 31; i > -1; --i) {
		int nI = msb - i;
		if (nI >= l && nI <= r && bitsa[nI] == 1) bitsb[nI] = 1;
	}

	for (int i = 0; i < 32; ++i) {
		res += bitsb[i] * (1 << i);
	}

	return res;
}

int main() {
	int a, b, l, r;
	cin >> a >> b >> l >> r;

	int res = copyBits(a, b, l, r);
	cout << res << endl;

	return 0;
}