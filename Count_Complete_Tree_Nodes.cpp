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
	int countNodes(TreeNode* root) {
		if (root == NULL) return 0;

		TreeNode* left = root->left;
		TreeNode* right = root->right;
		int height = 0;

		while (left != NULL && right != NULL) {
			++height;
			left = left->left;
			right = right->right;
		}
		
		return left == NULL && right == NULL ? (1 << height) - 1 :
			1 + countNodes(root->left) + countNodes(root->right);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}