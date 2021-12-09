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

int ans;

int findTiltUtil(TreeNode* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) return root->val;

    int leftSum = findTiltUtil(root->left), rightSum = findTiltUtil(root->right);

    ans += abs(leftSum - rightSum);

    return root->val + leftSum + rightSum;
}

int findTilt(TreeNode* root) {
    ans = 0;

    findTiltUtil(root);

    return ans;
}

