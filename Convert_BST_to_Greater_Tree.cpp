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
	int sum = 0;

public:
	TreeNode* convertBST(TreeNode* root) {
		if (root == NULL) return NULL;

		convertBST(root->right);

		sum += root->val;
		root->val = sum;

		convertBST(root->left);

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