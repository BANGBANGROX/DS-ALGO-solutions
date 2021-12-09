#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<string> mirrorNums1{ "" }, mirrorNums2{ "0" };

ll toBase10(string& num, int k) {
	ll res = 0;

	for (int i = 0; i < num.size(); ++i) {
		res = res * k + ((ll)num[i] - '0');
	}

	return res;
}

bool isMirror(ll num) {
	string numS = to_string(num);
	int l = 0, r = numS.size() - 1;

	while (l < r) {
		if (numS[l] != numS[r]) return false;
		++l;
		--r;
	}

	return true;
}

ll dfs(int dig, int n, int k) {
	vector<string> mirror;
	ll res = 0;

	if (n == 0) return 0;

	for (int i = 0; n > 0 && i < k; ++i) {
		for (int j = 0; n > 0 && j < mirrorNums1.size(); ++j) {
			mirror.push_back(to_string(i) + mirrorNums1[j] + to_string(i));
			ll n10 = toBase10(mirror.back(), k);
			if (i != 0 && isMirror(n10)) {
				res += n10;
				--n;
			}
		}
	}

	swap(mirrorNums1, mirrorNums2);
	swap(mirrorNums2, mirror);

	return res + dfs(dig + 1, n, k);
}

ll kMirror(int k, int n) {
	ll res = 0;

	for (int i = 1; n > 0 && i < k; ++i) {
		mirrorNums2.push_back(to_string(i));
		res += i;
		--n;
	}

	return res + dfs(2, n, k);
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, k;
		cin >> k >> n;
		
		cout << kMirror(k, n) << endl;

		mirrorNums1 = { "" };
		mirrorNums2 = { "0" };
	}

	return 0;
}
