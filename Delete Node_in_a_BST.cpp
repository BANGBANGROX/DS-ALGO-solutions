#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) {
		val = x;
		left = right = NULL;
	}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

	TreeNode* inorderSucc(TreeNode* node) {
		if (node == NULL) return node;

		while (node->left != NULL) {
			node = node->left;
		}

		return node;
	}

	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == NULL) return root;

		if (root->val == key) {
			if (root->left == NULL) {
				TreeNode* temp = root->right;
				delete root;
				return temp;
			}
		    if (root->right == NULL) {
				TreeNode* temp = root->left;
				delete root;
				return temp;
			}
			TreeNode* inSucc = inorderSucc(root->right);
			root->val = inSucc->val;
			root->right = deleteNode(root->right, inSucc->val);
		}

		if (root->val < key) {
			root->right = deleteNode(root->right, key);
		}

		if (root->val > key) {
			root->left = deleteNode(root->left, key);
		}

		return root;
	}
};