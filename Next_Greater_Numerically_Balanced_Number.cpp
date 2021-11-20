#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

void nextBeautifulNumberUtil(int currLen, int len, int num, unordered_map<int, int>& count, vector<int>& nums) {
	if (currLen == len) {
		bool isBalanced = true;
		for (pair<int, int> x : count) {
			int digit = x.first, freq = x.second;
			if (freq > 0 && freq != digit) {
				isBalanced = false;
				break;
			}
		}
		if (isBalanced) nums.push_back(num);
		return;
	}

	for (int dig = 1; dig <= len; ++dig) {
		if (count[dig] >= dig) continue;
		if (count[dig] + (len - currLen) < dig) continue;
		++count[dig];
		nextBeautifulNumberUtil(currLen + 1, len, num * 10 + dig, count, nums);
		--count[dig];
	}
}

int nextBeautifulNumber(int n) {

	if (n == 0) return 1;

	int minLen = log10(n) + 1;

	for (int len = minLen; len <= minLen + 1; ++len) {
		vector<int> allNums;
		unordered_map<int, int> count;
		nextBeautifulNumberUtil(0, len, 0, count, allNums);
		for (int num : allNums) {
			if (n < num) return num;
		}
	}

	return -1;

}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		cout << nextBeautifulNumber(n) << endl;
	}

	return 0;
}