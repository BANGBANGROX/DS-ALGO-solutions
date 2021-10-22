#include<bits/stdc++.h>
using namespace std;

bool areNumbersAscending(string s) {
	int n = s.size();
	vector<int> nums;

	for (int i = 0; i < n; ++i) {
		if (isdigit(s[i])) {
			string temp("");
			while (i < n && isdigit(s[i])) {
				temp += s[i];
				++i;
			}
			nums.push_back(stoi(temp));
		}
	}

	int size = nums.size();

	for (int i = 1; i < size; ++i) {
		if (nums[i] <= nums[i - 1]) return false;
	}

	return true;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		getline(cin, s);

		cout << areNumbersAscending(s) << endl;
	}

	return 0;
}