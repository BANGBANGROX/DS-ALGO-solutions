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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;

		if (root == NULL) return ans;

		queue<TreeNode*> q;

		q.push(root);

		while (!q.empty()) {
			vector<int> currrentLevel;
			int n = q.size();
			for (int i = 0; i < n; ++i) {
				TreeNode* currNode = q.front();
				q.pop();
				currrentLevel.push_back(currNode->val);
				if (currNode->left != NULL) {
					q.push(currNode->left);
				}
				if (currNode->right != NULL) {
					q.push(currNode->right);
				}
			}
			if (currrentLevel.empty()) continue;
			ans.push_back(currrentLevel);
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