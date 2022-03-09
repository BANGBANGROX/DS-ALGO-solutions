// https://leetcode.com/problems/create-binary-tree-from-descriptions/

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		left = right = NULL;
	}
};

class Solution {
public:
	TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
		unordered_map<int, TreeNode*> valueToNode;
		unordered_map<int, bool> isParent;

		for (const vector<int>& family : descriptions) {
			int parent = family[0];
			int child = family[1];
			int relation = family[2];
			TreeNode* parentNode = new TreeNode(parent);
			TreeNode* childNode = new TreeNode(child);
			if (valueToNode.find(parent) != valueToNode.end()) {
				parentNode = valueToNode[parent];
			}
			if (valueToNode.find(child) != valueToNode.end()) {
				childNode = valueToNode[child];
			}
			if (relation == 1) parentNode->left = childNode;
			else parentNode->right = childNode;
			valueToNode[parent] = parentNode;
			valueToNode[child] = childNode;
			isParent[child] = false;
			if (isParent.find(parent) == isParent.end()) {
				isParent[parent] = true;
			}
		}

		for (const pair<int, bool>& node : isParent) {
			if (node.second) return valueToNode[node.first];
		}

		return NULL;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}