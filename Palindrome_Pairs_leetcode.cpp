#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
	bool isPalindrome(string word) {
		int l = 0;
		int r = word.size() - 1;

		while (l < r) {
			if (word[l] != word[r]) return false;
			++l;
			--r;
		}

		return true;
	}

	string reverseString(string word) {
		reverse(word.begin(), word.end());

		return word;
	}

public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		vector<vector<int>> ans;
		unordered_map<string, int> indices;
		int n = words.size();

		for (int i = 0; i < n; ++i) {
			indices[words[i]] = i;
		}
		
		// Empty string
		if (indices.find("") != indices.end()) {
			int index = indices[""];
			for (int i = 0; i < n; ++i) {
				if (index == i || !isPalindrome(words[i])) continue;
				ans.push_back({ index,i });
				ans.push_back({ i,index });
			}
		}

		// Mirror strings
		for (int i = 0; i < n; ++i) {
			string reverseWord = reverseString(words[i]);
			if (indices.find(reverseWord) != indices.end()) {
				int index = indices[reverseWord];
				if (index != i) ans.push_back({ i, index });
			}
		}

		// Cutting cases
		for (int i = 0; i < n; ++i) {
			string word = words[i];
			int m = word.size();
			for (int cut = 1; cut < m; ++cut) {
				string left = word.substr(0, cut);
				string right = word.substr(cut);
				if (isPalindrome(left)) {
					reverse(right.begin(), right.end());
					if (indices.find(right) != indices.end()) {
						int index = indices[right];
						ans.push_back({ index,i });
					}
				}
				if (isPalindrome(right)) {
					reverse(left.begin(), left.end());
					if (indices.find(left) != indices.end()) {
						int index = indices[left];
						ans.push_back({ i,index });
					}
				}
			}
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}