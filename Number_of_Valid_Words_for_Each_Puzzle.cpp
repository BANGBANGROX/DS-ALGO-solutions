#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int generateMask(string& word) {
	int mask = 0;

	for (char ch : word) {
		mask |= (1 << (ch - 'a'));
	}

	return mask;
}

vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
	vector<int> res;
	unordered_map<int, int> freq;

	for (string word : words) {
		++freq[generateMask(word)];
	}

	for (string puzzle : puzzles) {
		int mask = generateMask(puzzle), submask = mask, curr = 0, first = (1 << (puzzle[0] - 'a'));
		while (submask) {
			if (submask & first) curr += freq[submask];
			submask = (submask - 1) & mask;
		}
		res.push_back(curr);
	}

	return res;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n;
		vector<string> words(n);
		for (string& x : words) cin >> x;
		cin >> m;
		vector<string> puzzles(m);
		for (string& x : puzzles) cin >> x;

		vector<int> ans = findNumOfValidWords(words, puzzles);
		for (int x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}