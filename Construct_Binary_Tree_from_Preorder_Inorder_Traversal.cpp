#include<bits/stdc++.h>
using namespace std;

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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:

    int findIndex(vector<int>& inorder, int val) {
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == val) return i;
        }

        return -1;
    }

    TreeNode* buildTreeUtil(int start, int end, int* index, vector<int>& preorder, vector<int>& inorder) {
        if (start > end) return NULL;

        TreeNode* root = new TreeNode(preorder[*index]);
        *index = *index + 1;

        int ind = findIndex(inorder, root->val);

        root->left = buildTreeUtil(start, ind - 1, index, preorder, inorder);
        root->right = buildTreeUtil(ind + 1, end, index, preorder, inorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0, n = inorder.size();

        return buildTreeUtil(0, n - 1, &index, preorder, inorder);
    }

    void postOrder(TreeNode* root) {
        if (root == NULL) return;

        postOrder(root->left);
        postOrder(root->right);

        cout << root->val << " ";
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> inorder(n), preorder(n);
        for (int& x : preorder) cin >> x;
        for (int& x : inorder) cin >> x;

        Solution obj;
        TreeNode* root = obj.buildTree(preorder, inorder);
        obj.postOrder(root);
        cout << endl;
    }

    return 0;
}