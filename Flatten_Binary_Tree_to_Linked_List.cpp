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
	void flatten(TreeNode* root) {
		if (root == NULL) return;

		flatten(root->left);

		TreeNode* temp = root->right;
		root->right = root->left;
		root->left = NULL;

		while (root->right != NULL) {
			root = root->right;
		}

		root->right = temp;

		flatten(root->right);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}