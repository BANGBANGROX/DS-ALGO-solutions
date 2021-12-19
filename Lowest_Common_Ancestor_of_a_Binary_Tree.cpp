#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left, * right;
	TreeNode(int x) {
		val = x;
		left = right = NULL;
	}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || root->val == p->val || root->val == q->val) return root;

		TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
		TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

		if (leftLCA != NULL && rightLCA != NULL) return root;

		if (leftLCA) return leftLCA;

		return rightLCA;
	}
};
