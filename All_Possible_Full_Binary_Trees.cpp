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
 
 class Solution {
 public:
     vector<TreeNode*> allPossibleFBT(int n) {
         if ((n & 1) == 0) return {};

         if (n == 1) return { new TreeNode(0) };

         vector<vector<TreeNode*>> dp(n + 1);

         dp[1].push_back(new TreeNode(0));

         for (int cnt = 3; cnt <= n; cnt += 2) {
             for (int i = 1; i < cnt - 1; i += 2) {
                 int j = cnt - i - 1;
                 for (TreeNode* left : dp[i]) {
                     for (TreeNode* right : dp[j]) {
                         TreeNode* root = new TreeNode(0, left, right);
                         dp[cnt].push_back(root);
                     }
                 }
             }
         }

         return dp[n];
     }

     void printTree(TreeNode* root) {
         if (root == nullptr) return;

         cout << root->val << " ";

         printTree(root->left);
         printTree(root->right);
     }
 };

 int main() {
     int T;
     cin >> T;

     while (T--) {
         int n;
         cin >> n;

         Solution solution;
         vector<TreeNode*> answer = solution.allPossibleFBT(n);
         for (TreeNode* root : answer) {
             solution.printTree(root);
             cout << endl;
         }
         cout << endl;
     }

     return 0;
 }