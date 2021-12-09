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

int widthOfBinaryTree(TreeNode* root) {
    if (root == NULL) return 0;

    int maxWidth = 0;
    queue<pair<TreeNode*, int>> q;

    q.push({ root,0 });

    while (!q.empty()) {
        int size = q.size(), left = -1, right = -1, min = q.front().second;
        for (int i = 0; i < size; ++i) {
            TreeNode* curr = q.front().first;
            int currVal = q.front().second - min;
            q.pop();
            if (i == 0) {
                left = currVal;
            }
            if (i == size - 1) {
                right = currVal;
            }
            if (curr->left) q.push({ curr->left,2 * currVal + 1 });
            if (curr->right) q.push({ curr->right,2 * currVal + 2 });
        }
        maxWidth = max(right - left + 1, maxWidth);
    }

    return maxWidth;
}
