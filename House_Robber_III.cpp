#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

unordered_map<TreeNode*, int> dp;

int rob(TreeNode* root) {
    if (root == NULL) return 0;

    if (dp.find(root) != dp.end()) return dp[root];

    int ansIncluding = 0, ansExcluding = 0;

    if (root->left == NULL && root->right == NULL) return dp[root] = root->val;

    if (root->left == NULL) {
        ansIncluding = rob(root->right->left) + rob(root->right->right) + root->val;
        ansExcluding = rob(root->right);
        return dp[root] = max(ansIncluding, ansExcluding);
    }

    if (root->right == NULL) {
        ansIncluding = rob(root->left->left) + rob(root->left->right) + root->val;
        ansExcluding = rob(root->left);
        return dp[root] = max(ansIncluding, ansExcluding);
    }

    ansIncluding = rob(root->left->left) + rob(root->left->right) + rob(root->right->left) +
        rob(root->right->right) + root->val;
    ansExcluding = rob(root->left) + rob(root->right);

    return dp[root] = max(ansIncluding, ansExcluding);
}
