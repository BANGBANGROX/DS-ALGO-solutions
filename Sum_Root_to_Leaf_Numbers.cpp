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
 
void sumNumbersUtil(TreeNode* root, string& currNum, int* ans) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        currNum += to_string(root->val);
        *ans = *ans + stoi(currNum);
        currNum.pop_back();
        return;
    }

    currNum += to_string(root->val);

    sumNumbersUtil(root->left, currNum, ans);
    sumNumbersUtil(root->right, currNum, ans);

    currNum.pop_back();
}

int sumNumbers(TreeNode* root) {
    int ans = 0;
    string currNum("");

    sumNumbersUtil(root, currNum, &ans);

    return ans;
}