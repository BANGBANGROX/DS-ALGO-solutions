#include<bits/stdc++.h>
using namespace std;

int rangeBitwiseAnd(int left, int right) {
	// here we use a simple concept 
	// whenever we have a range of length > 1 the corresponding bit will be 0
	// so we compute the result as [....lsb] lsb = 0 if left != right and lsb = 1 if left == right
	// once we compute lsb we shift left and right by 1 in right to compute next bit
	// we stop when left == right i.e. the bit is 1 and the no is [left 0 0 0 ... 0]

	if (!left || !right) return 0;

	int shifts = 0;

	while (left != right) {
		++shifts;
		left = (left >> 1);
		right = (right >> 1);
	}

	return (left << shifts);
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int left, right;
		cin >> left >> right;

		cout << rangeBitwiseAnd(left, right) << endl;
	}

	return 0;
}
