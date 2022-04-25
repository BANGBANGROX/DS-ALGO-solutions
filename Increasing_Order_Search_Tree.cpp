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
	TreeNode* ans = new TreeNode(0);
	TreeNode* ansTail = ans;

	void generateBST(TreeNode* root) {
		if (root == NULL) return;

		generateBST(root->left);

		ansTail->right = new TreeNode(root->val);
		ansTail = ansTail->right;

		generateBST(root->right);
	}

public:
	TreeNode* increasingBST(TreeNode* root) {
		generateBST(root);

		return ans->right;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}