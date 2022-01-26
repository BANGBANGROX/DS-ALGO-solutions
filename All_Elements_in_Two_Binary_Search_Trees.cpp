#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode() {
		val = 0;
		left = right = NULL;
	}

	TreeNode(int x) {
		val = x;
		left = right = NULL;
	}

	TreeNode(int x, TreeNode* l, TreeNode* r) {
		val = x;
		left = l;
		right = r;
	}
};

class Solution {
	void computeInorder(TreeNode* root, vector<int>& inorder) {
		if (root == NULL) return;

		computeInorder(root->left, inorder);

		inorder.push_back(root->val);

		computeInorder(root->right, inorder);
	}

	vector<int> merge(vector<int>& a, vector<int>& b) {
		int m = a.size();
		int n = b.size();
		int i = 0;
		int j = 0;
		vector<int> res;

		while (i < m && j < n) {
			if (a[i] < b[j]) {
				res.push_back(a[i]);
				++i;
			}
			else {
				res.push_back(b[j]);
				++j;
			}
		}

		while (i < m) {
			res.push_back(a[i]);
			++i;
		}

		while (j < n) {
			res.push_back(b[j]);
			++j;
			
		}

		return res;
	}
public:
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> inorder1;
		vector<int> inorder2;

		computeInorder(root1, inorder1);
		computeInorder(root2, inorder2);

		return merge(inorder1, inorder2);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}