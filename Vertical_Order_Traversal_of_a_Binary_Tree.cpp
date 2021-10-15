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

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if (root == NULL) return {};

        map<int, vector<pair<int, int>>> m;
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> res;

        q.push({ root,{0,0} });

        while (!q.empty()) {
            TreeNode* curr = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            m[col].push_back({ row,curr->val });
            if (curr->left != NULL) q.push({ curr->left,{row + 1,col - 1} });
            if (curr->right != NULL) q.push({ curr->right,{row + 1,col + 1} });
        }

        for (pair<int, vector<pair<int, int>>> x : m) {
            sort(x.second.begin(), x.second.end());
            vector<int> temp;
            for (pair<int, int> y : x.second) {
                temp.push_back(y.second);
            }
            res.push_back(temp);
        }

        return res;
    }
};