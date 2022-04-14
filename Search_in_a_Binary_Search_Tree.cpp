#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		left = right = NULL;
	}
};

class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == NULL || root->val == val) return root;

		if (val < root->val) return searchBST(root->left, val);

		return searchBST(root->right, val);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}