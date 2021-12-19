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

class BSTIterator {
public:
    vector<int> inorder;
    int ind, n;

    void inorderTraversal(TreeNode* root) {
        if (!root) return;

        inorderTraversal(root->left);

        inorder.push_back(root->val);

        inorderTraversal(root->right);
    }

    BSTIterator(TreeNode* root) {
        inorderTraversal(root);

        ind = -1;
        n = inorder.size();
    }

    int next() {
        return inorder[++ind];
    }

    bool hasNext() {
        return ind < n - 1;
    }
};
