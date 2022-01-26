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
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL) return root;

		invertTree(root->left);
		invertTree(root->right);

		swap(root->left, root->right);

		return root;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}