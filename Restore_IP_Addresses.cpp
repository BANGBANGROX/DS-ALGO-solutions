#include<bits/stdc++.h>
using namespace std;

void restoreIpAddressesUtil(int index, int seg, string& s, vector<string>& res, string segment[]) {
	if (index == s.size() && seg == 4) {
		string ans("");
		for (int i = 0; i < 3; i++) {
			ans += segment[i];
			ans += '.';
		}
		ans += segment[3];
		res.push_back(ans);
		return;
	}

	if (index == s.size() || seg == 4) return;

	for (int len = 1; len <= 4 && index + len <= s.size(); ++len) {
		string segmentString = s.substr(index, len);
		int segmentNumber = stoi(segmentString);
		if (segmentNumber > 255 || (len > 1 && segmentString[0] == '0')) return;
		segment[seg] = segmentString;
		restoreIpAddressesUtil(index + len, seg + 1, s, res, segment);
	}
}

vector<string> restoreIpAddresses(string s) {
	vector<string> res;
	string segment[4];

	restoreIpAddressesUtil(0, 0, s, res, segment);

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		vector<string> res = restoreIpAddresses(s);

		for (string s : res) cout << s << " ";
		cout << endl;
	}

	return 0;
}