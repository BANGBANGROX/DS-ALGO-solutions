#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
    int diameterOfBinaryTreeUtil(TreeNode* root, int* height) {
        int leftHeight = 0;
        int rightHeight = 0;

        if (root == NULL) {
            *height = 0;
            return 0;
        }

        int leftDiameter = diameterOfBinaryTreeUtil(root->left, &leftHeight);
        int rightDiameter = diameterOfBinaryTreeUtil(root->right, &rightHeight);

        *height = max(leftHeight, rightHeight) + 1;

        return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int height = 0;

        return diameterOfBinaryTreeUtil(root, &height);
    }
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}