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

	TreeNode* bstFromPreorderUtil(vector<int>& preorder, int* index, int key, int low, int high, int n) {
		if (*index >= n) return NULL;

		if (key > low && key < high) {
			TreeNode* node = new TreeNode(key);
			*index = *index + 1;
			if (*index < n) node->left = bstFromPreorderUtil(preorder, index, preorder[*index], low, key, n);
			if (*index < n) node->right = bstFromPreorderUtil(preorder, index, preorder[*index], key, high, n);
			return node;
		}

		return NULL;
	}

	TreeNode* bstFromPreorder(vector<int>& preorder) {
		int n = preorder.size();
		int low = INT_MIN;
		int high = INT_MAX;
		int index = 0;

		return bstFromPreorderUtil(preorder, &index, preorder[0], low, high, n);
	}

	void inorderTraversal(TreeNode* root) {
		if (root == NULL) return;

		inorderTraversal(root->left);

		cout << root->val << " ";

		inorderTraversal(root->right);
	}
};


int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<int> preorder(n);

		for (int& x : preorder) cin >> x;

		Solution obj;
        TreeNode* root = obj.bstFromPreorder(preorder);
		obj.inorderTraversal(root);
		cout << endl;
	}
}