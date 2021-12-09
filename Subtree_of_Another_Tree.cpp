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

bool isSubtreeUtil(TreeNode* root, TreeNode* subRoot) {
    if (subRoot == NULL) return root == NULL;

    if (root == NULL) return false;

    if (root->val == subRoot->val) {
        return isSubtreeUtil(root->left, subRoot->left) && isSubtreeUtil(root->right, subRoot->right);
    }

    return false;
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (subRoot == NULL) return true;

    if (root == NULL) return false;

    if (root->val == subRoot->val) {
        if (isSubtreeUtil(root, subRoot)) return true;
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
