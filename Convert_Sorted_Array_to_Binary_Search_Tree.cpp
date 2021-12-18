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

    TreeNode* constructTree(int start, int end, vector<int>& nums) {
        if (start > end) return NULL;

        int mid = (start + end) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = constructTree(start, mid - 1, nums);
        root->right = constructTree(mid + 1, end, nums);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();

        return constructTree(0, n - 1, nums);
    }
};