#include<bits/stdc++.h>
using namespace std;

int multiply(int num, vector<int>& res, int res_size) {
	int carry = 0;
	
	for (int i = 0; i < res_size; ++i) {
		int value = res[i] * num + carry;
		res[i] = value % 10;
		carry = value / 10;
	}
	while (carry) {
		res[res_size] = carry % 10;
		carry /= 10;
		++res_size;
	}

	return res_size;
}

vector<int> factorial(int n) {
	const int maxSize = 1e6 + 5;
	int res_size = 1;
	vector<int> res(maxSize);
	res[0] = 1;

	for (int i = 2; i <= n; ++i) {
		res_size = multiply(i, res, res_size);
	}
    vector<int> ans(res_size);
	for (int i = res_size - 1; i > -1; --i) ans[res_size - i - 1] = res[i];

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		vector<int> ans = factorial(n);
		for (int dig : ans) cout << dig;
		cout << endl;
	}

	return 0;
}