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
	int ans;

	int maxPathSumUtil(TreeNode* root) {
		if (root == NULL) return 0;

		int leftSum = maxPathSumUtil(root->left);
		int rightSum = maxPathSumUtil(root->right);

		// Let's consider 3 cases

		// 1. We take the "root" node to be in the path of the max sum path.
		int inPath = max(max(leftSum, rightSum) + root->val, root->val);

		// 2. Now we can also take "root" node to be the root of the max sum path.
		int rootPath = leftSum + rightSum + root->val;

		// 3. It can also be possible that the "root" node is not related to the max sum path.
		// In this case we need not compute anything, but we will make ans as max of the resuls 
		// obtained above inPath and rootPath.
		ans = max(ans, max(inPath, rootPath));

		// Since we can only use inPath to extend the max sum path, we return it.
		return inPath;
	}

public:
	int maxPathSum(TreeNode* root) {
		ans = INT_MIN;

		maxPathSumUtil(root);

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