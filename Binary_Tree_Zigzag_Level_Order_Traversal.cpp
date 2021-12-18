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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (root == NULL) return {};

		vector<vector<int>> res;
		queue<TreeNode*> q;
		bool left = false;

		q.push(root);

		while (!q.empty()) {
			int size = q.size();
			vector<int> currNodes;
			while (size--) {
				TreeNode* curr = q.front();
				q.pop();
				currNodes.push_back(curr->val);
				if (curr->left) q.push(curr->left);
				if (curr->right) q.push(curr->right);
			}
			if (!left) reverse(currNodes.begin(), currNodes.end());
			res.push_back(currNodes);
			left = !left;
		}

		return res;
	}
};