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
	TreeNode* previousNode;
	TreeNode* firstNode;
	TreeNode* secondNode;

	void recoverTreeUtil(TreeNode* root) {
		if (root == NULL) return;

		recoverTreeUtil(root->left);

		if (firstNode == NULL && root->val < previousNode->val) firstNode = previousNode;
		else if (firstNode != NULL && root->val < previousNode->val) secondNode = root;

		previousNode = root;

		recoverTreeUtil(root->right);
	}

public:
	void recoverTree(TreeNode* root) {
		previousNode = new TreeNode(INT_MIN);

		firstNode = secondNode = NULL;

		recoverTreeUtil(root);

		assert(firstNode != NULL && secondNode != NULL);

		swap(firstNode->val, secondNode->val);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}