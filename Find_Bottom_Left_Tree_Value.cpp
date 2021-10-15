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

    int ans = -1, maxLevel = -1;

    void findBottomUtil(TreeNode* root, int level) {
        if (root == NULL) return;

        if (level > maxLevel) {
            ans = root->val;
            maxLevel = level;
        }

        findBottomUtil(root->left, level + 1);
        findBottomUtil(root->right, level + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        findBottomUtil(root, 0);

        return ans;
    }
};
