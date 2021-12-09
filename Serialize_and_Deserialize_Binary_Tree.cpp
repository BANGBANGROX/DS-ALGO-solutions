#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    void generate(TreeNode* root, int index, string* str) {
        if (!root) {
            if (index < str->size()) str[index] = "null";
            return;
        }

        str[index] = to_string(root->val);

        generate(root->left, 2 * index + 1, str);
        generate(root->right, 2 * index + 2, str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "";

        int n = 0;
        queue<TreeNode*> q;

        q.push(root);
         
        while (!q.empty()) {
            int size = q.size();
            ++n;
            while (size--) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }

        n = (1 << n) - 1;

        string* str = new string[n];

        generate(root, 0, str);

        string res("");

        for (int i = 0; i < n; ++i) {
            res = (res + str[i] + " ");
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;

        if (data.empty()) return root;

        root = new TreeNode(stoi(data[0]));
    }
};
