#include<bits/stdc++.h>
using namespace std;

string smallestNumber(int s, int d) {
	if (s == 0) {
		if (d == 1) return "0";
		return "-1";
	}

	if (s > 9 * d) return "-1";

	string ans("");
	vector<char> res(d);
	--s;

	for (int i = d - 1; i > 0; --i) {
		if (s > 9) {
			res[i] = '9';
			s -= 9;
		}
		else {
			res[i] = char(s + (int)('0'));
			s = 0;
		}
	}
	res[0] = char((s + 1) + (int)('0'));
	for (int i = 0; i < d; ++i) ans.push_back(res[i]);

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int s, d;
		cin >> s >> d;

		string ans = smallestNumber(s, d);
		cout << ans << endl;
	}

	return 0;
}