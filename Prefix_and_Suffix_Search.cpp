#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

struct TrieNode {
	unordered_map<char, TrieNode*> children;
	int maxIndex;

	TrieNode() {
		maxIndex = -1;
	}
};

class WordFilter {
	TrieNode* root;
public:
    WordFilter(vector<string>& words) {
		root = new TrieNode();
		int n = words.size();

		for (int i = 0; i < n; ++i) {
			string word = words[i];
			string newWord = word + "#" + word;
			for (int j = 0; j < (int)word.size(); ++j) {
				TrieNode* current = root;
				for (int k = j; k < (int)newWord.size(); ++k) {
					char c = newWord[k];
					if (current->children.find(c) == current->children.end()) {
						current->children[c] = new TrieNode();
					}
					current = current->children[c];
					current->maxIndex = i;
				}
			}
		}
    }

    int f(string prefix, string suffix) {
		TrieNode* current = root;
		string searchWord = suffix + "#" + prefix;

		for (int i = 0; i < (int)searchWord.size(); ++i) {
			char c = searchWord[i];
			if (current->children.find(c) == current->children.end()) return -1;
			current = current->children[c];
		}

		return current->maxIndex;
    }
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}