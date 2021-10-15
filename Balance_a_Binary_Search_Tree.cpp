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
public:

    vector<TreeNode*> inorder;

    void inorderTraversal(TreeNode* root) {
        if (root == NULL) return;

        inorderTraversal(root->left);

        inorder.push_back(root);

        inorderTraversal(root->right);
    }

    TreeNode* balanceBST(int start, int end) {
        if (start > end) return NULL;

        int mid = (start + end) / 2;
        TreeNode* root = inorder[mid];

        root->left = balanceBST(start, mid - 1);
        root->right = balanceBST(mid + 1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorderTraversal(root);

        int n = inorder.size();

        TreeNode* balanceRoot = balanceBST(0, n - 1);

        return balanceRoot;
    }
};