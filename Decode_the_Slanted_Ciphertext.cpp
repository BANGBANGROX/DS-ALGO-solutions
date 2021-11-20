#include<bits/stdc++.h>
using namespace std;

string decodeCiphertext(string encodedText, int rows) {
	int n = encodedText.size(), cols = n / rows;
	string ans("");

	for (int i = 0; i < cols; ++i) {
		for (int j = i; j < n; j += (cols + 1)) {
			ans += encodedText[j];
		}
	}

	while (!ans.empty() && isspace(ans.back())) ans.pop_back();

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int rows;
		cin >> rows;
		string encodedText;
		getline(cin, encodedText);

		string ans = decodeCiphertext(encodedText, rows);
		cout << ans << endl;
	}

	return 0;
}