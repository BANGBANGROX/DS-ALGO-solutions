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

    int res = 0;

    void pathSumUtil(TreeNode* root, int k, vector<int>& path) {
        if (root == NULL) return;

        path.push_back(root->val);

        pathSumUtil(root->left, k, path);
        pathSumUtil(root->right, k, path);

        int sum = 0;

        for (int i = path.size() - 1; i > -1; --i) {
            sum += path[i];
            if (sum == k) ++res;
        }

        path.pop_back();
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;

        pathSumUtil(root, targetSum, path);

        return res;
    }
};

