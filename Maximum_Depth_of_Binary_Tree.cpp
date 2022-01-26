#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() {
		val = 0;
		left = right = NULL;
	}

	TreeNode(int x) {
		val = x;
		left = right = NULL;
	}

	TreeNode(int x, TreeNode* l, TreeNode* r) {
		val = x;
		left = l;
		right = r;
	}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;

		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}