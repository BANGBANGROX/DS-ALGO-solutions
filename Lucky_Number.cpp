#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isLucky(char ch) {
	return ch >= '3';
}

int luckyNumbers(string oNum, string lNum) {
	int n = oNum.size(), len = lNum.size();
	vector<int> freq1(10, 0), freq2(10);

	if (len > n) return 0;

	int l = 0, r = len - 1;
	ll res = 0;

	for (int i = l; i <= r; ++i) {
		++freq1[oNum[i] - '0'];
		++freq2[lNum[i] - '0'];
	}

	while (l < n && r < n) {
		bool isLucky = true;
		for (int i = 3; i < 10; ++i) {
			if (freq1[i] == 0) continue;
			if (freq1[i] != freq2[i]) {
				isLucky = false;
				break;
			}
		}
		if (isLucky) ++res;
		--freq1[oNum[l] - '0'];
		++l;
		++r;
		if (r < n) ++freq1[oNum[r] - '0'];
	}

	return res;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s1, s2;
		cin >> s1 >> s2;

		cout << luckyNumbers(s1, s2) << endl;
	}

	return 0;
}