#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
	struct TrieNode {
		TrieNode* children[26];
		bool isEnd;

		TrieNode() {
			for (int i = 0; i < 26; ++i) {
				children[i] = NULL;
			}

			isEnd = false;
		}
	};

	TrieNode* root = new TrieNode();
	vector<string> ans;
	unordered_map<string, bool> found;
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };

	void insertIntoTrie(string word) {
		TrieNode* pCrawl = root;

		for (char& ch : word) {
			int i = ch - 'a';
			if (pCrawl->children[i] == NULL) {
				pCrawl->children[i] = new TrieNode();
			}
			pCrawl = pCrawl->children[i];
		}

		pCrawl->isEnd = true;
	}

	void findWordsUtil(vector<vector<char>>& board, string currWord, int x, int y, vector<vector<bool>>& vis, 
		TrieNode* head) {
		int m = board.size();
		int n = board[0].size();

		vis[x][y] = true;
		currWord += board[x][y];
		head = head->children[board[x][y] - 'a'];

		if (head == NULL) {
			currWord.pop_back();
			vis[x][y] = false;
			return;
		}

		if (head->isEnd) {
			if (found.find(currWord) == found.end()) {
				ans.push_back(currWord);
				found[currWord] = true;
			}
		}

		for (int i = 0; i < 4; ++i) {
			int newX = x + dx[i];
			int newY = y + dy[i];
			if (newX < m && newY < n && newX >= 0 && newY >= 0 && !vis[newX][newY]) {
				findWordsUtil(board, currWord, newX, newY, vis, head);
			}
		}

		currWord.pop_back();
		vis[x][y] = false;
	}

public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		int m = board.size();
		int n = board[0].size();
		vector<vector<bool>> vis(m, vector<bool>(n));

		for (string word : words) {
			insertIntoTrie(word);
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (root->children[board[i][j] - 'a'] == NULL) continue;
				string currWord("");
				findWordsUtil(board, currWord, i, j, vis, root);
			}
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n;
		cin >> m >> n;
		vector<vector<char>> board(m, vector<char>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> board[i][j];
			}
		}
		int size;
		cin >> size;
		vector<string> words(size);
		for (string& word : words) cin >> word;

		Solution solution;
		vector<string> ans = solution.findWords(board, words);
		for (string& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}