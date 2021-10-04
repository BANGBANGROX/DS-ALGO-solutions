#include<bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
	string prev = "1";
	--n;

	while (n--) {
		string newString("");
		int len = prev.size();
		for (int i = 0; i < len; ++i) {
			int count = 1;
			while (i < len - 1 && prev[i] == prev[i + 1]) {
				++count;
				++i;
			}
			string temp = to_string(count);
			temp += prev[i];
			newString += temp;
		}
		prev = newString;
	}

	return prev;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		cout << countAndSay(n) << endl;
	}

	return 0;
}