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
	int deepestLeavesSum(TreeNode* root) {
		int ans = 0;
		queue<TreeNode*> q;

		if (root == NULL) return 0;

		q.push(root);

		while (!q.empty()) {
			int n = q.size();
			int currentSum = 0;
			for (int i = 0; i < n; ++i) {
				TreeNode* node = q.front();
				q.pop();
				currentSum += node->val;
				if (node->left != NULL) {
					q.push(node->left);
				}
				if (node->right != NULL) {
					q.push(node->right);
				}
			}
			ans = currentSum;
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}