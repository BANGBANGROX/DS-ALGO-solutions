// https://leetcode.com/problems/longest-substring-of-one-repeating-character/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	struct Node {
		int maxSize;
		int prefixSize;
		int suffixSize;
		int size;
		char maxChar;
		char prefixChar;
		char suffixChar;

		Node(char c) {
			maxSize = prefixSize = suffixSize = size = 1;
			prefixChar = suffixChar = maxChar = c;
		}
	};

	struct SegTree {
		vector<Node> tree;
		int n;

		SegTree(int n) {
			tree = vector<Node>(2 * n, Node('A'));
			this->n = n;
		}

		Node mergeNodes(Node a, Node b) {
			Node res = Node('A');

			res.size = a.size + b.size;

			if (a.prefixSize != a.size || a.prefixChar != b.prefixChar) {
				res.prefixSize = a.prefixSize;
				res.prefixChar = a.prefixChar;
			}
			else {
				res.prefixSize = a.prefixSize + b.prefixSize;
				res.prefixChar = a.prefixChar;
			}

			if (b.suffixSize != b.size || b.suffixChar != a.suffixChar) {
				res.suffixSize = b.suffixSize;
				res.suffixChar = b.suffixChar;
			}
			else {
				res.suffixSize = a.suffixSize + b.suffixSize;
				res.suffixChar = b.suffixChar;
			}

			int val1 = a.maxSize;
			int val2 = b.maxSize;
			int val3 = (a.suffixChar == b.prefixChar) ? a.suffixSize + b.prefixSize : 0;

			if (val1 > val2) {
				if (val1 > val3) {
					res.maxSize = val1;
					res.maxChar = a.maxChar;
				}
				else {
					res.maxSize = val3;
					res.maxChar = a.suffixChar;
				}
			}
			else {
				if (val2 > val3) {
					res.maxSize = val2;
					res.maxChar = b.maxChar;
				}
				else {
					res.maxSize = val3;
					res.maxChar = a.suffixChar;
				}
			}

			return res;
		}

		void updateTree(int pos, Node val) {
			for (tree[pos += n] = val; pos /= 2;) {
				tree[pos] = mergeNodes(tree[2 * pos], tree[2 * pos + 1]);
			}
		}

		Node queryTree(int start, int end) {
			Node left = Node('A');
			Node right = Node('A');

			for (start += n, end += n; start < end; start /= 2, end /= 2) {
				if (start % 2 == 1) {
					left = mergeNodes(left, tree[start]);
					++start;
				}
				if (end % 2 == 1) {
					--end;
					right = mergeNodes(tree[end], right);
				}
			}

			return mergeNodes(left, right);
		}
	};

public:
	vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
		int n = s.size();
		int k = queryCharacters.size();
		vector<int> ans;
		SegTree tree(s.size());

		for (int i = 0; i < n; ++i) {
			tree.updateTree(i, Node(s[i]));
		}

		for (int i = 0; i < k; ++i) {
			tree.updateTree(queryIndices[i], Node(queryCharacters[i]));
			ans.push_back(tree.queryTree(0, n).maxSize);
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s, queryCharacters;
		cin >> s >> queryCharacters;
		int k = queryCharacters.size();
		vector<int> queryIndices(k);
		for (int& x : queryIndices) cin >> x;

		Solution solution;
		vector<int> ans = solution.longestRepeating(s, queryCharacters, queryIndices);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}