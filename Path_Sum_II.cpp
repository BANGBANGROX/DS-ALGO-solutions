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
	vector<vector<int>> ans;

	void generatePath(TreeNode* root, int targetSum, vector<int>& curr) {
		if (targetSum == 0 && root == NULL) {
			ans.push_back(curr);
			return;
		}

		if (root == NULL) {
			return;
		}

		if (root->left == NULL && root->right == NULL) {
			if (root->val == targetSum) {
				curr.push_back(root->val);
				ans.push_back(curr);
				curr.pop_back();
			}
			return;
		}

		if (root->val > targetSum) return;

		curr.push_back(root->val);

		generatePath(root->left, targetSum - root->val, curr);
		generatePath(root->right, targetSum - root->val, curr);

		curr.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<int> curr;
		generatePath(root, targetSum, curr);

		return ans;
	}
};
