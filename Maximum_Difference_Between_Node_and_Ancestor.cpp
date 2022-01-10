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
private:
	void maxAncestorDiffUtil(TreeNode* root, int maxVal, int minVal, int* maxDiff) {
		if (root == NULL) return;

		if (maxVal == INT_MIN && minVal == INT_MAX) {
			maxAncestorDiffUtil(root->left, max(maxVal, root->val), min(minVal, root->val), maxDiff);
			maxAncestorDiffUtil(root->right, max(maxVal, root->val), min(minVal, root->val), maxDiff);
			
			return;
		}

		*maxDiff = max(*maxDiff, max(abs(maxVal - root->val), abs(minVal - root->val)));

		maxAncestorDiffUtil(root->left, max(maxVal, root->val), min(minVal, root->val), maxDiff);
		maxAncestorDiffUtil(root->right, max(maxVal, root->val), min(minVal, root->val), maxDiff);
	}

public:
	int maxAncestorDiff(TreeNode* root) {
		int maxDiff = 0;

		maxAncestorDiffUtil(root, INT_MIN, INT_MAX, &maxDiff);

		return maxDiff;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}