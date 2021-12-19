#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left, * right;

	TreeNode(int x) {
		val = x;
		left = right = NULL;
	}

    TreeNode() {
        val = 0;
        left = right = NULL;
    }
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "";

        string ans(""), nulls("");
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr != NULL) {
                    ans += nulls + to_string(curr->val) + ",";
                    q.push(curr->left);
                    q.push(curr->right);
                    nulls.clear();
                }
                else {
                    nulls += "null,";
                }
            }
        }
        ans.pop_back();

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        vector<string> str;
        data.push_back(',');

        stringToVector(data, str);

        queue<TreeNode**> q;

        TreeNode* root = new TreeNode;

        q.push(&root);

        int k = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode** curr = q.front();
                q.pop();
                if (k < str.size() && str[k] != "null") {
                    if ((*curr) == NULL) *curr = new TreeNode(stoi(str[k]));
                    q.push(&(*curr)->left);
                    q.push(&(*curr)->right);
                }
                ++k;
            }
        }

        return root;
    }

    void stringToVector(string s,vector<string>&vec) {
        stringstream ss(s);
        string str;

        while (getline(ss, str, ',')) vec.push_back(str);
    }
};

